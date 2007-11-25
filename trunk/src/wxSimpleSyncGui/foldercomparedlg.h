/////////////////////////////////////////////////////////////////////////////
// Name:        foldercomparedlg.h
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

#ifndef _FOLDERCOMPAREDLG_H_
#define _FOLDERCOMPAREDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "foldercomparedlg.h"
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
#define ID_FOLDERCOMPAREDLG 10055
#define ID_BUTTON_COMPARE 10056
#define ID_TEXTCTRL1 10060
#define ID_TEXTCTRL2 10061
#define SYMBOL_FOLDERCOMPAREDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_FOLDERCOMPAREDLG_TITLE _("Compare Folders")
#define SYMBOL_FOLDERCOMPAREDLG_IDNAME ID_FOLDERCOMPAREDLG
#define SYMBOL_FOLDERCOMPAREDLG_SIZE wxSize(500, 600)
#define SYMBOL_FOLDERCOMPAREDLG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * FolderCompareDlg class declaration
 */

class FolderCompareDlg: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( FolderCompareDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    FolderCompareDlg();
    FolderCompareDlg( wxWindow* parent, wxWindowID id = SYMBOL_FOLDERCOMPAREDLG_IDNAME, const wxString& caption = SYMBOL_FOLDERCOMPAREDLG_TITLE, const wxPoint& pos = SYMBOL_FOLDERCOMPAREDLG_POSITION, const wxSize& size = SYMBOL_FOLDERCOMPAREDLG_SIZE, long style = SYMBOL_FOLDERCOMPAREDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FOLDERCOMPAREDLG_IDNAME, const wxString& caption = SYMBOL_FOLDERCOMPAREDLG_TITLE, const wxPoint& pos = SYMBOL_FOLDERCOMPAREDLG_POSITION, const wxSize& size = SYMBOL_FOLDERCOMPAREDLG_SIZE, long style = SYMBOL_FOLDERCOMPAREDLG_STYLE );

    /// Destructor
    ~FolderCompareDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin FolderCompareDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_COMPARE
    void OnButtonCompareClick( wxCommandEvent& event );

////@end FolderCompareDlg event handler declarations

////@begin FolderCompareDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end FolderCompareDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin FolderCompareDlg member variables
    wxTextCtrl* m_dir1;
    wxTextCtrl* m_dir2;
////@end FolderCompareDlg member variables
    
    void CompareFolders();
    void CompareFoldersR(wxString folder, wxString Dir_1,wxString Dir_2, wxString direction);

    
    wxString Dir1,Dir2;
};

#endif
    // _FOLDERCOMPAREDLG_H_
