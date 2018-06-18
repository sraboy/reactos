/*
 * PROJECT: Send To Context Menu extension
 * 
 * Copyright 2018 Steven Lavoie <steven.lavoiejr@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "precomp.h"
WINE_DEFAULT_DEBUG_CHANNEL(shell);

HRESULT SHGetUIObjectFromFullPIDL(LPCITEMIDLIST pidl, HWND hwnd, REFIID riid, void **ppv);

//
// Used to enumerate all drop targets in the user's SendTo folder.
// Adapted from COpenWithList (see COpenWithMenu.cpp)
//
class CSendToList
{
    public:
        struct SSendTgt
        {
            WCHAR wszFilename[MAX_PATH];
            WCHAR wszClsid[45]; //Reg value format: `CLSID\{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}`
            HICON hIcon;
        };

        CSendToList();
        ~CSendToList();

        BOOL Load();
        
        inline SSendTgt *GetList() { return m_Targets; }
        inline UINT GetCount() { return m_TgtCount; }

    private:
        SSendTgt *m_Targets;
        UINT m_TgtCount;

        SSendTgt * AddDropTarget(LPCWSTR pwszFilename);
};

CSendToList::CSendToList() : m_Targets(NULL), m_TgtCount(0) {}
CSendToList::~CSendToList()
{
    // for (UINT i = 0; i < m_TgtCount; ++i)
    //     if (m_Targets[i].hIcon)
    //         DestroyIcon(m_Targets[i].hIcon);

    HeapFree(GetProcessHeap(), 0, m_Targets);
}

BOOL CSendToList::Load()
{
    WIN32_FIND_DATA data;
    WCHAR send_to_path[MAX_PATH];

    if (FAILED(SHGetFolderPathW(NULL, CSIDL_SENDTO, NULL, 0, send_to_path)))
    {
        ERR("SHGetFolderPathW failed\n");
        return FALSE;
    }

    //
    // I'm unsure if there are/could be drop targets here without extensions
    //
    if(FAILED(StringCchCatW(send_to_path, MAX_PATH, L"\\*")))
    {
        ERR("StringCchCatW failed\n");
        return FALSE;
    }

    DbgPrint("Got SendTo path: %S\n", send_to_path);
    HANDLE hFind = FindFirstFileW((LPCWSTR)&send_to_path, &data);

    BOOL found = FALSE;
    if ( hFind != INVALID_HANDLE_VALUE ) {
        do {
            if(!_tcscmp(data.cFileName, _T(".")) || !_tcscmp(data.cFileName, _T("..")))
            {
                continue;
            }
            found = true;
            DbgPrint("Found drop target: %S\n", data.cFileName);
            AddDropTarget(data.cFileName);
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
    return found;
}

CSendToList::SSendTgt *CSendToList::AddDropTarget(LPCWSTR pwszFilename)
{
    SSendTgt * pTgt;
    if (!m_Targets)
        m_Targets = static_cast<SSendTgt *>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(SSendTgt)));
    else
        m_Targets = static_cast<SSendTgt *>(HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, m_Targets, (m_TgtCount + 1)*sizeof(m_Targets[0])));
    if (!m_Targets)
    {
        ERR("Allocation failed\n");
        return NULL;
    }

    pTgt = &m_Targets[m_TgtCount++];
    wcscpy(pTgt->wszFilename, pwszFilename);

    LPCWSTR pwszExt = PathFindExtensionW(pwszFilename);
    if (!pwszExt[0])
    {
        ERR("No file extension\n");
        return pTgt;
    }

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_CLASSES_ROOT, pwszExt, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
    {
        ERR("File extension %S not registered\n", pwszExt);
        return pTgt;
    }

    DWORD dwSize = sizeof(pTgt->wszClsid);
    LONG err;
    if ( (err = RegQueryValueExW(hKey, NULL, NULL, NULL, (LPBYTE)pTgt->wszClsid, &dwSize)) != ERROR_SUCCESS)
    {
        ERR("Failed to retrieve default value w/ error: %l\n", err);
    }

    DbgPrint("Found CLSID string: %S\n", pTgt->wszClsid);
    RegCloseKey(hKey);
    return pTgt;
}

CSendToMenu::CSendToMenu() : m_idCmdFirst(0), m_idCmdLast(0), m_pdtobj(NULL), m_tgtList(NULL) {}

CSendToMenu::~CSendToMenu()
{
    TRACE("Destroying CSendToMenu(%p)\n", this);

    if (m_hSubMenu)
    {
        INT Count, Index;
        MENUITEMINFOW mii;

        /* get item count */
        Count = GetMenuItemCount(m_hSubMenu);
        if (Count == -1)
            return;

        /* setup menuitem info */
        ZeroMemory(&mii, sizeof(mii));
        mii.cbSize = sizeof(mii);
        mii.fMask = MIIM_DATA | MIIM_FTYPE | MIIM_CHECKMARKS;

        for(Index = 0; Index < Count; Index++)
        {
            if (GetMenuItemInfoW(m_hSubMenu, Index, TRUE, &mii))
            {
                if (mii.hbmpChecked)
                    DeleteObject(mii.hbmpChecked);
            }
        }
    }

    if (m_tgtList) {
        delete m_tgtList;
    }

    if(m_filePaths)
    {
        for(UINT i = 0; i < m_pathCount; i++)
        {
            HeapFree(GetProcessHeap(), 0, m_filePaths[i]);
        }
        HeapFree(GetProcessHeap(), 0, m_filePaths);
    }
}

