/////////////////////////////////////////////////////////////////////////////
// Name:        simplesyncdlg.cpp
// Purpose:     Implement Main Dialog Functions
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

// Generated by DialogBlocks (Personal Edition), 24.6.2007 05:20:26

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "simplesyncdlg.h"
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

#include "simplesyncdlg.h"

////@begin XPM images
////@end XPM images

#include <wx/aboutdlg.h>




/*!
 * SimpleSyncDlg type definition
 */

IMPLEMENT_CLASS( SimpleSyncDlg, wxFrame )


/*!
 * SimpleSyncDlg event table definition
 */

BEGIN_EVENT_TABLE( SimpleSyncDlg, wxFrame )

////@begin SimpleSyncDlg event table entries
    EVT_CLOSE( SimpleSyncDlg::OnCloseWindow )
    EVT_ICONIZE( SimpleSyncDlg::OnIconize )
    EVT_MAXIMIZE( SimpleSyncDlg::OnMaximize )
    EVT_SIZE( SimpleSyncDlg::OnSize )
    EVT_PAINT( SimpleSyncDlg::OnPaint )

    EVT_MENU( ID_MENUITEM_NEW_PROFILE, SimpleSyncDlg::OnMenuitemNewProfileClick )

    EVT_MENU( ID_MENUITEM_EDIT_PROFILE, SimpleSyncDlg::OnMenuEditProfileClick )

    EVT_MENU( ID_MENUITEM_OPEN_PROFILE, SimpleSyncDlg::OnMenuitemOpenProfileClick )

    EVT_MENU( ID_MENUITEM_SAVE_PROFILE, SimpleSyncDlg::OnMenuitemSaveProfileClick )

    EVT_MENU( ID_MENUITEM_SAVE_PROFILE_AS, SimpleSyncDlg::OnMenuitemSaveProfileAsClick )

    EVT_MENU( ID_MENUITEM_SETTINGS, SimpleSyncDlg::OnMenuitemSettingsClick )

    EVT_MENU( ID_MENUITEM_EXIT, SimpleSyncDlg::OnMenuitemExitClick )

    EVT_MENU( ID_MENUITEM_ADD_SYNC_ENTRY, SimpleSyncDlg::OnMenuitemAddSyncEntryClick )

    EVT_MENU( ID_MENUITEM, SimpleSyncDlg::OnMenuEditEntryClick )

    EVT_MENU( ID_MENUITEM_START_SYNC, SimpleSyncDlg::OnMenuitemStartSyncClick )

    EVT_MENU( ID_MENUITEM_SYNC_SELECTED, SimpleSyncDlg::OnMenuitemSyncSelectedClick )

    EVT_MENU( ID_MENUITEM_CANCEL_SYNC, SimpleSyncDlg::OnMenuitemCancelSyncClick )

    EVT_MENU( ID_MENUITEM_AKTIVATE_AUTOSYNC, SimpleSyncDlg::OnMenuitemAktivateAutosyncClick )

    EVT_MENU( ID_MENUITEM_DEAKTIVATE_AUTOSYNC, SimpleSyncDlg::OnMenuitemDeaktivateAutosyncClick )

    EVT_MENU( ID_MENUITEM_COMPARE_FOLDERS, SimpleSyncDlg::OnMenuitemCompareFoldersClick )

    EVT_MENU( ID_MENUITEM_FASTSYNCDLG, SimpleSyncDlg::OnMenuitemFastsyncdlgClick )

    EVT_MENU( ID_MENUITEM12, SimpleSyncDlg::OnMenuInfo12Click )

    EVT_MENU( ID_TOOL_ADD, SimpleSyncDlg::OnToolAddClick )

    EVT_MENU( ID_TOOL_REMOVE, SimpleSyncDlg::OnToolRemoveClick )

    EVT_MENU( ID_TOOL_MOVE_UP, SimpleSyncDlg::OnToolMoveUpClick )

    EVT_MENU( ID_TOOL_MOVE_DOWN, SimpleSyncDlg::OnToolMoveDownClick )

    EVT_MENU( ID_TOOL_SYNC_ALL, SimpleSyncDlg::OnToolSyncAllClick )

    EVT_MENU( ID_TOOL_ABORT_SYNC, SimpleSyncDlg::OnToolAbortSyncClick )

    EVT_LIST_ITEM_SELECTED( ID_SYNC_LISTCTRL, SimpleSyncDlg::OnSyncListctrlSelected )
    EVT_LIST_ITEM_ACTIVATED( ID_SYNC_LISTCTRL, SimpleSyncDlg::OnLeftDClick )

////@end SimpleSyncDlg event table entries

END_EVENT_TABLE()


/*!
 * SimpleSyncDlg constructors
 */

SimpleSyncDlg::SimpleSyncDlg()
{
    Init();
}

