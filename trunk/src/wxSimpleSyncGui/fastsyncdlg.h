/////////////////////////////////////////////////////////////////////////////
// Name:        fastsyncdlg.h
// Purpose:
// Author:      BoscoWitch
// Modified by:
// Created:     18.2.2008 12:31:00
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _FASTSYNCDLG_H_
#define _FASTSYNCDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "fastsyncdlg.h"
#endif

/*!
 * Includes
 */



////@begin includes
////@end includes
#ifndef CSYNC
#define CSYNC
#include "../csync.h"
#endif
/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_FASTSYNCDLG 10057
#define ID_TEXTCTRL2_DIR1 10067
#define ID_BUTTON_RIGHT 10058
#define ID_BUTTON_LEFT 10062
#define ID_BUTTON_BOTH 10063
#define ID_TEXTCTRL2_DIR2 10064
#define ID_CHECKBOX 10000
#define ID_CHECKBOX1 10001
#define SYMBOL_FASTSYNCDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_FASTSYNCDLG_TITLE _("FastSyncDlg")
#define SYMBOL_FASTSYNCDLG_IDNAME ID_FASTSYNCDLG
#define SYMBOL_FASTSYNCDLG_SIZE wxSize(400, 300)
#define SYMBOL_FASTSYNCDLG_POSITION wxDefaultPosition
////@end control identifiers

/*
class DnDFileStatic : public wxFileDropTarget
{
public:
    DnDFileStatic(wxStaticText *pOwner) { m_pOwner = pOwner; }

    virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames) {
        size_t nFiles = filenames.GetCount();
        m_pOwner->SetLabel(filenames[0]);
        return true;
    }

private:
    wxStaticText *m_pOwner;
};*/

/*!
 * FastSyncDlg class declaration
 */

class FastSyncDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( FastSyncDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    FastSyncDlg();
    FastSyncDlg(wxWindow* parent, wxWindowID id = SYMBOL_FASTSYNCDLG_IDNAME, const wxString& caption = SYMBOL_FASTSYNCDLG_TITLE, const wxPoint& pos = SYMBOL_FASTSYNCDLG_POSITION, const wxSize& size = SYMBOL_FASTSYNCDLG_SIZE, long style = SYMBOL_FASTSYNCDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FASTSYNCDLG_IDNAME, const wxString& caption = SYMBOL_FASTSYNCDLG_TITLE, const wxPoint& pos = SYMBOL_FASTSYNCDLG_POSITION, const wxSize& size = SYMBOL_FASTSYNCDLG_SIZE, long style = SYMBOL_FASTSYNCDLG_STYLE );

    /// Destructor
    ~FastSyncDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin FastSyncDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RIGHT
    void OnButtonRightClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LEFT
    void OnButtonLeftClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BOTH
    void OnButtonBothClick( wxCommandEvent& event );

////@end FastSyncDlg event handler declarations

////@begin FastSyncDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end FastSyncDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin FastSyncDlg member variables
    wxTextCtrl* m_Dir1;
    wxTextCtrl* m_Dir2;
    wxCheckBox* m_ClearTarged;
    wxCheckBox* m_HiddenFiles;
////@end FastSyncDlg member variables
    CFolderSyncer* Sync;
};

#endif
    // _FASTSYNCDLG_H_
