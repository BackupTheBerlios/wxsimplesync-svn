/////////////////////////////////////////////////////////////////////////////
// Name:        snycentrydlg.h
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

#ifndef _SNYCENTRYDLG_H_
#define _SNYCENTRYDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "snycentrydlg.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/spinctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_SNYCENTRYDLG 10022
#define ID_TEXTCTRL_DIR1 10023
#define ID_BITMAPBUTTON_CHOOSE_DIR1 10024
#define ID_TEXTCTRL_DIR2 10025
#define ID_BITMAPBUTTON_CHOOSE_DIR2 10026
#define ID_RADIOBUTTON_BOTHDIRECTION 10027
#define ID_RADIOBUTTON_RIGHTDIRECTION 10028
#define ID_RADIOBUTTON_LEFTDIRECTION 10029
#define ID_CHECKBOX7 10041
#define ID_CHECKBOX_HIDDENFILES 10042
#define ID_CHECKBOX9 10043
#define ID_RADIOBUTTON_FILTER_OFF 10039
#define ID_RADIOBUTTON_FILTER_ON 10040
#define ID_RADIOBUTTON_FILTER_ONLY 10044
#define ID_TEXTCTRL3 10045
#define ID_RADIOBUTTON_AUTO_OFF 10046
#define ID_RADIOBUTTON_AUTO_EXACT 10047
#define ID_RADIOBUTTON_AUTO_INTERVALL 10048
#define ID_SPINCTRL1 10051
#define ID_SPINCTRL2 10049
#define ID_OKCHECK 10042
#define SYMBOL_SYNCENTRYDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_SYNCENTRYDLG_TITLE _("SyncEntryDlg")
#define SYMBOL_SYNCENTRYDLG_IDNAME ID_SNYCENTRYDLG
#define SYMBOL_SYNCENTRYDLG_SIZE wxSize(400, 300)
#define SYMBOL_SYNCENTRYDLG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * SyncEntryDlg class declaration
 */

class SyncEntryDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( SyncEntryDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    SyncEntryDlg();
    SyncEntryDlg( wxWindow* parent, wxWindowID id = SYMBOL_SYNCENTRYDLG_IDNAME, const wxString& caption = SYMBOL_SYNCENTRYDLG_TITLE, const wxPoint& pos = SYMBOL_SYNCENTRYDLG_POSITION, const wxSize& size = SYMBOL_SYNCENTRYDLG_SIZE, long style = SYMBOL_SYNCENTRYDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SYNCENTRYDLG_IDNAME, const wxString& caption = SYMBOL_SYNCENTRYDLG_TITLE, const wxPoint& pos = SYMBOL_SYNCENTRYDLG_POSITION, const wxSize& size = SYMBOL_SYNCENTRYDLG_SIZE, long style = SYMBOL_SYNCENTRYDLG_STYLE );

    /// Destructor
    ~SyncEntryDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin SyncEntryDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR1
    void OnBitmapbuttonChooseDir1Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_CHOOSE_DIR2
    void OnBitmapbuttonChooseDir2Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_BOTHDIRECTION
    void OnRadiobuttonBothdirectionSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_RIGHTDIRECTION
    void OnRadiobuttonRightdirectionSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_LEFTDIRECTION
    void OnRadiobuttonLeftdirectionSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_OFF
    void OnRadiobuttonFilterOffSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ON
    void OnRadiobuttonFilterOnSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_FILTER_ONLY
    void OnRadiobuttonFilterOnlySelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_OFF
    void OnRadiobuttonAutoOffSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_EXACT
    void OnRadiobuttonAutoExactSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBUTTON_SELECTED event handler for ID_RADIOBUTTON_AUTO_INTERVALL
    void OnRadiobuttonAutoIntervallSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OKCHECK
    void OnOkcheckClick( wxCommandEvent& event );

////@end SyncEntryDlg event handler declarations

////@begin SyncEntryDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end SyncEntryDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin SyncEntryDlg member variables
    wxTextCtrl* m_Dir1;
    wxTextCtrl* m_Dir2;
    wxCheckBox* m_ClearTarged;
    wxCheckBox* m_HiddenFiles;
    wxCheckBox* m_NoTimeCheck;
    wxTextCtrl* m_FilterString;
    wxSpinCtrl* m_Hour;
    wxSpinCtrl* m_Minute;
////@end SyncEntryDlg member variables

    wxString SyncDirection;
    int Filtermode;
    int AutoSyncMode;
    wxRadioButton *AutoRadio[3];
    wxRadioButton *FilterRadio[3];
    wxRadioButton *DirectionRadio[3];
    bool NewEntry;

    void RefreshCtrlState();
};

#endif
    // _SNYCENTRYDLG_H_