SimpleSyncDlg::SimpleSyncDlg( wxWindow* parent, wxWindowID id, wxString ShellProfile,wxString LOCATION, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    APP_LOCATION = LOCATION;
    ShellProfileParameter = false;
    if(ShellProfile != wxT("")) {
        ShellProfilePath = ShellProfile;
        ShellProfileParameter = true;
    }
    Taskbar = true;
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*!
 * SimpleSyncDlg creator
 */

bool SimpleSyncDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin SimpleSyncDlg creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("recources/main.ico")));
    Centre();
////@end SimpleSyncDlg creation
     return true;
}


/*!
 * SimpleSyncDlg destructor
 */

SimpleSyncDlg::~SimpleSyncDlg()
{
////@begin SimpleSyncDlg destruction
////@end SimpleSyncDlg destruction
}


/*!
 * Member initialisation
 */

void SimpleSyncDlg::Init()
{
////@begin SimpleSyncDlg member initialisation
    m_StatusBar = NULL;
    m_Toolbar = NULL;
    m_ListCtrl = NULL;
////@end SimpleSyncDlg member initialisation
    logger = new CLogging(APP_LOCATION + wxT("log.txt"));
	Sync = new CFolderSyncer(logger,this);
	wxLog::SetActiveTarget(logger);
	Tray = new COwnTaskBar();
	Tray->SetWindow(this);
	second = 0;
	if(!Sync->OpenSettings(APP_LOCATION + wxT("wxSimpleSyncSettings.xml"))) {
	    logger->LogMessage(_("Could not Load Setting file wxSimpleSyncSettings.xml taking default settings"));
	    Sync->Settings.AutoOpenProfile = false;
	    Sync->Settings.AutoSync = true;
	    Sync->Settings.InTray = Tray::MINIMIZE;
	    Sync->Settings.Priority = WXTHREAD_DEFAULT_PRIORITY;
	    Sync->Settings.ShowStatusbar = true;
	    Sync->Settings.StartasTray = false;
	    Sync->Settings.WriteLogfile = true;
	}

	if(!Sync->Settings.AutoSync)
        Sync->StopAutoSync();

    SelectedItem = 0;
}


/*!
 * Control creation for SimpleSyncDlg
 */

