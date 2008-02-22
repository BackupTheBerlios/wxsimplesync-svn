/////////////////////////////////////////////////////////////////////////////
// Name:        fastsyncdlg.cpp
// Purpose:
// Author:      BoscoWitch
// Modified by:
// Created:     18.2.2008 12:31:00
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "fastsyncdlg.h"
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

#include "fastsyncdlg.h"

////@begin XPM images
////@end XPM images


/*!
 * FastSyncDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( FastSyncDlg, wxDialog )


/*!
 * FastSyncDlg event table definition
 */

BEGIN_EVENT_TABLE( FastSyncDlg, wxDialog )

////@begin FastSyncDlg event table entries
    EVT_BUTTON( ID_BUTTON_RIGHT, FastSyncDlg::OnButtonRightClick )

    EVT_BUTTON( ID_BUTTON_LEFT, FastSyncDlg::OnButtonLeftClick )

    EVT_BUTTON( ID_BUTTON_BOTH, FastSyncDlg::OnButtonBothClick )

////@end FastSyncDlg event table entries

END_EVENT_TABLE()


/*!
 * FastSyncDlg constructors
 */

FastSyncDlg::FastSyncDlg()
{
    Init();
}

FastSyncDlg::FastSyncDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * FastSyncDlg creator
 */

bool FastSyncDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin FastSyncDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end FastSyncDlg creation
    return true;
}


/*!
 * FastSyncDlg destructor
 */

FastSyncDlg::~FastSyncDlg()
{
////@begin FastSyncDlg destruction
////@end FastSyncDlg destruction
}


/*!
 * Member initialisation
 */

void FastSyncDlg::Init()
{
////@begin FastSyncDlg member initialisation
    m_Dir1 = NULL;
    m_Dir2 = NULL;
    m_ClearTarged = NULL;
    m_HiddenFiles = NULL;
////@end FastSyncDlg member initialisation
}


/*!
 * Control creation for FastSyncDlg
 */

void FastSyncDlg::CreateControls()
{
////@begin FastSyncDlg content construction
    FastSyncDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_Dir1 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL2_DIR1, _("Drop Dir1 here"), wxDefaultPosition, wxSize(100, 75), wxTE_MULTILINE );
    itemBoxSizer3->Add(m_Dir1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton6 = new wxButton( itemDialog1, ID_BUTTON_RIGHT, _("->"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, ID_BUTTON_LEFT, _("<-"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, ID_BUTTON_BOTH, _("<->"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_Dir2 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL2_DIR2, _("Drop Dir2 here"), wxDefaultPosition, wxSize(100, 75), wxTE_MULTILINE );
    itemBoxSizer3->Add(m_Dir2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText10 = new wxStaticText( itemDialog1, wxID_STATIC, _("Drag the folders you want so sync onto the textfields for Dir 1 and 2 and click an direction button  to start the Syncing."), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText10->Wrap(300);
    itemBoxSizer2->Add(itemStaticText10, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer11 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_ClearTarged = new wxCheckBox( itemDialog1, ID_CHECKBOX, _("Delete old files in Targed Directory"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ClearTarged->SetValue(true);
    itemBoxSizer11->Add(m_ClearTarged, 0, wxALIGN_LEFT|wxALL, 5);

    m_HiddenFiles = new wxCheckBox( itemDialog1, ID_CHECKBOX1, _("Sync Hidden Files"), wxDefaultPosition, wxDefaultSize, 0 );
    m_HiddenFiles->SetValue(true);
    itemBoxSizer11->Add(m_HiddenFiles, 0, wxALIGN_LEFT|wxALL, 5);

////@end FastSyncDlg content construction
    m_Dir1->SetDropTarget(new DnDFile(m_Dir1));
    m_Dir2->SetDropTarget(new DnDFile(m_Dir2));
}


/*!
 * Should we show tooltips?
 */

bool FastSyncDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap FastSyncDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin FastSyncDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end FastSyncDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon FastSyncDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin FastSyncDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end FastSyncDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RIGHT
 */

void FastSyncDlg::OnButtonRightClick( wxCommandEvent& event )
{
    Sync->SyncPath(wxT("->"),m_Dir1->GetValue(),m_Dir2->GetValue(),m_HiddenFiles->GetValue(),m_ClearTarged->GetValue());
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RIGHT in FastSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RIGHT in FastSyncDlg.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LEFT
 */

void FastSyncDlg::OnButtonLeftClick( wxCommandEvent& event )
{
    Sync->SyncPath(wxT("<-"),m_Dir1->GetValue(),m_Dir2->GetValue(),m_HiddenFiles->GetValue(),m_ClearTarged->GetValue());
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LEFT in FastSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LEFT in FastSyncDlg.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BOTH
 */

void FastSyncDlg::OnButtonBothClick( wxCommandEvent& event )
{
    Sync->SyncPath(wxT("<->"),m_Dir1->GetValue(),m_Dir2->GetValue(),m_HiddenFiles->GetValue(),false);
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BOTH in FastSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BOTH in FastSyncDlg.
}

