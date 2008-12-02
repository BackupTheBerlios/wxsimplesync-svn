/////////////////////////////////////////////////////////////////////////////
// Name:        settingsdlg.cpp
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

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "settingsdlg.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "settingsdlg.h"

////@begin XPM images
////@end XPM images


/*!
 * SettingsDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SettingsDlg, wxDialog )


/*!
 * SettingsDlg event table definition
 */

BEGIN_EVENT_TABLE( SettingsDlg, wxDialog )

////@begin SettingsDlg event table entries
////@end SettingsDlg event table entries

END_EVENT_TABLE()


/*!
 * SettingsDlg constructors
 */

SettingsDlg::SettingsDlg()
{
    Init();
}

SettingsDlg::SettingsDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * SettingsDlg creator
 */

bool SettingsDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin SettingsDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end SettingsDlg creation
    return true;
}


/*!
 * SettingsDlg destructor
 */

SettingsDlg::~SettingsDlg()
{
////@begin SettingsDlg destruction
////@end SettingsDlg destruction
}


/*!
 * Member initialisation
 */

void SettingsDlg::Init()
{
////@begin SettingsDlg member initialisation
    m_InTrayDrop = NULL;
    m_ShowStatus = NULL;
    m_Priority = NULL;
    m_AutoSync = NULL;
    m_LastProfile = NULL;
    m_StartasTray = NULL;
    m_WriteLog = NULL;
////@end SettingsDlg member initialisation
}


/*!
 * Control creation for SettingsDlg
 */

void SettingsDlg::CreateControls()
{
////@begin SettingsDlg content construction
    SettingsDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Gui"));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText5 = new wxStaticText( itemDialog1, wxID_STATIC, _("Minimize in Tray by:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_InTrayDropStrings;
    m_InTrayDropStrings.Add(_("Minimizing"));
    m_InTrayDropStrings.Add(_("Closing"));
    m_InTrayDropStrings.Add(_("Nothing"));
    m_InTrayDrop = new wxChoice( itemDialog1, ID_HOWTOTRAY, wxDefaultPosition, wxDefaultSize, m_InTrayDropStrings, 0 );
    itemBoxSizer4->Add(m_InTrayDrop, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer3->Add(itemBoxSizer7, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("Show Statusbar:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(itemStaticText8, 2, wxGROW|wxALL, 5);

    m_ShowStatus = new wxCheckBox( itemDialog1, ID_STATUSBAR, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowStatus->SetValue(false);
    itemBoxSizer7->Add(m_ShowStatus, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer10Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Functionality"));
    wxStaticBoxSizer* itemStaticBoxSizer10 = new wxStaticBoxSizer(itemStaticBoxSizer10Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer10, 0, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer10->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer11->Add(itemBoxSizer12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxStaticText* itemStaticText13 = new wxStaticText( itemDialog1, wxID_STATIC, _("Priority of the Snyc Process"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(itemStaticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_PriorityStrings;
    m_PriorityStrings.Add(_("High"));
    m_PriorityStrings.Add(_("Normal"));
    m_PriorityStrings.Add(_("Lower as Normal"));
    m_PriorityStrings.Add(_("Idle"));
    m_Priority = new wxChoice( itemDialog1, ID_PRIORITY, wxDefaultPosition, wxDefaultSize, m_PriorityStrings, 0 );
    itemBoxSizer12->Add(m_Priority, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer11->Add(itemBoxSizer15, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    itemBoxSizer15->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 40);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer15->Add(itemBoxSizer17, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    m_AutoSync = new wxCheckBox( itemDialog1, ID_AUTOSYNC, _("AutoSync Active at Start"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AutoSync->SetValue(false);
    itemBoxSizer17->Add(m_AutoSync, 0, wxALIGN_LEFT|wxALL, 5);

    m_LastProfile = new wxCheckBox( itemDialog1, ID_AUTOOPENPROFIEL, _("Open last Profile Automatically"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LastProfile->SetValue(false);
    itemBoxSizer17->Add(m_LastProfile, 0, wxALIGN_LEFT|wxALL, 5);

    m_StartasTray = new wxCheckBox( itemDialog1, ID_ONTRAYSTART, _("Minimize in Tray at Start"), wxDefaultPosition, wxDefaultSize, 0 );
    m_StartasTray->SetValue(false);
    itemBoxSizer17->Add(m_StartasTray, 0, wxALIGN_LEFT|wxALL, 5);

    m_WriteLog = new wxCheckBox( itemDialog1, ID_LOGGINGON, _("Write Logfile \"log.txt\""), wxDefaultPosition, wxDefaultSize, 0 );
    m_WriteLog->SetValue(false);
    itemBoxSizer17->Add(m_WriteLog, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer22, 0, wxALIGN_RIGHT|wxALL, 0);

    wxButton* itemButton23 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer22->Add(itemButton23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton24 = new wxButton( itemDialog1, wxID_CANCEL, _("&Abbrechen"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer22->Add(itemButton24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end SettingsDlg content construction

    SetFocus();
}


/*!
 * Should we show tooltips?
 */

bool SettingsDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap SettingsDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SettingsDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end SettingsDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon SettingsDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SettingsDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SettingsDlg icon retrieval
}



