/*
 * Send To Context Menu extension
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

class CSendToList
{
    public:
        struct SSendTgt
        {
            WCHAR wszFilename[MAX_PATH];
            GUID clsid;
            //WCHAR wszCmd[MAX_PATH];
            //WCHAR wszManufacturer[256];
            //WCHAR wszName[256];
            //BOOL bHidden;
            //BOOL bRecommended;
            //BOOL bMRUList;
            HICON hIcon;
        };

        CSendToList();
        ~CSendToList();

        BOOL Load();
        //SSendTgt *Add(LPCWSTR pwszPath);
        //static BOOL SaveApp(SSendTgt *pApp);
        //SSendTgt *Find(LPCWSTR pwszFilename);
        //static LPCWSTR GetName(SSendTgt *pApp);
        //static HICON GetIcon(SSendTgt *pApp);
        //BOOL LoadRecommended(LPCWSTR pwszFilePath);
        
        inline SSendTgt *GetList() { return m_pApp; }
        inline UINT GetCount() { return m_cApp; }
        //inline UINT GetRecommendedCount() { return m_cRecommended; }

    private:
        typedef struct _LANGANDCODEPAGE
        {
            WORD lang;
            WORD code;
        } LANGANDCODEPAGE, *LPLANGANDCODEPAGE;

        SSendTgt *m_pApp;
        UINT m_cApp;//, m_cRecommended;
        //BOOL m_bNoOpen;

        // SSendTgt *AddInternal(LPCWSTR pwszFilename);
        // static BOOL LoadInfo(SSendTgt *pApp);
        // static VOID GetPathFromCmd(LPWSTR pwszAppPath, LPCWSTR pwszCmd);
        // BOOL LoadProgIdList(HKEY hKey, LPCWSTR pwszExt);
        // static HANDLE OpenMRUList(HKEY hKey);
        // BOOL LoadMRUList(HKEY hKey);
        // BOOL LoadAppList(HKEY hKey);
        // VOID LoadFromProgIdKey(HKEY hKey, LPCWSTR pwszExt);
        // VOID LoadRecommendedFromHKCR(LPCWSTR pwszExt);
        // VOID LoadRecommendedFromHKCU(LPCWSTR pwszExt);
        // static BOOL AddAppToMRUList(SSendTgt *pApp, LPCWSTR pwszFilename);

        // inline VOID SetRecommended(SSendTgt *pApp)
        // {
            // if (!pApp->bRecommended)
                // ++m_cRecommended;
            // pApp->bRecommended = TRUE;
        // }
};

CSendToList::CSendToList() {}
CSendToList::~CSendToList() {}

BOOL CSendToList::Load()
{
    WIN32_FIND_DATA data;
    WCHAR send_to_path[MAX_PATH];

    if (FAILED(SHGetFolderPathW(NULL, CSIDL_SENDTO, NULL, 0, send_to_path)))
    {
        ERR("SHGetFolderPathW failed\n");
        return FALSE;
    }

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
            DbgPrint("found file: %S\n", data.cFileName);
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
    return found;
}

CSendToMenu::CSendToMenu() :
m_idCmdFirst(0), m_idCmdLast(0), m_pdtobj(NULL), m_tgtList(NULL)
{
}

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
    DbgPrint("here\n");
    // FIXME: Check SendTo folder
    DbgPrint("hMenu %p indexMenu %u idFirst %u idLast %u uFlags %u\n", hMenu, indexMenu, idCmdFirst, idCmdLast, uFlags);

    WCHAR wszName[100];
    if (!LoadStringW(shell32_hInstance, IDS_SENDTO_MENU, wszName, _countof(wszName)))
    {
        ERR("Failed to load string\n");
        return E_FAIL;
    }

    // FIXME: Make a resource for deskstr
    
    /* Init first cmd id and submenu */
    m_idCmdFirst = m_idCmdLast = idCmdFirst;

    m_hSubMenu = CreatePopupMenu();
    LPCWSTR deskstr = L"Desktop (create shortcut)";
    AddSendToItem(deskstr);
    LPCWSTR zipstr = L"Compressed Folder";
    AddSendToItem(zipstr);
    
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

WCHAR path[MAX_PATH];

