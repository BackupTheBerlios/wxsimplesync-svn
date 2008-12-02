/////////////////////////////////////////////////////////////////////////////
// Name:        profiledlg.cpp
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
#pragma implementation "profiledlg.h"
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

#include "profiledlg.h"

////@begin XPM images
////@end XPM images


/*!
 * ProfileDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ProfileDlg, wxDialog )


/*!
 * ProfileDlg event table definition
 */

BEGIN_EVENT_TABLE( ProfileDlg, wxDialog )

////@begin ProfileDlg event table entries
    EVT_BUTTON( ID_CHECKCLOSE, ProfileDlg::OnCheckcloseClick )

////@end ProfileDlg event table entries

END_EVENT_TABLE()


/*!
 * ProfileDlg constructors
 */

ProfileDlg::ProfileDlg()
{
    Init();
}

ProfileDlg::ProfileDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * ProfileDlg creator
 */

bool ProfileDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ProfileDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end ProfileDlg creation
    return true;
}


/*!
 * ProfileDlg destructor
 */

ProfileDlg::~ProfileDlg()
{
////@begin ProfileDlg destruction
////@end ProfileDlg destruction
}


/*!
 * Member initialisation
 */

void ProfileDlg::Init()
{
////@begin ProfileDlg member initialisation
    m_ProfileName = NULL;
////@end ProfileDlg member initialisation
}


/*!
 * Control creation for ProfileDlg
 */

void ProfileDlg::CreateControls()
{
////@begin ProfileDlg content construction
    ProfileDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Profile Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ProfileName = new wxTextCtrl( itemDialog1, ID_PROFILENAMETEXTFIELD, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(m_ProfileName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer6, 0, wxALIGN_RIGHT|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, ID_CHECKCLOSE, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemButton7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, wxID_CANCEL, _("&Abbrechen"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end ProfileDlg content construction
    SetFocus();
}


/*!
 * Should we show tooltips?
 */

bool ProfileDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ProfileDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ProfileDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ProfileDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ProfileDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ProfileDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ProfileDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void ProfileDlg::OnCheckcloseClick( wxCommandEvent& event )
{
    if(!m_ProfileName->IsModified()) {
        wxMessageDialog dlg(this, _("Missing Profile Name!"), _("Profile Error"), wxICON_EXCLAMATION);
        dlg.ShowModal();
    }
    else {
        EndModal(1);
    }
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in ProfileDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in ProfileDlg.
}

