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



CSendToMenu::CSendToMenu()
{
    m_idCmdFirst = 0;
    m_idCmdLast = 0;
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
}

VOID CSendToMenu::AddSendToItem(LPCWSTR pwszName)
{
    MENUITEMINFOW mii;

    ZeroMemory(&mii, sizeof(mii));
    mii.cbSize = sizeof(mii);
    mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE; // | MIIM_DATA;
    mii.fType = MFT_STRING;
    mii.fState = MFS_ENABLED;
    mii.wID = m_idCmdLast;
    mii.dwTypeData = (LPWSTR)pwszName;
    mii.cch = wcslen(mii.dwTypeData);

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
    if (!LoadStringW(shell32_hInstance, IDS_SEND_TO, wszName, _countof(wszName)))
    {
        ERR("Failed to load string\n");
        return E_FAIL;
    }

    // FIXME: Make a resource for deskstr
    
    /* Init first cmd id and submenu */
    m_idCmdFirst = m_idCmdLast = idCmdFirst;
    LPCWSTR deskstr = L"Desktop (create shortcut)";
    m_hSubMenu = CreatePopupMenu();
    AddSendToItem(deskstr);
    
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

HRESULT WINAPI CSendToMenu::InvokeCommand(LPCMINVOKECOMMANDINFO lpici)
{
    // return S_OK;

    HRESULT hr;
    DbgPrint("here\n");
    LPCSTR spath = "C:\\Documents and Settings\\Administrator\\Desktop\\linky.lnk";
    LPCWSTR comment = L"no comment";
    hr = CreateLink(path, spath, comment);
    return hr;

    // if (m_pdtobj)
    // {
    //     DbgPrint("Got m_pdtobj\n");
    //     hr = S_OK;
    //     LPITEMIDLIST pidlItem = NULL;
    //     IDropTarget *pdrop;
        
    //     hr = SHGetUIObjectFromFullPIDL(pidlItem, lpici->hwnd, IID_IDropTarget, (LPVOID*)&pdrop);
    //     DbgPrint("SHGetUIObjectFromFullPIDL done\n");
    //     //hr = psf->GetUIObjectOf(lpici->hwnd, 1, (LPCITEMIDLIST *)&pidlItem, IID_IDropTarget, 0, (void**)&pdrop);
    //     if (SUCCEEDED(hr))
    //     {
    //         DbgPrint("success\n");
    //         DWORD grfKeyState;

    //         if (GetAsyncKeyState(VK_SHIFT) < 0)         // move
    //             grfKeyState = MK_SHIFT | MK_LBUTTON;
    //         else if (GetAsyncKeyState(VK_CONTROL) < 0)  // copy
    //             grfKeyState = MK_CONTROL | MK_LBUTTON;
    //         else if (GetAsyncKeyState(VK_MENU) < 0)     // shortcut
    //             grfKeyState = MK_ALT | MK_LBUTTON;
    //         else
    //             grfKeyState = MK_LBUTTON;
    //         DbgPrint("call simdrop\n");
    //         hr = SHSimulateDrop(pdrop, m_pdtobj, grfKeyState, NULL, NULL);
    //         DbgPrint("done simdrop\n");
    //         if (hr == S_FALSE) // FIXME: Use ShellMessageBoxW
    //             ERR("SHSimulateDrop failed\n");
                
    //         pdrop->Release();
    //         ILFree(pidlItem);
    //     }
    //     else
    //         hr = E_FAIL;
    // }
    // else
    //     hr = E_INVALIDARG;
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
    if (pdtobj == nullptr) { return E_INVALIDARG; }

    // Get information on currently selected items
    FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM stm;

    HRESULT hr = pdtobj->GetData(&fe, &stm);
    if (FAILED(hr)) return hr;

    HDROP hDrop = reinterpret_cast<HDROP>(GlobalLock(stm.hGlobal));
    if (hDrop == NULL) return E_INVALIDARG;

    unsigned int count = DragQueryFile(hDrop, (unsigned int)-1, nullptr, 0);
    if (count == 0) return S_OK;

    // Get all selected files' names
    //WCHAR path[MAX_PATH]; //TODO: Handle longer paths in Win10 v1607+
    for (unsigned int i = 0; i < count; i++) 
    {
        // Skip if there's an error
        if (!DragQueryFile(hDrop, i, path, MAX_PATH))
        {
            ERR("DragQueryFile() failed! Last error: 0x%08x\n", GetLastError());
            continue;
        }
        
        DbgPrint("Path: %S\n", path);
        DWORD attrs = GetFileAttributes(path);

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
    DbgPrint("here\n");
    LPCITEMIDLIST pidlChild;
    IShellFolder* psf;
    *ppv = NULL;
    HRESULT hr = SHBindToParent(pidl, IID_IShellFolder, (LPVOID*)&psf, &pidlChild);
    DbgPrint("here\n");
    if (SUCCEEDED(hr))
    {
        DbgPrint("here\n");
        hr = psf->GetUIObjectOf(hwnd, 1, &pidlChild, riid, NULL, ppv);
        psf->Release();
    }
    DbgPrint("here\n");
    return hr;
}
