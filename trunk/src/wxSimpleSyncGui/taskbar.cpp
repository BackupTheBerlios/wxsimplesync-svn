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
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*//////////////////////////////////////////////////////////////////////////////

#include "simplesyncdlg.h"

IMPLEMENT_DYNAMIC_CLASS( COwnTaskBar , wxTaskBarIcon )


BEGIN_EVENT_TABLE( COwnTaskBar , wxTaskBarIcon )

    EVT_TASKBAR_LEFT_DCLICK( COwnTaskBar::OnTaskIconDClick )

END_EVENT_TABLE()


void  COwnTaskBar ::OnTaskIconDClick(wxTaskBarIconEvent &event) {
    inTaskBar = false;
    MainWindow->Show(!inTaskBar);
    MainWindow->Iconize(inTaskBar);
    RemoveIcon();
}

void COwnTaskBar ::MinimizeInTaskBar()
{
    wxIcon icon(_T("recources/mainicon.png"), wxBITMAP_TYPE_PNG);
    SetIcon(icon,wxT("wxSimpleSync"));
    inTaskBar = true;
    MainWindow->Show(!inTaskBar);
}
