/////////////////////////////////////////////////////////////////////////////
// Name:        snycentrydlg.cpp
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
#pragma implementation "snycentrydlg.h"
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

#include "snycentrydlg.h"


////@begin XPM images
////@end XPM images


/*!
 * SyncEntryDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SyncEntryDlg, wxDialog )


/*!
 * SyncEntryDlg event table definition
 */

BEGIN_EVENT_TABLE( SyncEntryDlg, wxDialog )

////@begin SyncEntryDlg event table entries
    EVT_BUTTON( ID_BITMAPBUTTON_CHOOSE_DIR1, SyncEntryDlg::OnBitmapbuttonChooseDir1Click )

    EVT_BUTTON( ID_BITMAPBUTTON_CHOOSE_DIR2, SyncEntryDlg::OnBitmapbuttonChooseDir2Click )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_BOTHDIRECTION, SyncEntryDlg::OnRadiobuttonBothdirectionSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_RIGHTDIRECTION, SyncEntryDlg::OnRadiobuttonRightdirectionSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_LEFTDIRECTION, SyncEntryDlg::OnRadiobuttonLeftdirectionSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_FILTER_OFF, SyncEntryDlg::OnRadiobuttonFilterOffSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_FILTER_ON, SyncEntryDlg::OnRadiobuttonFilterOnSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_FILTER_ONLY, SyncEntryDlg::OnRadiobuttonFilterOnlySelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_AUTO_OFF, SyncEntryDlg::OnRadiobuttonAutoOffSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_AUTO_EXACT, SyncEntryDlg::OnRadiobuttonAutoExactSelected )

    EVT_RADIOBUTTON( ID_RADIOBUTTON_AUTO_INTERVALL, SyncEntryDlg::OnRadiobuttonAutoIntervallSelected )

    EVT_BUTTON( ID_OKCHECK, SyncEntryDlg::OnOkcheckClick )

////@end SyncEntryDlg event table entries

END_EVENT_TABLE()


/*!
 * SyncEntryDlg constructors
 */

SyncEntryDlg::SyncEntryDlg()
{
    Init();
}

SyncEntryDlg::SyncEntryDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption,L"", pos, size, style);
}


/*!
 * SnycEntryDlg creator
 */

bool SyncEntryDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption,wxString APP_PATH, const wxPoint& pos, const wxSize& size, long style )
{
    APP_LOCATION = APP_PATH;
////@begin SyncEntryDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end SyncEntryDlg creation
    return true;
}


/*!
 * SyncEntryDlg destructor
 */

SyncEntryDlg::~SyncEntryDlg()
{
////@begin SyncEntryDlg destruction
////@end SyncEntryDlg destruction
}


/*!
 * Member initialisation
 */

void SyncEntryDlg::Init()
{
////@begin SyncEntryDlg member initialisation
    m_Dir1 = NULL;
    m_Dir2 = NULL;
    m_ClearTarged = NULL;
    m_HiddenFiles = NULL;
    m_NoTimeCheck = NULL;
    m_FilterString = NULL;
    m_Hour = NULL;
    m_Minute = NULL;
////@end SyncEntryDlg member initialisation
    Filtermode = 0;
    AutoSyncMode = 0;
}


/*!
 * Control creation for SnycEntryDlg
 */

