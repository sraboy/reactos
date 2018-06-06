/*
 * Copyright (C) 1999 Juergen Schmied
 * Copyright (C) 2009 Andrew Hill
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

#ifndef __SHLGUID_UNDOC_H
#define __SHLGUID_UNDOC_H

DEFINE_GUID(CLSID_RebarBandSite,         0xECD4FC4D, 0x521C, 0x11D0, 0xB7, 0x92, 0x00, 0xA0, 0xC9, 0x03, 0x12, 0xE1);
DEFINE_GUID(CLSID_BandSiteMenu,          0xECD4FC4E, 0x521C, 0x11D0, 0xB7, 0x92, 0x00, 0xA0, 0xC9, 0x03, 0x12, 0xE1);
DEFINE_GUID(IID_IBandSiteHelper,         0xD1E7AFEA, 0x6A2E, 0x11D0, 0x8C, 0x78, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xB4);
DEFINE_GUID(CLSID_PersonalStartMenu,     0x3F6953F0, 0x5359, 0x47FC, 0xBD, 0x99, 0x9F, 0x2C, 0xB9, 0x5A, 0x62, 0xFD);
DEFINE_GUID(IID_ITrayPriv,               0x4622AD10, 0xFF23, 0x11D0, 0x8D, 0x34, 0x00, 0xA0, 0xC9, 0x0F, 0x27, 0x19);
DEFINE_GUID(IID_ITrayPriv2,              0x9E83C057, 0xFF23, 0x6823, 0x1F, 0x4F, 0xBF, 0xA3, 0x74, 0x61, 0xD4, 0x0A);
DEFINE_GUID(IID_IShellMenu2,             0x6F51C646, 0x0EFE, 0x4370, 0x88, 0x2A, 0xC1, 0xF6, 0x1C, 0xB2, 0x7C, 0x3B);
DEFINE_GUID(IID_IWinEventHandler,        0xEA5F2D61, 0xE008, 0x11CF, 0x99, 0xCB, 0x00, 0xC0, 0x4F, 0xD6, 0x44, 0x97);
DEFINE_GUID(IID_IShellMenuAcc,           0xFAF6FE96, 0xCE5E, 0x11D1, 0x83, 0x71, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xD0);
DEFINE_GUID(IID_IShellBrowserService,    0x1307EE17, 0xEA83, 0x49EB, 0x96, 0xB2, 0x3A, 0x28, 0xE2, 0xD7, 0x04, 0x8A);
DEFINE_GUID(IID_IShellFolderView,        0x37A378C0, 0xF82D, 0x11CE, 0xAE, 0x65, 0x08, 0x00, 0x2B, 0x2E, 0x12, 0x62);

DEFINE_GUID(SID_SProxyBrowser,             0x20C46561, 0x8491, 0x11CF, 0x96, 0x0C, 0x00, 0x80, 0xC7, 0xF4, 0xEE, 0x85);

// this class lives in shell32.dll
DEFINE_GUID(IID_IGlobalFolderSettings,     0xEF8AD2D3, 0xAE36, 0x11D1, 0xB2, 0xD2, 0x00, 0x60, 0x97, 0xDF, 0x8C, 0x11);
DEFINE_GUID(CLSID_GlobalFolderSettings,    0xEF8AD2D1, 0xAE36, 0x11D1, 0xB2, 0xD2, 0x00, 0x60, 0x97, 0xDF, 0x8C, 0x11);
DEFINE_GUID(IID_IRegTreeOptions,           0xAF4F6511, 0xF982, 0x11D0, 0x85, 0x95, 0x00, 0xAA, 0x00, 0x4C, 0xD6, 0xD8);
DEFINE_GUID(CLSID_CRegTreeOptions,         0xAF4F6510, 0xF982, 0x11D0, 0x85, 0x95, 0x00, 0xAA, 0x00, 0x4C, 0xD6, 0xD8);
DEFINE_GUID(IID_IExplorerToolbar,          0x8455F0C1, 0x158F, 0x11D0, 0x89, 0xAE, 0x00, 0xA0, 0xC9, 0x0A, 0x90, 0xAC);

// not registered, lives in browseui.dll
DEFINE_GUID(CLSID_BrowserBar,              0x9581015C, 0xD08E, 0x11D0, 0x8D, 0x36, 0x00, 0xA0, 0xC9, 0x2D, 0xBF, 0xE8);

DEFINE_GUID(CGID_DefViewFrame,             0x710EB7A1, 0x45ED, 0x11D0, 0x92, 0x4A, 0x00, 0x20, 0xAF, 0xC7, 0xAC, 0x4D);

// browseui.dll
DEFINE_GUID(IID_IACLCustomMRU,             0xf729fc5e, 0x8769, 0x4f3e, 0xbd, 0xb2, 0xd7, 0xb5, 0x0f, 0xd2, 0x27, 0x5b);

DEFINE_GUID(CLSID_SH_AddressBand,          0x01E04581, 0x4EEE, 0x11D0, 0xBF, 0xE9, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);
DEFINE_GUID(CLSID_AddressEditBox,          0xA08C11D2, 0xA228, 0x11D0, 0x82, 0x5B, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);
DEFINE_GUID(IID_IAddressEditBox,           0xA08C11D1, 0xA228, 0x11D0, 0x82, 0x5B, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);

DEFINE_GUID(IID_IAddressBand,              0x106E86E1, 0x52B5, 0x11D0, 0xBF, 0xED, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);
DEFINE_GUID(CLSID_BrandBand,               0x22BF0C20, 0x6DA7, 0x11D0, 0xB3, 0x73, 0x00, 0xA0, 0xC9, 0x03, 0x49, 0x38);
DEFINE_GUID(SID_SBrandBand,                0x82A62DE8, 0x32AC, 0x4E4A, 0x99, 0x35, 0x90, 0x46, 0xC3, 0x78, 0xCF, 0x90);
DEFINE_GUID(CLSID_InternetToolbar,         0x5E6AB780, 0x7743, 0x11CF, 0xA1, 0x2B, 0x00, 0xAA, 0x00, 0x4A, 0xE8, 0x37);

DEFINE_GUID(CGID_PrivCITCommands,          0x67077B95, 0x4F9D, 0x11D0, 0xB8, 0x84, 0x00, 0xAA, 0x00, 0xB6, 0x01, 0x04);
DEFINE_GUID(CGID_Theater,                  0x0F12079C, 0xC193, 0x11D0, 0x8D, 0x49, 0x00, 0xC0, 0x4F, 0xC9, 0x9D, 0x61);
DEFINE_GUID(CGID_ShellBrowser,             0x3531F060, 0x22B3, 0x11D0, 0x96, 0x9E, 0x00, 0xAA, 0x00, 0xB6, 0x01, 0x04);

DEFINE_GUID(CLSID_SearchBand,              0x2559A1F0, 0x21D7, 0x11D4, 0xBD, 0xAF, 0x00, 0xC0, 0x4F, 0x60, 0xB9, 0xF0);
DEFINE_GUID(CLSID_TipOfTheDayBand,         0x4D5C8C25, 0xD075, 0x11D0, 0xB4, 0x16, 0x00, 0xC0, 0x4F, 0xB9, 0x03, 0x76);
DEFINE_GUID(CLSID_DiscussBand,             0xBDEADE7F, 0xC265, 0x11D0, 0xBC, 0xED, 0x00, 0xA0, 0xC9, 0x0A, 0xB5, 0x0F);
DEFINE_GUID(CLSID_SH_FavBand,              0xEFA24E61, 0xB078, 0x11D0, 0x89, 0xE4, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E);
DEFINE_GUID(CLSID_SH_HistBand,             0xEFA24E62, 0xB078, 0x11D0, 0x89, 0xE4, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E);
DEFINE_GUID(CLSID_ExplorerBand,            0xEFA24E64, 0xB078, 0x11D0, 0x89, 0xE4, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E);
DEFINE_GUID(CLSID_SH_SearchBand,           0x21569614, 0xB795, 0x46B1, 0x85, 0xF4, 0xE7, 0x37, 0xA8, 0xDC, 0x09, 0xAD);
DEFINE_GUID(CLSID_FileSearchBand,          0xC4EE31F3, 0x4768, 0x11D2, 0xBE, 0x5C, 0x00, 0xA0, 0xC9, 0xA8, 0x3D, 0xA1);
DEFINE_GUID(CLSID_IE_SearchBand,           0x30D02401, 0x6A81, 0x11D0, 0x82, 0x74, 0x00, 0xC0, 0x4F, 0xD5, 0xAE, 0x38);
DEFINE_GUID(CLSID_ChannelsBand,            0xEFA24E63, 0xB078, 0x11D0, 0x89, 0xE4, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E);
// missing ResearchBand

DEFINE_GUID(IID_IBandNavigate,             0x3697C30B, 0xCD88, 0x11D0, 0x8A, 0x3E, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E);
DEFINE_GUID(IID_INamespaceProxy,           0xCF1609EC, 0xFA4B, 0x4818, 0xAB, 0x01, 0x55, 0x64, 0x33, 0x67, 0xE6, 0x6D);
DEFINE_GUID(IID_IBandProxy,                0x208CE801, 0x754B, 0x11D0, 0x80, 0xCA, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);
DEFINE_GUID(CLSID_BandProxy,               0xF61FFEC1, 0x754F, 0x11D0, 0x80, 0xCA, 0x00, 0xAA, 0x00, 0x5B, 0x43, 0x83);
DEFINE_GUID(SID_IBandProxy,                0x80243AC1, 0x0569, 0x11D1, 0xA7, 0xAE, 0x00, 0x60, 0x97, 0xDF, 0x5B, 0xD4);
DEFINE_GUID(CLSID_ShellSearchExt,          0x169A0691, 0x8DF9, 0x11D1, 0xA1, 0xC4, 0x00, 0xC0, 0x4F, 0xD7, 0x5D, 0x13);

DEFINE_GUID(CLSID_CommonButtons,           0x1E79697E, 0x9CC5, 0x11D1, 0xA8, 0x3F, 0x00, 0xC0, 0x4F, 0xC9, 0x9D, 0x61);
DEFINE_GUID(CLSID_CCommonBrowser,          0xAF604EFE, 0x8897, 0x11D1, 0xB9, 0x44, 0x00, 0xA0, 0xC9, 0x03, 0x12, 0xE1);
DEFINE_GUID(CLSID_DeskBar,                 0xecd4fc4c, 0x521c, 0x11d0, 0xb7, 0x92, 0x00, 0xa0, 0xc9, 0x03, 0x12, 0xe1);
DEFINE_GUID(CLSID_DeskBarApp,              0x3ccf8a41, 0x5c85, 0x11d0, 0x97, 0x96, 0x00, 0xaa, 0x00, 0xb9, 0x0a, 0xdf);

DEFINE_GUID(CGID_BrandCmdGroup,            0x25019D8C, 0x9EE0, 0x45C0, 0x88, 0x3B, 0x97, 0x2D, 0x48, 0x32, 0x5E, 0x18);

DEFINE_GUID(IID_INSCTree,                  0x43A8F463, 0x4222, 0x11D2, 0xB6, 0x41, 0x00, 0x60, 0x97, 0xDF, 0x5B, 0xD4);
DEFINE_GUID(IID_INSCTree2,                 0x801C1AD5, 0xC47C, 0x428C, 0x97, 0xAF, 0xE9, 0x91, 0xE4, 0x85, 0x7D, 0x97);

DEFINE_GUID(IID_IInitializeObject,         0x4622AD16, 0xFF23, 0x11D0, 0x8D, 0x34, 0x00, 0xA0, 0xC9, 0x0F, 0x27, 0x19);
DEFINE_GUID(IID_IBanneredBar,              0x596A9A94, 0x013E, 0x11D1, 0x8D, 0x34, 0x00, 0xA0, 0xC9, 0x0F, 0x27, 0x19);

DEFINE_GUID(CLSID_StartMenu,               0x4622AD11, 0xFF23, 0x11D0, 0x8D, 0x34, 0x00, 0xA0, 0xC9, 0x0F, 0x27, 0x19);
DEFINE_GUID(CLSID_MenuBandSite,            0xE13EF4E4, 0xD2F2, 0x11D0, 0x98, 0x16, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0x72);
DEFINE_GUID(SHELL32_AdvtShortcutProduct,   0x9DB1186F, 0x40DF, 0x11D1, 0xAA, 0x8C, 0x00, 0xC0, 0x4F, 0xB6, 0x78, 0x63);
DEFINE_GUID(SHELL32_AdvtShortcutComponent, 0x9DB1186E, 0x40DF, 0x11D1, 0xAA, 0x8C, 0x00, 0xC0, 0x4F, 0xB6, 0x78, 0x63);
DEFINE_GUID(CLSID_OpenWithMenu,            0x09799AFB, 0xAD67, 0x11D1, 0xAB, 0xCD, 0x00, 0xC0, 0x4F, 0xC3, 0x09, 0x36);
DEFINE_GUID(CLSID_SendToMenu,              0x7BA4C740, 0x9E81, 0x11CF, 0x99, 0xD3, 0x00, 0xAA, 0x00, 0x4A, 0xE8, 0x37);

DEFINE_GUID(CLSID_FontsFolderShortcut,     0xD20EA4E1, 0x3957, 0x11D2, 0xA4, 0x0B, 0x0C, 0x50, 0x20, 0x52, 0x41, 0x52);
DEFINE_GUID(CLSID_AdminFolderShortcut,     0xD20EA4E1, 0x3957, 0x11D2, 0xA4, 0x0B, 0x0C, 0x50, 0x20, 0x52, 0x41, 0x53);

DEFINE_GUID(CLSID_FolderOptions,           0x6DFD7C5C, 0x2451, 0x11D3, 0xA2, 0x99, 0x00, 0xC0, 0x4F, 0x8E, 0xF6, 0xAF);

DEFINE_GUID(CLSID_ShellFileDefExt,         0x21B22460, 0x3AEA, 0x1069, 0xA2, 0xDC, 0x08, 0x00, 0x2B, 0x30, 0x30, 0x9D);
DEFINE_GUID(CLSID_ShellDrvDefExt,          0x5F5295E0, 0x429F, 0x1069, 0xA2, 0xE2, 0x08, 0x00, 0x2B, 0x30, 0x30, 0x9D);
DEFINE_GUID(CLSID_ShellNetDefExt,          0x86422020, 0x42A0, 0x1069, 0xA2, 0xE5, 0x08, 0x00, 0x2B, 0x30, 0x30, 0x9D);

DEFINE_GUID(CLSID_ExeDropHandler, 		   0x86C86720, 0x42A0, 0x1069, 0xA2, 0xE8, 0x08, 0x00, 0x2B, 0x30, 0x30, 0x9D);

DEFINE_GUID(CLSID_MergedFolder,            0x26FDC864, 0xBE88, 0x46E7, 0x92, 0x35, 0x03, 0x2D, 0x8E, 0xA5, 0x16, 0x2E);
DEFINE_GUID(IID_IAugmentedShellFolder,     0x91EA3F8C, 0xC99B, 0x11D0, 0x98, 0x15, 0x00, 0xC0, 0x4F, 0xD9, 0x19, 0x72);
DEFINE_GUID(IID_IAugmentedShellFolder2,    0x8DB3B3F4, 0x6CFE, 0x11D1, 0x8A, 0xE9, 0x00, 0xC0, 0x4F, 0xD9, 0x18, 0xD0);
DEFINE_GUID(IID_IAugmentedShellFolder3,    0x4F755EA8, 0x247D, 0x479B, 0x91, 0x81, 0x22, 0x7D, 0x09, 0xC2, 0xE0, 0x01);

DEFINE_GUID(CGID_MenuDeskBar,              0x5C9F0A12, 0x959E, 0x11D0, 0xA3, 0xA4, 0x00, 0xA0, 0xC9, 0x08, 0x26, 0x36);

DEFINE_GUID(CLSID_DialupConnectionUi,      0x7007ACC1, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_DirectConnectionUi,      0x7007ACC2, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_InboundConnectionUi,     0x7007ACC3, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_InternetConnectionUi,    0x7007ACC4, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_LanConnectionUi,         0x7007ACC5, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_VpnConnectionUi,         0x7007ACC6, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_ConnectionFolder,        0x7007ACC7, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_ConnectionFolderEnum,    0x7007ACC8, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_ConnectionTray,          0x7007ACCF, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_ConnectionCommonUi,      0x7007ACD1, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_NetConnectionUiUtilities,0x7007ACD3, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_PPPoEUi,                 0x7007ACD4, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);
DEFINE_GUID(CLSID_SharedAccessConnectionUi,0x7007ACD5, 0x3202, 0x11D1, 0xAA, 0xD2, 0x00, 0x80, 0x5F, 0xC1, 0x27, 0x0E);

DEFINE_GUID(CLSID_SysTray,                 0x35CEC8A3, 0x2BE6, 0x11D2, 0x87, 0x73, 0x92, 0xE2, 0x20, 0x52, 0x41, 0x53);

DEFINE_GUID(CLSID_BackgroundTaskScheduler, 0x603D3800, 0xBD81, 0x11d0, 0xA3, 0xA5, 0x00, 0xC0, 0x4F, 0xD7, 0x06, 0xEC);
DEFINE_GUID(CLSID_SharedTaskScheduler,     0x603D3801, 0xBD81, 0x11d0, 0xA3, 0xA5, 0x00, 0xC0, 0x4F, 0xD7, 0x06, 0xEC);

/* The following list of interfaces was taken from here: http://www.geoffchappell.com/studies/windows/shell/shell32/interfaces/index.htm */
DEFINE_GUID(IID_IAggregateFilterCondition, 0x86228AA3, 0xA736, 0x4733, 0xBD, 0x8A, 0x10, 0xA8, 0x3C, 0x69, 0xBF, 0x84);
DEFINE_GUID(IID_IAliasRegistrationCallback,0xF6D2D333, 0xBEC1, 0x4194, 0x8A, 0x6E, 0x8A, 0xBA, 0xD0, 0x0F, 0x8D, 0xCF);
DEFINE_GUID(IID_IAssociationArrayInitialize,0xEE9165BF,0xA4D9, 0x474B, 0x82, 0x36, 0x67, 0x35, 0xCB, 0x7E, 0x28, 0xB6);
DEFINE_GUID(IID_IAssociationList,          0xDC8F8556, 0xEFBD, 0x4EFA, 0x8B, 0x64, 0xBB, 0xA8, 0x4B, 0x4E, 0xCD, 0x7F);
DEFINE_GUID(IID_IBackReferencedObject,     0xC938B119, 0xD3AD, 0x4D02, 0xB5, 0xEE, 0x16, 0x4C, 0x2E, 0xC8, 0x16, 0x0E);
DEFINE_GUID(IID_IBasePropPage,             0xB34E525B, 0x9EB4, 0x433B, 0x8E, 0x0F, 0x01, 0x9C, 0x4F, 0x21, 0xD7, 0xE7);
DEFINE_GUID(IID_ICommonLayoutDefinition,   0xD72FF553, 0xAE8F, 0x4DAE, 0x9E, 0xE8, 0x83, 0x3A, 0x9E, 0x02, 0x5C, 0xB0);
DEFINE_GUID(IID_IControlPanelEnumerator,   0xCE247F0D, 0x2579, 0x4BA8, 0xB3, 0x93, 0x29, 0xA4, 0x3D, 0x88, 0xEB, 0x31);
DEFINE_GUID(IID_IDelegateHostItemContainer,0x02468693, 0xE7E5, 0x4C6B, 0x99, 0x95, 0x64, 0xCE, 0x5F, 0x51, 0xCE, 0xC4);
DEFINE_GUID(IID_IDrawPropertyControl,      0xE6DFF6FD, 0xBCD5, 0x4162, 0x9C, 0x65, 0xA3, 0xB1, 0x8C, 0x61, 0x6F, 0xDB);
DEFINE_GUID(IID_IEnumAssociationElements,  0xA6B0FB57, 0x7523, 0x4439, 0x94, 0x25, 0xEB, 0xE9, 0x98, 0x23, 0xB8, 0x28);
DEFINE_GUID(IID_IEnumerateAssociationElements,0x7513A16E,0xCF00,0x4817,0xA8, 0x90, 0xA2, 0x3C, 0x60, 0x8F, 0xE7, 0xB7);
DEFINE_GUID(IID_IExecuteCommand,           0x7F9185B0, 0xCB92, 0x43C5, 0x80, 0xA9, 0x92, 0x27, 0x7A, 0x4F, 0x7B, 0x54);
DEFINE_GUID(IID_IFilterCondition,          0xFCA2857D, 0x1760, 0x4AD3, 0x8C, 0x63, 0xC9, 0xB6, 0x02, 0xFC, 0xBA, 0xEA);
DEFINE_GUID(IID_IFolderNotify,             0x0FF22D71, 0x5172, 0x11D1, 0xA9, 0xC6, 0x08, 0x00, 0x36, 0xAF, 0x3F, 0x03);
DEFINE_GUID(IID_IFolderProperties,         0x7361EE29, 0x5BAD, 0x459D, 0xA9, 0xF5, 0xF6, 0x55, 0x06, 0x89, 0x82, 0xF0);
DEFINE_GUID(IID_IFolderType,               0x053B4A86, 0x0DC9, 0x40A3, 0xB7, 0xED, 0xBC, 0x6A, 0x2E, 0x95, 0x1F, 0x48);
DEFINE_GUID(IID_IFolderWithSearchRoot,     0x4CA18419, 0x902A, 0x4F03, 0x8D, 0xB4, 0xB2, 0x4D, 0x21, 0x8A, 0xC5, 0xAA);
DEFINE_GUID(IID_IFrameLayoutDefinition,    0x176C11B1, 0x4302, 0x4164, 0x84, 0x30, 0xD5, 0xA9, 0xF0, 0xEE, 0xAC, 0xDB);
DEFINE_GUID(IID_IItemFilter,               0x7FCBEB25, 0xED60, 0x45C9, 0x9F, 0x5E, 0x57, 0xB4, 0x84, 0x93, 0xC4, 0xDD);
DEFINE_GUID(IID_IItemFilterOwner,          0x7E1AF054, 0x83A6, 0x47FC, 0xAB, 0x27, 0xA5, 0x8A, 0xE8, 0xD9, 0xC7, 0x05);
DEFINE_GUID(IID_ILocalizableItemParent,    0x148BCE7A, 0x0D60, 0x4254, 0x81, 0x3F, 0xA4, 0xE4, 0xEA, 0x46, 0xDF, 0x3F);
DEFINE_GUID(IID_INewItemAdvisor,           0x24D16EE5, 0x10F5, 0x4DE3, 0x87, 0x66, 0xD2, 0x37, 0x79, 0xBA, 0x7A, 0x6D);
DEFINE_GUID(IID_IObjectWithAssociationElement,0xE157C3A1,0xA532,0x4DE2,0x94, 0x80, 0x14, 0x52, 0xB7, 0x42, 0x6E, 0xEE);
DEFINE_GUID(IID_IObjectWithAssociationList,0xE6FFBB28, 0xBB79, 0x43B9, 0xA7, 0xBC, 0x6B, 0x57, 0x41, 0x0C, 0x81, 0x08);
DEFINE_GUID(IID_IObjectWithQuerySource,    0xB3DCB623, 0x4280, 0x4EB1, 0x84, 0xB3, 0x8D, 0x07, 0xE8, 0x4F, 0x29, 0x9A);
DEFINE_GUID(IID_IObjectWithSelection,      0x1C9CD5BB, 0x98E9, 0x4491, 0xA6, 0x0F, 0x31, 0xAA, 0xCC, 0x72, 0xB8, 0x3C);
DEFINE_GUID(IID_IPersistString2,           0x3C44BA76, 0xDE0E, 0x4049, 0xB6, 0xE4, 0x6B, 0x31, 0xA5, 0x26, 0x27, 0x07);
DEFINE_GUID(IID_IPrinterFolder,            0xEF99ABD4, 0x5B8D, 0x11D1, 0xA9, 0xC8, 0x00, 0x80, 0x36, 0xAF, 0x3F, 0x03);
DEFINE_GUID(IID_IPropertyControl,          0x5E82A4DD, 0x9561, 0x476A, 0x86, 0x34, 0x1B, 0xEB, 0xAC, 0xBA, 0x4A, 0x38);
DEFINE_GUID(IID_IPropertyControlBase,      0x6E71A510, 0x732A, 0x4557, 0x95, 0x96, 0xA8, 0x27, 0xE3, 0x6D, 0xAF, 0x8F);
DEFINE_GUID(IID_IPropertyControlSite,      0x61AD7F6B, 0xDD60, 0x4E95, 0xB7, 0x2B, 0xF2, 0xA2, 0x5C, 0x3A, 0xCF, 0xF6);
DEFINE_GUID(IID_IRegItemCustomAttributes,  0xD730309E, 0x9C53, 0x47B0, 0x93, 0x97, 0x9D, 0x85, 0x2C, 0xB7, 0x17, 0x45);
DEFINE_GUID(IID_IRegItemCustomEnumerator,  0x8DE4E39D, 0x921D, 0x410C, 0x84, 0x67, 0xD9, 0x92, 0xB8, 0x48, 0x9D, 0x72);
DEFINE_GUID(IID_IRegItemFolder,            0x81075FEB, 0x0A85, 0x439B, 0xB2, 0x5B, 0xE9, 0x53, 0x4A, 0xDF, 0x98, 0x11);
DEFINE_GUID(IID_IRootAndRelativeParsingFolder,0x52B14A6A,0x58F1,0x45BD,0xB0, 0x0A, 0xDC, 0xE7, 0x40, 0x3D, 0x95, 0x1E);
DEFINE_GUID(IID_IScope,                    0xDD8B42D6, 0x8162, 0x44B0, 0x8C, 0x27, 0x14, 0x71, 0x33, 0x18, 0xA0, 0xC6);
DEFINE_GUID(IID_IScopeItem,                0x0A4E5B7D, 0x99E1, 0x4700, 0x93, 0xB1, 0x89, 0x52, 0x5E, 0xAD, 0xD0, 0x90);
DEFINE_GUID(IID_IShellBrowserServce,       0xDFBC7E30, 0xF9E5, 0x455F, 0x88, 0xF8, 0xFA, 0x98, 0xC1, 0xE4, 0x94, 0xCA);
DEFINE_GUID(IID_IShellFolder3,             0x2EC06C64, 0x1296, 0x4F53, 0x89, 0xE5, 0xEC, 0xCE, 0x4E, 0xFC, 0x21, 0x89);
DEFINE_GUID(IID_ITaskCondition,            0x8419D6C6, 0x78C6, 0x4AAF, 0xB4, 0xEB, 0x29, 0x1B, 0x43, 0x37, 0x4A, 0xED);
DEFINE_GUID(IID_ITaskConditionCombiner,    0xD65AC459, 0x1187, 0x4C71, 0x88, 0x82, 0xDE, 0x09, 0x47, 0x23, 0x95, 0x29);
DEFINE_GUID(IID_ITaskConditionInit,        0xD2BF5114, 0x3F4B, 0x4A63, 0x87, 0x32, 0x67, 0x01, 0x85, 0x74, 0xB6, 0xB3);
DEFINE_GUID(IID_ITransferProvider,         0xF174B783, 0x3F7F, 0x4D97, 0x9F, 0x17, 0xEA, 0x82, 0xFE, 0xC9, 0x3B, 0x4A);
DEFINE_GUID(IID_IUserEventTimer,           0x0F504B94, 0x6E42, 0x42E6, 0x99, 0xE0, 0xE2, 0x0F, 0xAF, 0xE5, 0x2A, 0xB4);
DEFINE_GUID(IID_IUserEventTimerCallback,   0xE9EAD8E6, 0x2A25, 0x410E, 0x9B, 0x58, 0xA9, 0xFB, 0xEF, 0x1D, 0xD1, 0xA2);
DEFINE_GUID(IID_IAssociationArrayOld,      0x3B877E3C, 0x67DE, 0x4F9A, 0xB2, 0x9B, 0x17, 0xD0, 0xA1, 0x52, 0x1C, 0x6A); 	/*original*/
DEFINE_GUID(IID_IAssociationArray,         0x19ADBAFD, 0x1C5F, 0x4FC7, 0x94, 0xEE, 0x84, 0x67, 0x02, 0xDF, 0xB5, 0x8B); 	/*revised*/
DEFINE_GUID(IID_IDriveFolderExtOld,        0x98467961, 0x4F27, 0x4A1F, 0x96, 0x29, 0x22, 0xB0, 0x6D, 0x0B, 0x5C, 0xCB); 	/*Original*/
DEFINE_GUID(IID_IDriveFolderExt,           0x3EC36F3E, 0x5BA3, 0x4C3D, 0xBF, 0x39, 0x10, 0xF7, 0x6C, 0x3F, 0x7C, 0xC6); 	/*Revised*/
DEFINE_GUID(IID_IPinnedListOld,            0xC3C6EB6D, 0xC837, 0x4EAE, 0xB1, 0x72, 0x5F, 0xEC, 0x52, 0xA2, 0xA4, 0xFD); 	/*version 6.0*/
DEFINE_GUID(IID_IPinnedList,               0xBBD20037, 0xBC0E, 0x42F1, 0x91, 0x3F, 0xE2, 0x93, 0x6B, 0xB0, 0xEA, 0x0C); 	/*version 6.1*/

#define CGID_IExplorerToolbar IID_IExplorerToolbar
#define SID_IExplorerToolbar IID_IExplorerToolbar
#define SID_ITargetFrame2 IID_ITargetFrame2
#define SID_IWebBrowserApp IID_IWebBrowserApp
#define CGID_IDeskBand IID_IDeskBand
#define CGID_MenuBand CLSID_MenuBand

#define SID_STravelLogCursor IID_ITravelLogStg
#define SID_IBandSite IID_IBandSite
#define SID_IFolderView IID_IFolderView
#define SID_IShellBrowser IID_IShellBrowser

#endif // __SHLGUID_UNDOC_H
