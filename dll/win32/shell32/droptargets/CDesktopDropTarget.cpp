/*
 * Send To Desktop (create shortcut) functionality
 *
 * Copyright (C) 2018 Steven Lavoie
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

// FIXME: This should be moved to sendmail.dll once it's created

#include <precomp.h>

WINE_DEFAULT_DEBUG_CHANNEL (shell);

class CDesktopDropTarget :
    public CComObjectRootEx<CComMultiThreadModelNoCS>,
    public IDropTarget
{
    private:
        UINT cfShellIDList;

    public:

        CDesktopDropTarget()
        {
            FIXME("This should be moved to sendmail.dll once it's created\n");
            cfShellIDList = RegisterClipboardFormatW(CFSTR_SHELLIDLIST);
        }

        HRESULT WINAPI DragEnter(IDataObject *pDataObject,
                                DWORD dwKeyState, POINTL pt, DWORD *pdwEffect)
        {
            return E_NOTIMPL;
        }

        HRESULT WINAPI DragOver(DWORD dwKeyState, POINTL pt, DWORD *pdwEffect)
        {
            return E_NOTIMPL;
        }

        HRESULT WINAPI DragLeave()
        {
            return E_NOTIMPL;
        }

        // FIXME: Use IShellLink_ConstructFromPath
        HRESULT CreateLink(LPCWSTR lpszPathObj, LPCWSTR lpszPathLink, LPCWSTR lpszDesc)
        { 
            HRESULT hres; 
            IShellLink* psl; 

            // Assumes CoInitialize has already been called
            hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl); 
            if (SUCCEEDED(hres)) 
            {
                IPersistFile* ppf; 

                psl->SetPath(lpszPathObj); 
                psl->SetDescription(lpszDesc); 

                hres = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&ppf); 

                if (SUCCEEDED(hres)) 
                { 
                    hres = ppf->Save(lpszPathLink, TRUE); 
                    ppf->Release(); 
                } 
                psl->Release(); 
            } 
            return hres; 
        }

        HRESULT WINAPI Drop(IDataObject *pDataObject,
                            DWORD dwKeyState, POINTL pt, DWORD *pdwEffect)
        {
            TRACE("Object sent to desktop\n");
            if (pDataObject == NULL) return E_INVALIDARG;

            FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
            STGMEDIUM stm;
            HRESULT hr = pDataObject->GetData(&fmt, &stm);
            if (FAILED(hr)) return hr;

            HDROP hDrop = (HDROP)GlobalLock(stm.hGlobal);
            if (hDrop == NULL) return E_INVALIDARG;

            UINT count = DragQueryFile(hDrop, (UINT)-1, nullptr, 0);
            DbgPrint("Found %d file(s) in HDROP\n", count);
            for (UINT i = 0; i < count; i++)
            {
                WCHAR obj_path[MAX_PATH];
                ZeroMemory(obj_path, MAX_PATH);

                // Skip if there's an error
                UINT chars = DragQueryFile(hDrop, i, obj_path, MAX_PATH);
                if (!chars)
                {
                    ERR("DragQueryFile() failed! Last error: 0x%08x\n", GetLastError());
                    continue;
                }
                else
                {
                    DbgPrint("Got %d chars in path: %.*S\n", chars, obj_path);
                }
                
                DbgPrint("Path: %S\n", obj_path);
                DWORD attrs = GetFileAttributes(obj_path);
                if (attrs == INVALID_FILE_ATTRIBUTES)
                {
                    ERR("GetFileAttributes() failed! Last error: 0x%08x\n", GetLastError());
                    continue;
                }

                // Skip directories
                if (attrs & FILE_ATTRIBUTE_DIRECTORY) {
                    continue;
                }
                LPWSTR name = PathFindFileNameW(obj_path);
                DbgPrint("File name: %S\n", name);

                WCHAR link_path[MAX_PATH];
                hr = SHGetFolderPath(HWND_DESKTOP, CSIDL_DESKTOP, NULL, SHGFP_TYPE_CURRENT, link_path);
                if(hr != S_OK)
                {
                    ERR("SHGetSpecialFolderPath failed: 0x%08x\n", hr);
                    return E_FAIL;
                }

                if (FAILED(StringCchCatW(link_path, MAX_PATH, L"\\Shortcut to ")))
                {
                    ERR("StringCchCatW failed\n");
                    return E_FAIL;
                }

                if (FAILED(StringCchCatW(link_path, MAX_PATH, name)))
                {
                    ERR("StringCchCatW failed\n");
                    return E_FAIL;
                }

                if (FAILED(StringCchCatW(link_path, MAX_PATH, L".lnk")))
                {
                    ERR("StringCchCatW failed\n");
                    return E_FAIL;
                }

                DbgPrint("Shortcut path: %S\n", link_path);
                hr = CreateLink(obj_path, link_path, L"");
            }

            GlobalUnlock(stm.hGlobal);
            GlobalFree(stm.hGlobal);
            return hr;
        }

        DECLARE_NOT_AGGREGATABLE(CDesktopDropTarget)
        DECLARE_PROTECT_FINAL_CONSTRUCT()

        BEGIN_COM_MAP(CDesktopDropTarget)
        COM_INTERFACE_ENTRY_IID(IID_IDropTarget, IDropTarget)
        END_COM_MAP()
};

HRESULT CDesktopDropTarget_CreateInstance(REFIID riid, LPVOID * ppvOut)
{
    return ShellObjectCreator<CDesktopDropTarget>(riid, ppvOut);
}