void SimpleSyncDlg::CreateControls()
{
first = true;
////@begin SimpleSyncDlg content construction
    SimpleSyncDlg* itemFrame1 = this;


    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu3 = new wxMenu;
    itemMenu3->Append(ID_MENUITEM_NEW_PROFILE, _("New Profile"), _T(""), wxITEM_NORMAL);
    itemMenu3->Append(ID_MENUITEM_EDIT_PROFILE, _("Edit Profile"), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(ID_MENUITEM_OPEN_PROFILE, _("Open Profile"), _T(""), wxITEM_NORMAL);
    itemMenu3->Append(ID_MENUITEM_SAVE_PROFILE, _("Save Profiel"), _T(""), wxITEM_NORMAL);
    itemMenu3->Append(ID_MENUITEM_SAVE_PROFILE_AS, _("Save as"), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(ID_MENUITEM_SETTINGS, _("Settings"), _T(""), wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(ID_MENUITEM_EXIT, _("Exit"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu3, _("File"));
    wxMenu* itemMenu14 = new wxMenu;
    itemMenu14->Append(ID_MENUITEM_ADD_SYNC_ENTRY, _("Add new Sync Entry"), _T(""), wxITEM_NORMAL);
    itemMenu14->Append(ID_MENUITEM, _("Edit Selected Entry"), _T(""), wxITEM_NORMAL);
    itemMenu14->AppendSeparator();
    itemMenu14->Append(ID_MENUITEM_START_SYNC, _("Sync all Entrys now"), _T(""), wxITEM_NORMAL);
    itemMenu14->Append(ID_MENUITEM_SYNC_SELECTED, _("Sync selected Entry now"), _T(""), wxITEM_NORMAL);
    itemMenu14->Append(ID_MENUITEM_CANCEL_SYNC, _("Abort Syncing"), _T(""), wxITEM_NORMAL);
    itemMenu14->AppendSeparator();
    itemMenu14->Append(ID_MENUITEM_AKTIVATE_AUTOSYNC, _("Activate AutoSync Checks"), _T(""), wxITEM_NORMAL);
    itemMenu14->Append(ID_MENUITEM_DEAKTIVATE_AUTOSYNC, _("Deactivate AutoSync Checks"), _T(""), wxITEM_NORMAL);
    itemMenu14->AppendSeparator();
    itemMenu14->Append(ID_MENUITEM_COMPARE_FOLDERS, _("Compare Folders of Sleected Sync Entry"), _T(""), wxITEM_NORMAL);
    itemMenu14->Append(ID_MENUITEM_FASTSYNCDLG, _("Show Fast Sync Dialog"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu14, _("Actions"));
    wxMenu* itemMenu27 = new wxMenu;
    itemMenu27->Append(ID_MENUITEM12, _("Info..."), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu27, _("Help"));
    itemFrame1->SetMenuBar(menuBar);

    m_StatusBar = new wxStatusBar( itemFrame1, ID_STATUSBAR1, wxST_SIZEGRIP|wxNO_BORDER );
    m_StatusBar->SetFieldsCount(2);
    itemFrame1->SetStatusBar(m_StatusBar);

    m_Toolbar = CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL, ID_TOOLBAR1 );
    m_Toolbar->SetToolBitmapSize(wxSize(32, 32));
    wxBitmap itemtool31Bitmap(itemFrame1->GetBitmapResource(wxT("recources/PlusOver.png")));
    wxBitmap itemtool31BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_ADD, _T(""), itemtool31Bitmap, itemtool31BitmapDisabled, wxITEM_NORMAL, _("Add New Sync Entry"), wxEmptyString);
    wxBitmap itemtool32Bitmap(itemFrame1->GetBitmapResource(wxT("recources/MinusOver.png")));
    wxBitmap itemtool32BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_REMOVE, _T(""), itemtool32Bitmap, itemtool32BitmapDisabled, wxITEM_NORMAL, _("Remove Selected Entry"), wxEmptyString);
    m_Toolbar->AddSeparator();
    wxBitmap itemtool34Bitmap(itemFrame1->GetBitmapResource(wxT("recources/UpOver.png")));
    wxBitmap itemtool34BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_MOVE_UP, _T(""), itemtool34Bitmap, itemtool34BitmapDisabled, wxITEM_NORMAL, _("Move Eentry Up"), wxEmptyString);
    wxBitmap itemtool35Bitmap(itemFrame1->GetBitmapResource(wxT("recources/DownOver.png")));
    wxBitmap itemtool35BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_MOVE_DOWN, _T(""), itemtool35Bitmap, itemtool35BitmapDisabled, wxITEM_NORMAL, _("Move Entry Down"), wxEmptyString);
    m_Toolbar->AddSeparator();
    wxBitmap itemtool37Bitmap(itemFrame1->GetBitmapResource(wxT("recources/SyncOver.png")));
    wxBitmap itemtool37BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_SYNC_ALL, _T(""), itemtool37Bitmap, itemtool37BitmapDisabled, wxITEM_NORMAL, _("Sync All Entrys now"), wxEmptyString);
    wxBitmap itemtool38Bitmap(itemFrame1->GetBitmapResource(wxT("recources/AbortOver.png")));
    wxBitmap itemtool38BitmapDisabled;
    m_Toolbar->AddTool(ID_TOOL_ABORT_SYNC, _T(""), itemtool38Bitmap, itemtool38BitmapDisabled, wxITEM_NORMAL, _("Abort Syncing"), wxEmptyString);
    m_Toolbar->EnableTool(ID_TOOL_ABORT_SYNC, false);
    m_Toolbar->Realize();
    itemFrame1->SetToolBar(m_Toolbar);

    m_ListCtrl = new wxListCtrl( itemFrame1, ID_SYNC_LISTCTRL, wxDefaultPosition, wxSize(99, 99), wxLC_REPORT );

    // Connect events and objects
    m_ListCtrl->Connect(ID_SYNC_LISTCTRL, wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(SimpleSyncDlg::OnListCtrlContextMenu), NULL, this);
////@end SimpleSyncDlg content construction
    Menu = menuBar;

    wxSize rect = m_ListCtrl->GetClientSize();
    m_ListCtrl->InsertColumn(0,_("Nr"),30);
    m_ListCtrl->InsertColumn(1,_("Dir 1"),rect.GetWidth()/2-60);
    m_ListCtrl->InsertColumn(2,_("Sync Direction"),90);
    m_ListCtrl->InsertColumn(3,_("Dir 2"),rect.GetWidth()-rect.GetWidth()/2-60);

    if(Sync->IsAutoSync()) {
        Menu->FindItem(ID_MENUITEM_AKTIVATE_AUTOSYNC)->Enable(false);
        Menu->FindItem(ID_MENUITEM_DEAKTIVATE_AUTOSYNC)->Enable(true);
    }
    else {
        Menu->FindItem(ID_MENUITEM_AKTIVATE_AUTOSYNC)->Enable(true);
        Menu->FindItem(ID_MENUITEM_DEAKTIVATE_AUTOSYNC)->Enable(false);
    }

    Menu->FindItem(ID_MENUITEM_CANCEL_SYNC)->Enable(false);

    m_StatusBar->Show(Sync->Settings.ShowStatusbar);

    //Check if user gave a Profile Path as Parameter
    if(ShellProfileParameter) {
        Sync->OpenProfile(wxFileName(ShellProfilePath).GetFullPath());
            for(unsigned int i = 0; i<Sync->SyncList.GetCount(); i++) {
                m_ListCtrl->InsertItem(i,wxString::Format(L"%i",i+1));
                m_ListCtrl->SetItem(i,1, Sync->SyncList[i].dir1 );
                m_ListCtrl->SetItem(i,2, Sync->SyncList[i].direction );
                m_ListCtrl->SetItem(i,3, Sync->SyncList[i].dir2 );
            }
    }
    else if(Sync->Settings.AutoOpenProfile) {
        Sync->OpenProfile(Sync->Settings.LastProfile);
        m_ListCtrl->DeleteAllItems();
            for(unsigned int i = 0; i<Sync->SyncList.GetCount(); i++) {
                m_ListCtrl->InsertItem(i,wxString::Format(L"%i",i+1));
                m_ListCtrl->SetItem(i,1, Sync->SyncList[i].dir1 );
                m_ListCtrl->SetItem(i,2, Sync->SyncList[i].direction );
                m_ListCtrl->SetItem(i,3, Sync->SyncList[i].dir2 );
            }
    }
    else {
        Sync->Settings.LastProfile.Empty();
    }
}