void SyncEntryDlg::CreateControls()
{
////@begin SyncEntryDlg content construction
    SyncEntryDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Dir 1:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 7);

    m_Dir1 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_DIR1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(m_Dir1, 2, wxGROW|wxALL, 7);

    wxBitmapButton* itemBitmapButton6 = new wxBitmapButton( itemDialog1, ID_BITMAPBUTTON_CHOOSE_DIR1, itemDialog1->GetBitmapResource(wxT("recources/FolderOpen.png")), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    itemBoxSizer3->Add(itemBitmapButton6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer7, 0, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("Dir 2:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(itemStaticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 7);

    m_Dir2 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_DIR2, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_Dir2, 2, wxGROW|wxALL, 7);

    wxBitmapButton* itemBitmapButton10 = new wxBitmapButton( itemDialog1, ID_BITMAPBUTTON_CHOOSE_DIR2, itemDialog1->GetBitmapResource(wxT("recources/FolderOpen.png")), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    itemBoxSizer7->Add(itemBitmapButton10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer11Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Syncing Rules"));
    wxStaticBoxSizer* itemStaticBoxSizer11 = new wxStaticBoxSizer(itemStaticBoxSizer11Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer11, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer11->Add(itemBoxSizer12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxRadioButton* itemRadioButton13 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_BOTHDIRECTION, _("Dir1 <-> Dir 2"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    itemRadioButton13->SetValue(false);
    itemBoxSizer12->Add(itemRadioButton13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton14 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_RIGHTDIRECTION, _("Dir1 -> Dir2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton14->SetValue(false);
    itemBoxSizer12->Add(itemRadioButton14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton15 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_LEFTDIRECTION, _("Dir1 <- Dir2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton15->SetValue(false);
    itemBoxSizer12->Add(itemRadioButton15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ClearTarged = new wxCheckBox( itemDialog1, ID_CHECKBOX7, _("Delete old files in Targed Directory"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ClearTarged->SetValue(false);
    itemStaticBoxSizer11->Add(m_ClearTarged, 0, wxALIGN_LEFT|wxALL, 5);

    m_HiddenFiles = new wxCheckBox( itemDialog1, ID_CHECKBOX_HIDDENFILES, _("Sync Hidden Files"), wxDefaultPosition, wxDefaultSize, 0 );
    m_HiddenFiles->SetValue(true);
    itemStaticBoxSizer11->Add(m_HiddenFiles, 0, wxALIGN_LEFT|wxALL, 5);

    m_NoTimeCheck = new wxCheckBox( itemDialog1, ID_CHECKBOX9, _("Copy Files without comparing File Timestamps"), wxDefaultPosition, wxDefaultSize, 0 );
    m_NoTimeCheck->SetValue(false);
    itemStaticBoxSizer11->Add(m_NoTimeCheck, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer19Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Filters"));
    wxStaticBoxSizer* itemStaticBoxSizer19 = new wxStaticBoxSizer(itemStaticBoxSizer19Static, wxVERTICAL);
    itemStaticBoxSizer11->Add(itemStaticBoxSizer19, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer19->Add(itemBoxSizer20, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxRadioButton* itemRadioButton21 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_FILTER_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    itemRadioButton21->SetValue(true);
    itemBoxSizer20->Add(itemRadioButton21, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton22 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_FILTER_ON, _("Only File with"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton22->SetValue(false);
    itemBoxSizer20->Add(itemRadioButton22, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton23 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_FILTER_ONLY, _("No File with"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton23->SetValue(false);
    itemBoxSizer20->Add(itemRadioButton23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText24 = new wxStaticText( itemDialog1, wxID_STATIC, _("following filter words (seperated with ; semicolon  )"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer19->Add(itemStaticText24, 0, wxALIGN_LEFT|wxALL, 5);

    m_FilterString = new wxTextCtrl( itemDialog1, ID_TEXTCTRL3, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer19->Add(m_FilterString, 0, wxGROW|wxALL, 0);

    wxStaticBox* itemStaticBoxSizer26Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Automatic Syncing Shedule"));
    wxStaticBoxSizer* itemStaticBoxSizer26 = new wxStaticBoxSizer(itemStaticBoxSizer26Static, wxVERTICAL);
    itemStaticBoxSizer11->Add(itemStaticBoxSizer26, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer26->Add(itemBoxSizer27, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxRadioButton* itemRadioButton28 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_AUTO_OFF, _("Off"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
    itemRadioButton28->SetValue(true);
    itemBoxSizer27->Add(itemRadioButton28, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton29 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_AUTO_EXACT, _("Exact Time:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton29->SetValue(false);
    itemBoxSizer27->Add(itemRadioButton29, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxRadioButton* itemRadioButton30 = new wxRadioButton( itemDialog1, ID_RADIOBUTTON_AUTO_INTERVALL, _("Time Interval"), wxDefaultPosition, wxDefaultSize, 0 );
    itemRadioButton30->SetValue(false);
    itemBoxSizer27->Add(itemRadioButton30, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer26->Add(itemBoxSizer31, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxStaticText* itemStaticText32 = new wxStaticText( itemDialog1, wxID_STATIC, _("Hour:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer31->Add(itemStaticText32, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Hour = new wxSpinCtrl( itemDialog1, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(40, -1), wxSP_ARROW_KEYS, 0, 23, 0 );
    itemBoxSizer31->Add(m_Hour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText34 = new wxStaticText( itemDialog1, wxID_STATIC, _("Minute:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer31->Add(itemStaticText34, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Minute = new wxSpinCtrl( itemDialog1, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxSize(40, -1), wxSP_ARROW_KEYS, 0, 59, 0 );
    itemBoxSizer31->Add(m_Minute, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer36 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer36, 0, wxALIGN_RIGHT|wxALL, 0);

    wxButton* itemButton37 = new wxButton( itemDialog1, ID_OKCHECK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer36->Add(itemButton37, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton38 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer36->Add(itemButton38, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end SyncEntryDlg content construction

    m_Dir1->SetDropTarget(new DnDFile(m_Dir1));
    m_Dir2->SetDropTarget(new DnDFile(m_Dir2));

    FilterRadio[0] = itemRadioButton21;
    FilterRadio[1] = itemRadioButton23;
    FilterRadio[2] = itemRadioButton22;

    AutoRadio[0] = itemRadioButton28;
    AutoRadio[1] = itemRadioButton29;
    AutoRadio[2] = itemRadioButton30;

    DirectionRadio[0] = itemRadioButton13;
    DirectionRadio[1] = itemRadioButton14;
    DirectionRadio[2] = itemRadioButton15;

    SyncDirection = L"<->";
    m_ClearTarged->Enable(false);
    m_NoTimeCheck->Enable(false);
    DirectionRadio[0]->SetValue(true);

    SetFocus();

}

void SyncEntryDlg::RefreshCtrlState()
{
    m_ClearTarged->Enable(true);
    m_NoTimeCheck->Enable(true);

    FilterRadio[0]->SetValue(false);
    FilterRadio[Filtermode]->SetValue(true);

    AutoRadio[0]->SetValue(false);
    AutoRadio[AutoSyncMode]->SetValue(true);

    DirectionRadio[0]->SetValue(false);
    if( SyncDirection == L"<->" ) {
        DirectionRadio[0]->SetValue(true);
        m_ClearTarged->Enable(false);
        m_NoTimeCheck->Enable(false);
    }
    else if( SyncDirection == L"->" )
        DirectionRadio[1]->SetValue(true);
    else if( SyncDirection == L"<-" )
        DirectionRadio[2]->SetValue(true);
}


/*!
 * Should we show tooltips?
 */

bool SyncEntryDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap SyncEntryDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SyncEntryDlg bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("recources/FolderOpen.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/FolderOpen.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    return wxNullBitmap;
////@end SyncEntryDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon SyncEntryDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SyncEntryDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SyncEntryDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OKCHECK
 */

void SyncEntryDlg::OnOkcheckClick( wxCommandEvent& event )
{
    wxMessageDialog *Msg;
    if( m_Dir1->GetValue() == L"" || m_Dir2->GetValue() == L"")
    {
        Msg = new wxMessageDialog(this, _("Too less Syncing Diretorys!"),_("Too less Information"), wxOK );
        Msg->ShowModal();
        event.Skip();
    }
    else if( SyncDirection == L"")
    {
        Msg = new wxMessageDialog(this, _("Missing Sync Direction!"),_("Too less Information"), wxOK );
        Msg->ShowModal();
        event.Skip();
    }
    else if(Filtermode != 0 && m_FilterString->GetValue() == L"") {
        Msg = new wxMessageDialog(this, _("Missing Filter Words!"),_("Too less Information"), wxOK );
        Msg->ShowModal();
        event.Skip();
    }
    else if(AutoSyncMode == 2 && m_Hour->GetValue() == 0 && m_Minute->GetValue() == 0) {
        Msg = new wxMessageDialog(this, wxString(_("Time Interval of 0 Hours and 0 Minutes is not allowed! (Minimum is 1)")),_("Wrong Data"), wxOK );
        Msg->ShowModal();
        event.Skip();
    }
    else {
        //SetReturnCode(1);
        EndModal(1);
    }
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OKCHECK in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OKCHECK in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON1
 */

void SyncEntryDlg::OnRadiobuttonBothdirectionSelected( wxCommandEvent& event )
{
    SyncDirection= L"<->";
    m_ClearTarged->SetValue(false);
    m_ClearTarged->Enable(false);
    m_NoTimeCheck->SetValue(false);
    m_NoTimeCheck->Enable(false);
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON1 in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON1 in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_RIGHTDIRECTION
 */

void SyncEntryDlg::OnRadiobuttonRightdirectionSelected( wxCommandEvent& event )
{
    SyncDirection= L"->";
    m_ClearTarged->Enable(true);
    m_NoTimeCheck->Enable(true);
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_RIGHTDIRECTION in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_RIGHTDIRECTION in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_LEFTDIRECTION
 */

void SyncEntryDlg::OnRadiobuttonLeftdirectionSelected( wxCommandEvent& event )
{
    SyncDirection= L"<-";
    m_ClearTarged->Enable(true);
    m_NoTimeCheck->Enable(true);
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_LEFTDIRECTION in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_LEFTDIRECTION in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR1
 */

void SyncEntryDlg::OnBitmapbuttonChooseDir1Click( wxCommandEvent& event )
{
    wxDirDialog dir1(this,_("Choose the first Sync Directory"));
    if(dir1.ShowModal() == wxID_OK ) {
        m_Dir1->SetValue(dir1.GetPath());
    }
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR1 in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR1 in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR2
 */

void SyncEntryDlg::OnBitmapbuttonChooseDir2Click( wxCommandEvent& event )
{
    wxDirDialog dir2(this,_("Choose the second Sync Directory"));
    if(dir2.ShowModal() == wxID_OK ) {
        m_Dir2->SetValue(dir2.GetPath());
    }
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR2 in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR2 in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_OFF
 */

void SyncEntryDlg::OnRadiobuttonFilterOffSelected( wxCommandEvent& event )
{
    Filtermode = 0;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_OFF in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_OFF in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ON
 */

void SyncEntryDlg::OnRadiobuttonFilterOnSelected( wxCommandEvent& event )
{
    Filtermode = 2;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ON in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ON in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ONLY
 */

void SyncEntryDlg::OnRadiobuttonFilterOnlySelected( wxCommandEvent& event )
{
    Filtermode = 1;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ONLY in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ONLY in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_OFF
 */

void SyncEntryDlg::OnRadiobuttonAutoOffSelected( wxCommandEvent& event )
{
    AutoSyncMode = 0;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_OFF in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_OFF in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_EXACT
 */

void SyncEntryDlg::OnRadiobuttonAutoExactSelected( wxCommandEvent& event )
{
    AutoSyncMode = 1;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_EXACT in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_EXACT in SyncEntryDlg.
}


/*!
 * wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_INTERVALL
 */

void SyncEntryDlg::OnRadiobuttonAutoIntervallSelected( wxCommandEvent& event )
{
    AutoSyncMode = 2;
////@begin wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_INTERVALL in SyncEntryDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_INTERVALL in SyncEntryDlg.
}

