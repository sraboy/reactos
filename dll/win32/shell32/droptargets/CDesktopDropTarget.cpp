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
        BOOL fAcceptFmt;       /* flag for pending Drop */
        UINT cfShellIDList;

    public:

        CDesktopDropTarget()
        {
            fAcceptFmt = FALSE;
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
        HRESULT CreateLink(LPCWSTR lpszPathObj, LPCSTR lpszPathLink, LPCWSTR lpszDesc)
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
                    WCHAR wsz[MAX_PATH]; 
                    // Ensure that the string is Unicode
                    MultiByteToWideChar(CP_ACP, 0, lpszPathLink, -1, wsz, MAX_PATH); 

                    hres = ppf->Save(wsz, TRUE); 
                    ppf->Release(); 
                } 
                psl->Release(); 
            } 
            return hres; 
        }

        HRESULT WINAPI Drop(IDataObject *pDataObject,
                            DWORD dwKeyState, POINTL pt, DWORD *pdwEffect)
        {
            DbgPrint("Object sent to desktop\n");
            if (pDataObject == NULL) return E_INVALIDARG;

            FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
            STGMEDIUM stm;
            HRESULT hr = pDataObject->GetData(&fmt, &stm);
            if (FAILED(hr)) return hr;

            // LPDROPFILES lpdf = (LPDROPFILES) GlobalLock(stm.hGlobal);
            // if (!lpdf)
            // {
            //     ERR("Error locking global\n");
            //     return E_FAIL;
            // }

            // LPWSTR obj_path = (LPWSTR) (((byte*) lpdf) + lpdf->pFiles);
            // DbgPrint("Path: %S\n", obj_path);
            // LPCSTR link_path = "C:\\Documents and Settings\\Administrator\\Desktop\\linky.lnk";
            // LPCWSTR comment = L"no comment";
            // hr = CreateLink(obj_path, link_path, comment);

            HDROP hDrop = (HDROP)GlobalLock(stm.hGlobal);
            if (hDrop == NULL) return E_INVALIDARG;

            unsigned int count = DragQueryFile(hDrop, (unsigned int)-1, nullptr, 0);
            DbgPrint("Found %d files in HDROP\n", count);
            for (unsigned int i = 0; i < count; i++) 
            {
                WCHAR obj_path[MAX_PATH];
                // Skip if there's an error
                int chars = DragQueryFile(hDrop, i, obj_path, MAX_PATH);
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
                LPCSTR link_path = "C:\\Documents and Settings\\Administrator\\Desktop\\linky.lnk";
                LPCWSTR comment = L"no comment";
                hr = CreateLink(obj_path, link_path, comment);
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