/*!
 * wxEVT_ICONIZE event handler for ID_SIMPLESYNCDLG
 */

void SimpleSyncDlg::OnIconize( wxIconizeEvent& event )
{
    if( IsIconized() && Sync->Settings.InTray == Tray::MINIMIZE) {
        Tray->MinimizeInTaskBar();
    }
////@begin wxEVT_ICONIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_ICONIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
}


/*!
 * wxEVT_SIZE event handler for ID_SIMPLESYNCDLG
 */

void SimpleSyncDlg::OnSize( wxSizeEvent& event )
{
////@begin wxEVT_SIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_SIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg
    if(!first && second < 2) {
        wxSize rect = m_ListCtrl->GetClientSize();
        m_ListCtrl->SetColumnWidth(0,30);
        m_ListCtrl->SetColumnWidth(1,rect.GetWidth()/2-55);
        m_ListCtrl->SetColumnWidth(2,80);
        m_ListCtrl->SetColumnWidth(3,rect.GetWidth()-rect.GetWidth()/2-55);
        if(Sync->Settings.StartasTray) {
            Tray->MinimizeInTaskBar();
        }
        second++;

    }
    first = false;
}


/*!
 * wxEVT_PAINT event handler for ID_SIMPLESYNCDLG
 */

void SimpleSyncDlg::OnPaint( wxPaintEvent& event )
{
////@begin wxEVT_PAINT event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    wxPaintDC dc(this);
////@end wxEVT_PAINT event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.

}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_ADD
 */

void SimpleSyncDlg::OnToolAddClick( wxCommandEvent& event )
{
    SyncEntryDlg entry;
    entry.Create(this,-1,_("Entry"), APP_LOCATION);
    //if(Sync->SyncList[SelectedItem] != NULL)
    if(entry.ShowModal() == 1) {
        SyncParameters Param;
        Param.id = Sync->SyncList.GetCount();
        Param.dir1 = entry.m_Dir1->GetValue();
        Param.dir2 = entry.m_Dir2->GetValue();
        Param.direction = entry.SyncDirection;
        Param.TargedClear = entry.m_ClearTarged->GetValue();
        Param.SyncAuto = entry.AutoSyncMode;
        Param.time.SetHour(entry.m_Hour->GetValue());
        Param.time.SetMinute(entry.m_Minute->GetValue());
        Param.HiddenFiles = entry.m_HiddenFiles->GetValue();
        Param.lastSynced.SetHour(0);
        Param.lastSynced.SetMinute(0);
        Param.filter_mode = entry.Filtermode;
        Param.Filters = entry.m_FilterString->GetValue();
        Param.noTimeCheck = entry.m_NoTimeCheck->GetValue();

        Sync->SyncList.Add(Param);
        Sync->ProfileModified = true;
        m_ListCtrl->InsertItem(Param.id,wxString::Format(L"%i",Param.id+1));
        m_ListCtrl->SetItem(Param.id,1, Param.dir1 );
        m_ListCtrl->SetItem(Param.id,2, Param.direction );
        m_ListCtrl->SetItem(Param.id,3, Param.dir2 );

    }
}


/*!
 * Should we show tooltips?
 */

