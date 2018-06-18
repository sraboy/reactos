/*
 *  SendTo Context Menu extension
 *
 * Copyright 2018 Steven Lavoie <steven.lavoiejr@gmail.com>
 *
 * This code may be distributed under either the MIT 
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

#ifndef _SHE_SENDTOMENU_H_
#define _SHE_SENDTOMENU_H_

class CSendToList;

class CSendToMenu :
    public CComCoClass<CSendToMenu, &CLSID_SendToMenu>,
    public CComObjectRootEx<CComMultiThreadModelNoCS>,
    public IContextMenu,
    public IShellExtInit
{
    private:
        UINT m_idCmdFirst, m_idCmdLast;
        HMENU m_hSubMenu;
        IDataObject * m_pdtobj;
        CSendToList * m_tgtList;
        WCHAR ** m_filePaths;
        UINT m_pathCount;
        VOID AddSendToItem(LPCWSTR pwszName);
        HBITMAP IconToBitmap(HICON hIcon);

    public:
        CSendToMenu();
        ~CSendToMenu();

        // IContextMenu
        virtual HRESULT WINAPI QueryContextMenu(HMENU hMenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);
        virtual HRESULT WINAPI InvokeCommand(LPCMINVOKECOMMANDINFO lpcmi);
        virtual HRESULT WINAPI GetCommandString(UINT_PTR idCommand, UINT uFlags, UINT *lpReserved, LPSTR lpszName, UINT uMaxNameLen);

        // IContextMenu2
        virtual HRESULT WINAPI HandleMenuMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);

        // IShellExtInit
        virtual HRESULT STDMETHODCALLTYPE Initialize(LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID);

        DECLARE_REGISTRY_RESOURCEID(IDR_SENDTOMENU)
        DECLARE_NOT_AGGREGATABLE(CSendToMenu)

        DECLARE_PROTECT_FINAL_CONSTRUCT()

        BEGIN_COM_MAP(CSendToMenu)
            //COM_INTERFACE_ENTRY_IID(IID_IContextMenu2, IContextMenu2)
            COM_INTERFACE_ENTRY_IID(IID_IContextMenu, IContextMenu)
            COM_INTERFACE_ENTRY_IID(IID_IShellExtInit, IShellExtInit)
        END_COM_MAP()
};

#endif /* _SHE_SENDTOMENU_H_ */