VOID CSendToMenu::AddSendToItem(LPCWSTR pwszName)
{
    MENUITEMINFOW mii;

    ZeroMemory(&mii, sizeof(mii));
    mii.cbSize = sizeof(mii);
    mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;// | MIIM_DATA;
    mii.fType = MFT_STRING;
    mii.fState = MFS_ENABLED;
    mii.wID = m_idCmdLast;
    mii.dwTypeData = (LPWSTR)pwszName;
    mii.cch = wcslen(mii.dwTypeData);
    //mii.dwItemData = ***;

    // FIXME: Icon doesn't show on context menu, though nothing fails here
    // mii.dwItemData = 
    // HICON hIcon = LoadIcon(shell32_hInstance, MAKEINTRESOURCE(IDI_SHELL_DESKTOP));
    // if (hIcon)
    // {
    //     mii.fMask |= MIIM_CHECKMARKS;
    //     mii.hbmpChecked = mii.hbmpUnchecked = IconToBitmap(hIcon);
    // }

    if (InsertMenuItemW(m_hSubMenu, 1, TRUE, &mii))
        m_idCmdLast++;
}

// FIXME: Duplicated from COpenWithMenu
HBITMAP CSendToMenu::IconToBitmap(HICON hIcon)
{
    DbgPrint("Converting icon to bitmap\n");
    HDC hdc, hdcScr;
    HBITMAP hbm, hbmOld;
    RECT rc;

    hdcScr = GetDC(NULL);
    hdc = CreateCompatibleDC(hdcScr);
    SetRect(&rc, 0, 0, GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
    hbm = CreateCompatibleBitmap(hdcScr, rc.right, rc.bottom);
    ReleaseDC(NULL, hdcScr);

    hbmOld = (HBITMAP)SelectObject(hdc, hbm);
    FillRect(hdc, &rc, (HBRUSH)(COLOR_MENU + 1));
    if (!DrawIconEx(hdc, 0, 0, hIcon, rc.right, rc.bottom, 0, NULL, DI_NORMAL))
        ERR("DrawIcon failed: %x\n", GetLastError());
    SelectObject(hdc, hbmOld);

    DeleteDC(hdc);
    return hbm;
}

HRESULT WINAPI CSendToMenu::QueryContextMenu(
    HMENU hMenu,
    UINT indexMenu,
    UINT idCmdFirst,
    UINT idCmdLast,
    UINT uFlags)
{
    DbgPrint("QueryContextMenu\n");
    // FIXME: Check SendTo folder
    DbgPrint("hMenu %p indexMenu %u idFirst %u idLast %u uFlags %u\n", hMenu, indexMenu, idCmdFirst, idCmdLast, uFlags);

    WCHAR wszName[100];
    if (!LoadStringW(shell32_hInstance, IDS_SENDTO_MENU, wszName, _countof(wszName)))
    {
        ERR("Failed to load string: IDS_SENDTO_MENU\n");
        return E_FAIL;
    }

    /* Init first cmd id and submenu */
    m_idCmdFirst = m_idCmdLast = idCmdFirst;
    
    if(!m_tgtList->Load())
    {
        ERR("No targets\n");
        return E_FAIL;
    }

    m_hSubMenu = CreatePopupMenu();

    for(UINT i = 0; i < m_tgtList->GetCount(); i++)
    {
        auto tgt = m_tgtList->GetList() + i;
        DbgPrint("Adding %S to Send To menu\n", tgt->wszFilename);
        AddSendToItem(tgt->wszFilename);
    }

    // m_hSubMenu = CreatePopupMenu();
    // LPCWSTR deskstr = L"Desktop (create shortcut)";
    // AddSendToItem(deskstr);
    // LPCWSTR zipstr = L"Compressed Folder";
    // AddSendToItem(zipstr);
    
    /* Insert "Send To" menu */
    MENUITEMINFOW mii;
    ZeroMemory(&mii, sizeof(mii));
    mii.cbSize = sizeof(mii);
    mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE | MIIM_SUBMENU;
    mii.wID = indexMenu;
    mii.hSubMenu = m_hSubMenu;
    mii.fType = MFT_STRING;
    mii.dwTypeData = (LPWSTR)wszName;
    mii.cch = wcslen(wszName);
    mii.fState = MFS_ENABLED;
    
    DbgPrint("Inserting main menu\n");
    if (!InsertMenuItemW(hMenu, indexMenu + 1, TRUE, &mii))
        return E_FAIL;

    return MAKE_HRESULT(SEVERITY_SUCCESS, 0, m_idCmdLast - m_idCmdFirst + 1);
}



// CLSID CLSID_ZipFolder = { 0x888DCA60, 0xFC0A, 0x11CF, { 0x8F, 0x0F, 0x00, 0xC0, 0x4F, 0xD7, 0xD0, 0x62 } };

// #ifdef __cplusplus
// #   define IID_PPV_ARG(Itype, ppType) IID_##Itype, reinterpret_cast<void**>((static_cast<Itype**>(ppType)))
// #   define IID_NULL_PPV_ARG(Itype, ppType) IID_##Itype, NULL, reinterpret_cast<void**>((static_cast<Itype**>(ppType)))
// #else
// #   define IID_PPV_ARG(Itype, ppType) IID_##Itype, (void**)(ppType)
// #   define IID_NULL_PPV_ARG(Itype, ppType) IID_##Itype, NULL, (void**)(ppType)
// #endif
extern HRESULT CDesktopDropTarget_CreateInstance(REFIID riid, LPVOID * ppvOut);

HRESULT WINAPI CSendToMenu::InvokeCommand(LPCMINVOKECOMMANDINFO lpici)
{
    DbgPrint("This %p idFirst %u idLast %u idCmd %u\n", this, m_idCmdFirst, m_idCmdLast, m_idCmdFirst + LOWORD(lpici->lpVerb));
    
    HRESULT hr = E_FAIL;

    for(UINT i = 0; i < m_pathCount; i++)
    {
        IDataObject *pdtobj = NULL;
        LPITEMIDLIST pidlItem = NULL;

        hr = SHILCreateFromPathW(m_filePaths[i], &pidlItem, NULL);
        if (FAILED(hr))
        {
            ERR("SHILCreateFromPathW failed\n");
            return E_FAIL;
        }
        
        hr = SHGetUIObjectFromFullPIDL(pidlItem, NULL, IID_IDataObject, (LPVOID*)&pdtobj);
        CComPtr<IDropTarget> pdt;
        
        if (SUCCEEDED(hr))
        {
            DWORD grfKeyState;
            if (GetAsyncKeyState(VK_SHIFT) < 0)         // move
                grfKeyState = MK_SHIFT | MK_LBUTTON;
            else if (GetAsyncKeyState(VK_CONTROL) < 0)  // copy
                grfKeyState = MK_CONTROL | MK_LBUTTON;
            else if (GetAsyncKeyState(VK_MENU) < 0)     // shortcut
                grfKeyState = MK_ALT | MK_LBUTTON;
            else
                grfKeyState = MK_LBUTTON;

            DWORD dwEffect = DROPEFFECT_COPY;
            
            DbgPrint("HACK: Sending to desktop\n");
            //hr = CRecyclerDropTarget_CreateInstance(IID_PPV_ARG(IDropTarget, &pdt));
            hr = CDesktopDropTarget_CreateInstance(IID_PPV_ARG(IDropTarget, &pdt));
            if (FAILED_UNEXPECTEDLY(hr))
            {
                ERR("CDesktopDropTarget_CreateInstance failed\n");
                hr = E_FAIL;
            } 
            else
            {
                POINTL pt = { 0, 0 };
                hr = SHSimulateDrop(pdt, pdtobj, grfKeyState, &pt, &dwEffect);
                if (FAILED(hr)) 
                {
                    ERR("SHSimulateDrop failed\n");
                    hr = E_FAIL;
                }
            }

            pdt->Release();
        }
        else
        {
            ERR("SHGetUIObjectFromFullPIDL failed\n");
        }
        pdtobj->Release();
        ILFree(pidlItem);
    }

    // hr = SHILCreateFromPathW(m_wszPath, &pidlItem, NULL);
    // if (FAILED(hr))
    // {
    //     ERR("SHILCreateFromPathW failed\n");
    //     return E_FAIL;
    // }
    
    // hr = SHGetUIObjectFromFullPIDL(pidlItem, lpici->hwnd, IID_IDataObject, (LPVOID*)&pdtobj);
    // CComPtr<IDropTarget> pdt;
    
    // if (SUCCEEDED(hr))
    // {
    //     DWORD grfKeyState;
    //     if (GetAsyncKeyState(VK_SHIFT) < 0)         // move
    //         grfKeyState = MK_SHIFT | MK_LBUTTON;
    //     else if (GetAsyncKeyState(VK_CONTROL) < 0)  // copy
    //         grfKeyState = MK_CONTROL | MK_LBUTTON;
    //     else if (GetAsyncKeyState(VK_MENU) < 0)     // shortcut
    //         grfKeyState = MK_ALT | MK_LBUTTON;
    //     else
    //         grfKeyState = MK_LBUTTON;

    //     DWORD dwEffect = DROPEFFECT_COPY;
        
    //     DbgPrint("HACK: Sending to desktop\n");
    //     //hr = CRecyclerDropTarget_CreateInstance(IID_PPV_ARG(IDropTarget, &pdt));
    //     hr = CDesktopDropTarget_CreateInstance(IID_PPV_ARG(IDropTarget, &pdt));
    //     if (FAILED_UNEXPECTEDLY(hr))
    //     {
    //         ERR("CDesktopDropTarget_CreateInstance failed\n");
    //         hr = E_FAIL;
    //     } 
    //     else
    //     {
    //         POINTL pt = { 0, 0 };
    //         hr = SHSimulateDrop(pdt, pdtobj, grfKeyState, &pt, &dwEffect);
    //         if (FAILED(hr)) 
    //         {
    //             ERR("SHSimulateDrop failed\n");
    //             hr = E_FAIL;
    //         }
    //     }

    //     pdt->Release();
    // }
    // else
    // {
    //     ERR("SHGetUIObjectFromFullPIDL failed\n");
    // }
    // pdtobj->Release();
    // ILFree(pidlItem);
    return hr;
    // //hr = psf->GetUIObjectOf(lpici->hwnd, 1, (LPCITEMIDLIST *)&pidlItem, IID_IDropTarget, 0, (void**)&pdrop);
    // if (FAILED(hr))
    // {
    //     ERR("SHGetUIObjectFromFullPIDL failed\n");
    //     return E_FAIL;
    // }

    // DbgPrint("SHGetUIObjectFromFullPIDL success\n");
    // DWORD grfKeyState;



    // DbgPrint("call simdrop\n");
    // hr = SHSimulateDrop(pdrop, m_pdtobj, grfKeyState, NULL, NULL);
    // DbgPrint("done simdrop\n");
    // if (hr == S_FALSE) 
    // {
    //     // FIXME: Use ShellMessageBoxW
    //     ERR("SHSimulateDrop failed\n");
    //     hr = E_FAIL;
    // }
        
    // pdrop->Release();
    // ILFree(pidlItem);
    
    // return hr;
}

HRESULT WINAPI
CSendToMenu::GetCommandString(UINT_PTR idCmd, UINT uType,
                                UINT* pwReserved, LPSTR pszName, UINT cchMax )
{
    FIXME("%p %lu %u %p %p %u\n", this,
          idCmd, uType, pwReserved, pszName, cchMax );

    return E_NOTIMPL;
}

HRESULT WINAPI CSendToMenu::HandleMenuMsg(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{

    DbgPrint("This %p uMsg %x\n", this, uMsg);
    return E_NOTIMPL;
}

HRESULT WINAPI
CSendToMenu::Initialize(LPCITEMIDLIST pidlFolder,
                        IDataObject *pdtobj,
                        HKEY hkeyProgID)
{
    m_tgtList = new CSendToList();

    if (pdtobj == NULL) return E_INVALIDARG;

    // Get information on currently selected items
    FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM stm;

    HRESULT hr = pdtobj->GetData(&fe, &stm);
    if (FAILED(hr)) return hr;

    HDROP hDrop = reinterpret_cast<HDROP>(GlobalLock(stm.hGlobal));
    if (hDrop == NULL) return E_INVALIDARG;

    unsigned int count = DragQueryFile(hDrop, (unsigned int)-1, nullptr, 0);
    if (count == 0) 
    {
        GlobalUnlock(stm.hGlobal);
        GlobalFree(stm.hGlobal);
        return S_OK;
    }
    
    m_pathCount = 0;
    m_filePaths = (WCHAR**)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, count * sizeof(WCHAR*));

    // Get all selected files' names
    for (UINT i = 0; i < count; i++) 
    {
        WCHAR path[MAX_PATH]; // FIXME: Handle longer paths in Win10 v1607+
        ZeroMemory(path, MAX_PATH);
        // Skip if there's an error
        if (!DragQueryFile(hDrop, i, path, MAX_PATH))
        {
            ERR("DragQueryFile() failed! Last error: 0x%08x\n", GetLastError());
            continue;
        }
        
        DbgPrint("Path: %S\n", path);
        DWORD attrs = GetFileAttributes(path);
        //DbgPrint("HACK: Set IDataObject\n");
        //m_pdtobj = pdtobj;

        // Skip if there's an error
        if (attrs == INVALID_FILE_ATTRIBUTES)
        {
            ERR("GetFileAttributes() failed! Last error: 0x%08x\n", GetLastError());
            continue;
        }

        // FIXME: Only skip . and ..
        // Skip directories
        if (attrs & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }

        m_filePaths[i] = (WCHAR*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, MAX_PATH * sizeof(WCHAR));
        DbgPrint("Copying path: %S\n", path);
        wcscpy(m_filePaths[i], path);
        m_pathCount++;
        DbgPrint("Copied path: %S\n", m_filePaths[i]);
    }
    
    GlobalUnlock(stm.hGlobal);
    GlobalFree(stm.hGlobal);
    return S_OK;
}

HRESULT SHGetUIObjectFromFullPIDL(LPCITEMIDLIST pidl, HWND hwnd, REFIID riid, void **ppv)
{
    DbgPrint("Enter SHGetUIObjectFromFullPIDL\n");
    LPCITEMIDLIST pidlChild;
    IShellFolder* psf;
    *ppv = NULL;
    HRESULT hr = SHBindToParent(pidl, IID_IShellFolder, (LPVOID*)&psf, &pidlChild);
    if(FAILED(hr))
    {
        ERR("SHBindToParent failed with: 0x%08x\n", hr);
        return hr;
    }
        
    hr = psf->GetUIObjectOf(hwnd, 1, &pidlChild, riid, NULL, ppv);
    if(FAILED(hr))
    {
        ERR("GetUIObjectOf failed with: 0x%08x\n", hr);
        return hr;
    }
    psf->Release();
    
    DbgPrint("Success: SHGetUIObjectFromFullPIDL\n");
    return hr;
}