bool SimpleSyncDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap SimpleSyncDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SimpleSyncDlg bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("recources/PlusOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/PlusOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == _T("recources/MinusOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/MinusOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == _T("recources/UpOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/UpOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == _T("recources/DownOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/DownOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == _T("recources/SyncOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/SyncOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    else if (name == _T("recources/AbortOver.png"))
    {
        wxBitmap bitmap(APP_LOCATION + _T("recources/AbortOver.png"), wxBITMAP_TYPE_PNG);
        return bitmap;
    }
    return wxNullBitmap;
////@end SimpleSyncDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon SimpleSyncDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SimpleSyncDlg icon retrieval
    wxUnusedVar(name);
    if (name == _T("recources/main.ico"))
    {
        wxIcon icon( APP_LOCATION + _T("recources/main.ico"), wxBITMAP_TYPE_ICO);
        return icon;
    }
    return wxNullIcon;
////@end SimpleSyncDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM12
 */

void SimpleSyncDlg::OnMenuInfo12Click( wxCommandEvent& event )
{
    wxAboutDialogInfo info;
    info.SetName(_("wxSimpleSync"));
    info.SetVersion(_("2.5"));
    info.SetDescription(_("Cross Platform Folder && File Syncer"));
    info.SetCopyright(_("(C) 2008 by BoscoWitch"));
    wxBitmap bitmap(APP_LOCATION + _T("recources/icon.png"), wxBITMAP_TYPE_PNG);
    wxIcon icon; icon.CopyFromBitmap(bitmap);
    info.SetIcon(icon);

    wxAboutBox(info);
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_SETTINGS
 */

void SimpleSyncDlg::OnMenuitemSettingsClick( wxCommandEvent& event )
{
    SettingsDlg settings;
    settings.Create(this,-1,_("Settings"));
    int sel;
    if( Sync->Settings.InTray == Tray::MINIMIZE )
        sel = 0;
    else if ( Sync->Settings.InTray == Tray::CLOSE)
        sel = 1;
    else
        sel = 2;

    settings.m_InTrayDrop->SetSelection(sel);
    if( Sync->Settings.Priority == WXTHREAD_MIN_PRIORITY )
        sel = 3;
    else if( Sync->Settings.Priority == WXTHREAD_DEFAULT_PRIORITY )
        sel = 1;
    else if( Sync->Settings.Priority == WXTHREAD_MAX_PRIORITY  )
        sel = 0;
    else
        sel = 2;
    settings.m_Priority->SetSelection(sel);
    settings.m_LastProfile->SetValue(Sync->Settings.AutoOpenProfile);
    settings.m_AutoSync->SetValue(Sync->Settings.AutoSync);
    settings.m_ShowStatus->SetValue(Sync->Settings.ShowStatusbar);
    settings.m_WriteLog->SetValue(Sync->Settings.WriteLogfile);
    settings.m_StartasTray->SetValue(Sync->Settings.StartasTray);


    if(settings.ShowModal() == wxID_OK) {
        sel = settings.m_InTrayDrop->GetSelection();
        if( sel == 0 )
            Sync->Settings.InTray = Tray::MINIMIZE;
        else if ( sel == 1)
            Sync->Settings.InTray = Tray::CLOSE;
        else
            Sync->Settings.InTray = Tray::NONE;

        sel = settings.m_Priority->GetSelection();
        if( sel == 3 )
            Sync->Settings.Priority = WXTHREAD_MIN_PRIORITY;
        else if( sel == 1 )
            Sync->Settings.Priority = WXTHREAD_DEFAULT_PRIORITY;
        else if( sel == 0 )
            Sync->Settings.Priority = WXTHREAD_MAX_PRIORITY;
        else
            Sync->Settings.Priority = 25;

        Sync->Settings.AutoOpenProfile = settings.m_LastProfile->GetValue();
        Sync->Settings.AutoSync = settings.m_AutoSync->GetValue();
        Sync->Settings.ShowStatusbar = settings.m_ShowStatus->GetValue();
        Sync->Settings.WriteLogfile = settings.m_WriteLog->GetValue();
        Sync->Settings.StartasTray = settings.m_StartasTray->GetValue();

        Sync->SaveSettings(APP_LOCATION + wxT("wxSimpleSyncSettings.xml"));
        m_StatusBar->Show(Sync->Settings.ShowStatusbar);
    }
}


/*!
 * wxEVT_CLOSE_WINDOW event handler for ID_SIMPLESYNCDLG
 */

void SimpleSyncDlg::OnCloseWindow( wxCloseEvent& event )
{
    if( Sync->Settings.InTray == Tray::CLOSE && event.CanVeto() && Taskbar )
    {
        event.Veto(true);
        Tray->MinimizeInTaskBar();
        Taskbar = true;
        return;
        event.Skip();
    }
    else {
        if(Sync->ProfileModified) {
            wxMessageDialog dlg(this, _("This Profile has been modified do you want so save the changes?"), _("Profile modified"), wxCANCEL | wxYES_NO);
            int ret = dlg.ShowModal();
            if( ret == wxID_YES ) {
                if(!Sync->Settings.LastProfile.IsEmpty()) {
                    Sync->SaveProfile(Sync->Settings.LastProfile);
                }
                else {
                    wxFileDialog filedlg(this,_("Save to"),L"",L"",L".xml",wxFD_SAVE);
                    if( filedlg.ShowModal() == wxID_OK) {
                        Sync->SaveProfile(filedlg.GetPath());
                    }
                }
            }
            else if( ret == wxID_CANCEL ) {
                event.Veto(true);
                return;
            }
        }
        Sync->SaveSettings(APP_LOCATION + wxT("wxSimpleSyncSettings.xml"));
        if(Taskbar)
        delete Tray;
        event.Skip();
    }
////@begin wxEVT_CLOSE_WINDOW event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_CLOSE_WINDOW event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
}


/*!
 * wxEVT_MAXIMIZE event handler for ID_SIMPLESYNCDLG
 */

void SimpleSyncDlg::OnMaximize( wxMaximizeEvent& event )
{

////@begin wxEVT_MAXIMIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_MAXIMIZE event handler for ID_SIMPLESYNCDLG in SimpleSyncDlg.
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EDIT_PROFILE
 */

void SimpleSyncDlg::OnMenuEditProfileClick( wxCommandEvent& event )
{
    ProfileDlg profile;
    profile.Create(this,-1,_("Profile Settings"));
    if(profile.ShowModal() == 1) {
        Sync->ProfileName = profile.m_ProfileName->GetValue();
        m_StatusBar->SetStatusText(_("Changed Pfofile Settings"));
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_NEW_PROFILE
 */

void SimpleSyncDlg::OnMenuitemNewProfileClick( wxCommandEvent& event )
{
    Sync->ProfileName = _("New Pofile");
    m_ListCtrl->DeleteAllItems();
    Sync->SyncList.Empty();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_OPEN_PROFILE
 */

void SimpleSyncDlg::OnMenuitemOpenProfileClick( wxCommandEvent& event )
{
    if( Sync->ProfileModified ) {
         wxMessageDialog dlg(this, _("This Profile has been modified do you want so save the changes?"), _("Profile modified"), wxCANCEL | wxYES_NO);
            int ret = dlg.ShowModal();
            if( ret == wxID_YES ) {
                if(!Sync->Settings.LastProfile.IsEmpty()) {
                    Sync->SaveProfile(Sync->Settings.LastProfile);
                }
                else {
                    wxFileDialog filedlg(this,_("Save to"),L"",L"",L".xml",wxFD_SAVE);
                    if( filedlg.ShowModal() == wxID_OK) {
                        Sync->SaveProfile(filedlg.GetPath());
                    }
                }
            }
            else if( ret == wxID_CANCEL ) {
                return;
            }
    }

        wxFileDialog filedlg(this,_("Open Profile"),L"",L"",L"*.xml;*.XML;*",wxFD_OPEN);
        if( filedlg.ShowModal() == wxID_OK) {
            Sync->OpenProfile(filedlg.GetPath());
            m_ListCtrl->DeleteAllItems();
            for(unsigned int i = 0; i<Sync->SyncList.GetCount(); i++) {
                m_ListCtrl->InsertItem(i,wxString::Format(L"%i",i+1));
                m_ListCtrl->SetItem(i,1, Sync->SyncList[i].dir1 );
                m_ListCtrl->SetItem(i,2, Sync->SyncList[i].direction );
                m_ListCtrl->SetItem(i,3, Sync->SyncList[i].dir2 );
            }
        }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_SAVE_PROFILE
 */

void SimpleSyncDlg::OnMenuitemSaveProfileClick( wxCommandEvent& event )
{
    if(!Sync->Settings.LastProfile.IsEmpty()) {
        Sync->SaveProfile(Sync->Settings.LastProfile);
    }
    else {
        wxFileDialog filedlg(this,_("Save to"),L"",L"",L".xml",wxFD_SAVE);
        if( filedlg.ShowModal() == wxID_OK) {
            Sync->SaveProfile(filedlg.GetPath());
        }
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_SAVE_PROFILE_AS
 */

void SimpleSyncDlg::OnMenuitemSaveProfileAsClick( wxCommandEvent& event )
{
    wxFileDialog filedlg(this,_("Save to"),L"",L"",L".xml",wxFD_SAVE);
    if( filedlg.ShowModal() == wxID_OK) {
        Sync->SaveProfile(filedlg.GetPath());
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
 */

void SimpleSyncDlg::OnMenuitemExitClick( wxCommandEvent& event )
{
    Taskbar = false;
    Close();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_ADD_SYNC_ENTRY
 */

void SimpleSyncDlg::OnMenuitemAddSyncEntryClick( wxCommandEvent& event )
{
    wxCommandEvent evt;
    OnToolAddClick(evt);
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_START_SYNC
 */

void SimpleSyncDlg::OnMenuitemStartSyncClick( wxCommandEvent& event )
{
    wxCommandEvent evt;
    OnToolSyncAllClick(evt);
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_CANCEL_SYNC
 */

void SimpleSyncDlg::OnMenuitemCancelSyncClick( wxCommandEvent& event )
{
    m_StatusBar->SetStatusText(_("Aborting Sync Process, Please Wait"));
    Sync->AbortSync();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_AKTIVATE_ATUSYNC
 */

void SimpleSyncDlg::OnMenuitemAktivateAutosyncClick( wxCommandEvent& event )
{
    Menu->FindItem(ID_MENUITEM_AKTIVATE_AUTOSYNC)->Enable(false);
    Menu->FindItem(ID_MENUITEM_DEAKTIVATE_AUTOSYNC)->Enable(true);
    Sync->StartAutoSync();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_DEAKTIVATE_AUTOSYNC
 */

void SimpleSyncDlg::OnMenuitemDeaktivateAutosyncClick( wxCommandEvent& event )
{
    Menu->FindItem(ID_MENUITEM_AKTIVATE_AUTOSYNC)->Enable(true);
    Menu->FindItem(ID_MENUITEM_DEAKTIVATE_AUTOSYNC)->Enable(false);
    Sync->StopAutoSync();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_REMOVE
 */

void SimpleSyncDlg::OnToolRemoveClick( wxCommandEvent& event )
{
    if(Sync->RemoveEntry(SelectedItem)) {
        m_ListCtrl->DeleteItem(SelectedItem);
        Sync->ProfileModified = true;
    }

    //TODO UPDATE NUMBERS
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_MOVE_UP
 */

void SimpleSyncDlg::OnToolMoveUpClick( wxCommandEvent& event )
{
    if(SelectedItem > 0)
    {
        SyncParameters temp;
        temp = Sync->SyncList[SelectedItem-1];
        Sync->SyncList[SelectedItem-1] = Sync->SyncList[SelectedItem];
        Sync->SyncList[SelectedItem] = temp;

        Sync->SyncList[SelectedItem].id = SelectedItem;
        Sync->SyncList[SelectedItem-1].id = SelectedItem-1;

        wxListItem lol;
        m_ListCtrl->SetItem(SelectedItem,0, wxString::Format(L"%i",SelectedItem+1));
        m_ListCtrl->SetItem(SelectedItem,1, temp.dir1 );
        m_ListCtrl->SetItem(SelectedItem,2, temp.direction );
        m_ListCtrl->SetItem(SelectedItem,3, temp.dir2 );

        m_ListCtrl->SetItem(SelectedItem-1,0, wxString::Format(L"%i",SelectedItem));
        m_ListCtrl->SetItem(SelectedItem-1,1, Sync->SyncList[SelectedItem-1].dir1 );
        m_ListCtrl->SetItem(SelectedItem-1,2, Sync->SyncList[SelectedItem-1].direction );
        m_ListCtrl->SetItem(SelectedItem-1,3, Sync->SyncList[SelectedItem-1].dir2 );
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_MOVE_DOWN
 */

void SimpleSyncDlg::OnToolMoveDownClick( wxCommandEvent& event )
{
    if(SelectedItem+1 < Sync->SyncList.GetCount())
    {
        SyncParameters temp;
        temp = Sync->SyncList[SelectedItem+1];
        Sync->SyncList[SelectedItem+1] = Sync->SyncList[SelectedItem];
        Sync->SyncList[SelectedItem] = temp;

        Sync->SyncList[SelectedItem].id = SelectedItem;
        Sync->SyncList[SelectedItem+1].id = SelectedItem+1;

        wxListItem lol;
        m_ListCtrl->SetItem(SelectedItem,0, wxString::Format(L"%i",SelectedItem+1));
        m_ListCtrl->SetItem(SelectedItem,1, temp.dir1 );
        m_ListCtrl->SetItem(SelectedItem,2, temp.direction );
        m_ListCtrl->SetItem(SelectedItem,3, temp.dir2 );

        m_ListCtrl->SetItem(SelectedItem+1,0, wxString::Format(L"%i",SelectedItem+2));
        m_ListCtrl->SetItem(SelectedItem+1,1, Sync->SyncList[SelectedItem+1].dir1 );
        m_ListCtrl->SetItem(SelectedItem+1,2, Sync->SyncList[SelectedItem+1].direction );
        m_ListCtrl->SetItem(SelectedItem+1,3, Sync->SyncList[SelectedItem+1].dir2 );
    }
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_SYNC_LISTCTRL
 */

void SimpleSyncDlg::OnSyncListctrlSelected( wxListEvent& event )
{
    SelectedItem = event.GetIndex();
////@begin wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_SYNC_LISTCTRL in SimpleSyncDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_SYNC_LISTCTRL in SimpleSyncDlg.
}


/*!
 * wxEVT_LEFT_DCLICK event handler for ID_SYNC_LISTCTRL
 */

void SimpleSyncDlg::OnMenuEditEntryClick( wxCommandEvent& event )
{
    SyncEntryDlg entry;
    entry.Create(this,-1,_("Entry"),APP_LOCATION);
    //if(Sync->SyncList[SelectedItem] != NULL)
    if( m_ListCtrl->GetItemCount() > SelectedItem ) {
        entry.AutoSyncMode = Sync->SyncList[SelectedItem].SyncAuto;
        entry.Filtermode = Sync->SyncList[SelectedItem].filter_mode;
        entry.m_FilterString->SetValue(Sync->SyncList[SelectedItem].Filters);
        entry.m_Hour->SetValue(Sync->SyncList[SelectedItem].time.GetHour());
        entry.m_Minute->SetValue(Sync->SyncList[SelectedItem].time.GetMinute());
        entry.SyncDirection = Sync->SyncList[SelectedItem].direction;
        entry.m_ClearTarged->SetValue(Sync->SyncList[SelectedItem].TargedClear);
        entry.m_NoTimeCheck->SetValue(Sync->SyncList[SelectedItem].noTimeCheck);
        entry.m_HiddenFiles->SetValue(Sync->SyncList[SelectedItem].HiddenFiles);
        entry.m_Dir1->SetValue(Sync->SyncList[SelectedItem].dir1);
        entry.m_Dir2->SetValue(Sync->SyncList[SelectedItem].dir2);
        entry.RefreshCtrlState();
        if(entry.ShowModal() == 1) {
            SyncParameters Param;
            Param.id = SelectedItem;
            Param.dir1 = entry.m_Dir1->GetValue();
            Param.dir2 = entry.m_Dir2->GetValue();
            Param.direction = entry.SyncDirection;
            Param.TargedClear = entry.m_ClearTarged->GetValue();
            Param.SyncAuto = entry.AutoSyncMode;
            Param.time.SetHour(entry.m_Hour->GetValue());
            Param.time.SetMinute(entry.m_Minute->GetValue());
            Param.HiddenFiles = entry.m_HiddenFiles->GetValue();
            /*wxDateTime lastchecked;
            wxDateTime lastSynced;
            wxDateTime nextSync;*/
            //bool SystemFiles;
            Param.filter_mode = entry.Filtermode;
            Param.Filters = entry.m_FilterString->GetValue();
            Param.noTimeCheck = entry.m_NoTimeCheck->GetValue();


            Sync->SyncList[SelectedItem] = Param;
            m_ListCtrl->SetItem(SelectedItem,0, wxString::Format(L"%i",SelectedItem+1));
            m_ListCtrl->SetItem(SelectedItem,1, Param.dir1 );
            m_ListCtrl->SetItem(SelectedItem,2, Param.direction );
            m_ListCtrl->SetItem(SelectedItem,3, Param.dir2 );
            Sync->ProfileModified = true;
        }
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SYNC_ALL
 */

void SimpleSyncDlg::OnToolSyncAllClick( wxCommandEvent& event )
{
    Sync->SyncAllEntrys();
}




/*!
 * wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for ID_SYNC_LISTCTRL
 */

void SimpleSyncDlg::OnLeftDClick( wxListEvent& event )
{
    wxCommandEvent event1;
    OnMenuEditEntryClick(event1);
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_ABORT_SYNC
 */

void SimpleSyncDlg::OnToolAbortSyncClick( wxCommandEvent& event )
{
    OnMenuitemCancelSyncClick( event );
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_COMPARE_FOLDERS
 */

void SimpleSyncDlg::OnMenuitemCompareFoldersClick( wxCommandEvent& event )
{
    if( m_ListCtrl->GetItemCount() > SelectedItem ) {
        FolderCompareDlg cfdlg;
        cfdlg.Create(this,-1,_("Compare Sync Folders"));
        cfdlg.Dir1=Sync->SyncList[SelectedItem].dir1;
        cfdlg.Dir2=Sync->SyncList[SelectedItem].dir2;
        cfdlg.ShowModal();
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_SYNC_SELECTED
 */

void SimpleSyncDlg::OnMenuitemSyncSelectedClick( wxCommandEvent& event )
{
    if( m_ListCtrl->GetItemCount() > SelectedItem ) {
        Sync->SyncEntry(SelectedItem);
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_FASTSYNCDLG
 */

void SimpleSyncDlg::OnMenuitemFastsyncdlgClick( wxCommandEvent& event )
{
    //delete FsDlg;
    FsDlg = new FastSyncDlg();
    FsDlg->Sync = Sync;
    FsDlg->Create(this, -1, _("Fast Sync Dialog"));
    FsDlg->Show();
}


/*!
 * wxEVT_CONTEXT_MENU event handler for ID_SYNC_LISTCTRL
 */

void SimpleSyncDlg::OnListCtrlContextMenu( wxContextMenuEvent& event )
{
    wxMenu *menu = new wxMenu;
    menu->Append(ID_MENUITEM_SYNC_SELECTED, _("&Sync Selected Entry"));
    menu->Append(ID_MENUITEM,_("&Edit Selected Entry"));
    menu->Append(ID_MENUITEM_COMPARE_FOLDERS, _("&Compare Folders of Selected Entry"));
    menu->AppendSeparator();
    menu->Append(ID_MENUITEM_START_SYNC, _("Sync &All Entrys"));
    PopupMenu(menu);
}

