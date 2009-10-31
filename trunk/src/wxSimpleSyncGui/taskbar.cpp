/////////////////////////////////////////////////////////////////////////////
// Name:        taskbar.cpp
// Purpose:
// Author:      Pascal Schnurr aka BoscoWitch
// Modified by:
// Created:     24.6.2007 05:20:26
// RCS-ID:
// Copyright: (c) 2007 by Pascal Schnurr aka BoscoWitch
// Licence:
/*   This file is part of wxSimpleSync.

    wxSimpleSync is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    wxSimpleSync is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with wxSimpleSync.  If not, see <http://www.gnu.org/licenses/>.
*//////////////////////////////////////////////////////////////////////////////

#include "simplesyncdlg.h"



IMPLEMENT_DYNAMIC_CLASS( COwnTaskBar , wxTaskBarIcon )

enum {
    PU_RESTORE = 19001,
    PU_SYNCMENU,
    PU_EXIT,
    PU_SYNCENTRYS_START,
    PU_SYNCENTRYS_MAX = 29000
};
BEGIN_EVENT_TABLE( COwnTaskBar , wxTaskBarIcon )

    EVT_TASKBAR_LEFT_DCLICK( COwnTaskBar::OnTaskIconDClick )
    EVT_MENU(PU_RESTORE, COwnTaskBar::OnRestore )
    EVT_MENU( PU_EXIT , COwnTaskBar::OnExit)
    EVT_UPDATE_UI(PU_SYNCMENU, COwnTaskBar::OnMenuUISyncMenu)
    EVT_MENU_RANGE(PU_SYNCENTRYS_START,PU_SYNCENTRYS_MAX,COwnTaskBar::OnSync)

END_EVENT_TABLE()

wxMenu *COwnTaskBar::CreatePopupMenu()
{
    // Try creating menus different ways
    // TODO: Probably try calling SetBitmap with some XPMs here
    wxMenu *menu = new wxMenu;
    menu->Append(PU_RESTORE, _("&Restore wxSS"));

    submenu = new wxMenu;
    menu->Append(PU_SYNCMENU, _("Sync Entry"), submenu);

#ifndef __WXMAC_OSX__ /*Mac has built-in quit menu*/
    menu->AppendSeparator();
    menu->Append(PU_EXIT,    _("E&xit"));
#endif
    return menu;
}

void  COwnTaskBar::OnTaskIconDClick(wxTaskBarIconEvent &event) {
    inTaskBar = false;
    MainWindow->Show(!inTaskBar);
    MainWindow->Iconize(inTaskBar);
    RemoveIcon();
}

void COwnTaskBar::MinimizeInTaskBar()
{
    wxIcon icon(APP_LOCATION + _T("recources/mainicon.png"), wxBITMAP_TYPE_PNG);
    SetIcon(icon,wxT("wxSimpleSync"));
    inTaskBar = true;
    MainWindow->Show(!inTaskBar);
}

void COwnTaskBar::OnRestore(wxCommandEvent&) {
    inTaskBar = false;
    MainWindow->Show(!inTaskBar);
    MainWindow->Iconize(inTaskBar);
    RemoveIcon();
}
void COwnTaskBar::OnMenuUISyncMenu(wxUpdateUIEvent &event) {
    for(int i=0; i<MainWindow->Sync->SyncList.GetCount(); i++) {
        submenu->Append(PU_SYNCENTRYS_START + i, wxString::Format(L"%i ",i+1) + MainWindow->Sync->SyncList[i].dir1 + MainWindow->Sync->SyncList[i].direction + MainWindow->Sync->SyncList[i].dir2);
    }
}

void COwnTaskBar::OnExit(wxCommandEvent&) {
    MainWindow->Close();
}

void COwnTaskBar::OnSync(wxCommandEvent& ev) {
    int list_index = ev.GetId() - PU_SYNCENTRYS_START;
    MainWindow->Sync->SyncEntry(list_index);
}
