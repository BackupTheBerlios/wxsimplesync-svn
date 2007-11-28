/////////////////////////////////////////////////////////////////////////////
// Name:        settingsdlg.h
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

#ifndef _SETTINGSDLG_H_
#define _SETTINGSDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "settingsdlg.h"
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
#define ID_SETTINGSDLG 10030
#define ID_HOWTOTRAY 10054
#define ID_STATUSBAR 10031
#define ID_PRIORITY 10032
#define ID_AUTOSYNC 10034
#define ID_AUTOOPENPROFIEL 10035
#define ID_ONTRAYSTART 10036
#define ID_LOGGINGON 10038
#define SYMBOL_SETTINGSDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_SETTINGSDLG_TITLE _("Settings")
#define SYMBOL_SETTINGSDLG_IDNAME ID_SETTINGSDLG
#define SYMBOL_SETTINGSDLG_SIZE wxSize(400, 300)
#define SYMBOL_SETTINGSDLG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * SettingsDlg class declaration
 */

class SettingsDlg: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( SettingsDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    SettingsDlg();
    SettingsDlg( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDLG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDLG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDLG_POSITION, const wxSize& size = SYMBOL_SETTINGSDLG_SIZE, long style = SYMBOL_SETTINGSDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDLG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDLG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDLG_POSITION, const wxSize& size = SYMBOL_SETTINGSDLG_SIZE, long style = SYMBOL_SETTINGSDLG_STYLE );

    /// Destructor
    ~SettingsDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin SettingsDlg event handler declarations

////@end SettingsDlg event handler declarations

////@begin SettingsDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end SettingsDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin SettingsDlg member variables
    wxChoice* m_InTrayDrop;
    wxCheckBox* m_ShowStatus;
    wxChoice* m_Priority;
    wxCheckBox* m_AutoSync;
    wxCheckBox* m_LastProfile;
    wxCheckBox* m_StartasTray;
    wxCheckBox* m_WriteLog;
////@end SettingsDlg member variables
};

#endif
    // _SETTINGSDLG_H_