HRESULT CSendToMenu::CreateLink(LPCWSTR lpszPathObj, LPCSTR lpszPathLink, LPCWSTR lpszDesc)
{ 
    HRESULT hres; 
    IShellLink* psl; 

    // Get a pointer to the IShellLink interface. It is assumed that CoInitialize
    // has already been called.
    hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl); 
    if (SUCCEEDED(hres)) 
    {
        IPersistFile* ppf; 

        // Set the path to the shortcut target and add the description. 
        psl->SetPath(lpszPathObj); 
        psl->SetDescription(lpszDesc); 

        // Query IShellLink for the IPersistFile interface, used for saving the 
        // shortcut in persistent storage. 
        hres = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&ppf); 

        if (SUCCEEDED(hres)) 
        { 
            WCHAR wsz[MAX_PATH]; 

            // Ensure that the string is Unicode. 
            MultiByteToWideChar(CP_ACP, 0, lpszPathLink, -1, wsz, MAX_PATH); 

            // Save the link by calling IPersistFile::Save. 
            hres = ppf->Save(wsz, TRUE); 
            ppf->Release(); 
        } 
        psl->Release(); 
    } 
    return hres; 
}

// CLSID CLSID_ZipFolder = { 0x888DCA60, 0xFC0A, 0x11CF, { 0x8F, 0x0F, 0x00, 0xC0, 0x4F, 0xD7, 0xD0, 0x62 } };

// #ifdef __cplusplus
// #   define IID_PPV_ARG(Itype, ppType) IID_##Itype, reinterpret_cast<void**>((static_cast<Itype**>(ppType)))
// #   define IID_NULL_PPV_ARG(Itype, ppType) IID_##Itype, NULL, reinterpret_cast<void**>((static_cast<Itype**>(ppType)))
// #else
// #   define IID_PPV_ARG(Itype, ppType) IID_##Itype, (void**)(ppType)
// #   define IID_NULL_PPV_ARG(Itype, ppType) IID_##Itype, NULL, (void**)(ppType)
// #endif

HRESULT WINAPI CSendToMenu::InvokeCommand(LPCMINVOKECOMMANDINFO lpici)
{
    DbgPrint("This %p idFirst %u idLast %u idCmd %u\n", this, m_idCmdFirst, m_idCmdLast, m_idCmdFirst + LOWORD(lpici->lpVerb));
    IDataObject *pdtobj = NULL;
    LPITEMIDLIST pidlItem = NULL;
    
    HRESULT hr = SHILCreateFromPathW(m_wszPath, &pidlItem, NULL);
    if (FAILED(hr))
    {
        ERR("SHILCreateFromPathW failed\n");
        return E_FAIL;
    }
    
    
    hr = SHGetUIObjectFromFullPIDL(pidlItem, lpici->hwnd, IID_IDataObject, (LPVOID*)&pdtobj);
    
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
        POINTL pt = { 0, 0 };
        DbgPrint("HACK: Sending to recycler\n");
        CRecyclerDropTarget_CreateInstance(IID_PPV_ARG(IDropTarget, &pdt));
        hr = SHSimulateDrop(pdt, pdtobj, grfKeyState, &pt, &dwEffect);
        if (FAILED(hr)) 
        {
            // FIXME: Use ShellMessageBoxW
            ERR("SHSimulateDrop failed\n");
            hr = E_FAIL;
        }
        pdt->Release();
    }
    else
    {
        ERR("SHGetUIObjectFromFullPIDL failed\n");
    }
    pdtobj->Release();
    ILFree(pidlItem);
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
    if(!m_tgtList->Load())
    {
        ERR("No targets\n");
        return E_FAIL;
    }

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

    // Get all selected files' names
    //WCHAR path[MAX_PATH]; //TODO: Handle longer paths in Win10 v1607+
    for (unsigned int i = 0; i < count; i++) 
    {
        // Skip if there's an error
        if (!DragQueryFile(hDrop, i, m_wszPath, MAX_PATH))
        {
            ERR("DragQueryFile() failed! Last error: 0x%08x\n", GetLastError());
            continue;
        }
        
        DbgPrint("Path: %S\n", m_wszPath);
        DWORD attrs = GetFileAttributes(m_wszPath);
        //DbgPrint("HACK: Set IDataObject\n");
        //m_pdtobj = pdtobj;
        // Skip if there's an error
        if (attrs == INVALID_FILE_ATTRIBUTES)
        {
            ERR("GetFileAttributes() failed! Last error: 0x%08x\n", GetLastError());
            continue;
        }

        // Skip directories
        if (attrs & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }
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
