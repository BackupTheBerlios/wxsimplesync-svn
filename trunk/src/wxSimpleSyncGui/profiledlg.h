/////////////////////////////////////////////////////////////////////////////
// Name:        profiledlg.h
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

#ifndef _PROFILEDLG_H_
#define _PROFILEDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "profiledlg.h"
#endif

/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_PROFILEDLG 10050
#define ID_PROFILENAMETEXTFIELD 10052
#define ID_CHECKCLOSE 10052
#define SYMBOL_PROFILEDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_PROFILEDLG_TITLE _("Profile")
#define SYMBOL_PROFILEDLG_IDNAME ID_PROFILEDLG
#define SYMBOL_PROFILEDLG_SIZE wxSize(400, 300)
#define SYMBOL_PROFILEDLG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * ProfileDlg class declaration
 */

class ProfileDlg: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( ProfileDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ProfileDlg();
    ProfileDlg( wxWindow* parent, wxWindowID id = SYMBOL_PROFILEDLG_IDNAME, const wxString& caption = SYMBOL_PROFILEDLG_TITLE, const wxPoint& pos = SYMBOL_PROFILEDLG_POSITION, const wxSize& size = SYMBOL_PROFILEDLG_SIZE, long style = SYMBOL_PROFILEDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PROFILEDLG_IDNAME, const wxString& caption = SYMBOL_PROFILEDLG_TITLE, const wxPoint& pos = SYMBOL_PROFILEDLG_POSITION, const wxSize& size = SYMBOL_PROFILEDLG_SIZE, long style = SYMBOL_PROFILEDLG_STYLE );

    /// Destructor
    ~ProfileDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin ProfileDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CHECKCLOSE
    void OnCheckcloseClick( wxCommandEvent& event );

////@end ProfileDlg event handler declarations

////@begin ProfileDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ProfileDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ProfileDlg member variables
    wxTextCtrl* m_ProfileName;
////@end ProfileDlg member variables
};

#endif
    // _PROFILEDLG_H_
