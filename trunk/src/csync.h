/////////////////////////////////////////////////////////////////////////////
// Name:        csync.h
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




#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/frame.h>
#include <wx/dynarray.h>
#include <wx/thread.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/listctrl.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/dnd.h>

#ifndef CXML
#define CXML
#include "cxml.h"
#endif

#ifndef CLOG
#define CLOG
#include "clogging.h"
#endif

#ifdef SHELL_BUILD
#include <iostream>
#endif
#ifndef SHELL_BUILD
#include "wxSimpleSyncGui/simplesyncdlg.h"
class SimpleSyncDlg;
#endif


class CSyncThread;

namespace Tray
{
enum InTrayEvent { NONE = 0 ,MINIMIZE = 1, CLOSE = 2};
}
class CSettings
{
public:
	Tray::InTrayEvent InTray;
	bool ShowStatusbar;
	int Priority;
	bool AutoSync;
	bool AutoOpenProfile;
	bool StartasTray;
	bool WriteLogfile;
	wxString LastProfile;
};

class SyncParameters
{
public:
	int id;
	wxString dir1;
	wxString dir2;
	wxString direction;
	bool TargedClear;
	int SyncAuto;
	wxDateTime time;
	wxDateTime lastSynced;
	bool HiddenFiles;
	int filter_mode;
	wxString Filters;
	bool noTimeCheck;
};

WX_DECLARE_OBJARRAY(SyncParameters, SyncParametersArray);

class CFolderSyncer : public wxTimer
{
public:
    SyncParametersArray SyncList;
    CSettings Settings;

    bool OpenProfile(wxString file);
    bool SaveProfile(wxString file);

    bool OpenSettings(wxString Path);
    bool SaveSettings(wxString Path);

    void AbortSync();

    CSyncThread* Syncer;
    bool running;
    wxCriticalSection csect;

	CFolderSyncer(CLogging *logger)
		{ ProfileModified=false; LastCheck.SetHour(wxDateTime::Now().GetHour() + 1); wxTimer(); m_logger = logger; Start(30000); running = false;};
    #ifndef SHELL_BUILD
    CFolderSyncer(CLogging *logger, SimpleSyncDlg* Pointer)
		{ ProfileModified=false; Gui=Pointer; LastCheck.SetHour(wxDateTime::Now().GetHour() + 1); wxTimer(); m_logger = logger; Start(30000); running = false;};
    #endif
    //Timer for Autosync
	void Notify();

    //Sync all of Synclist
	void SyncAllEntrys();

	void StopAutoSync() { if(IsRunning()) Stop(); };
	void StartAutoSync() { if(!IsRunning()) Start(30000); };

	bool IsAutoSync() { return IsRunning(); };

    //Sync Entry at position entry in SyncList
	bool SyncEntry(int entry);

	//Sync with Parameters
	bool SyncPath(wxString Diection, wxString Dir1, wxString Dir2, bool HiddenFiles, bool DeleteOld);

	//Removes an Sync Entry at index
	bool RemoveEntry(int index);


    wxString ProfileName;
    bool ProfileModified;
    wxDateTime LastCheck;
private:
    #ifndef SHELL_BUILD
    SimpleSyncDlg* Gui;
	#endif
	CLogging *m_logger;
	wxCriticalSection csection;

};




class CSyncThread : public wxThread
{
public:
    SyncParametersArray ThreadList;

    CSyncThread(CFolderSyncer * mysyncer) { m_cfolder = mysyncer; wxFileName sep; Sep = sep.GetPathSeparator(); };

    #ifndef SHELL_BUILD
    CSyncThread(CFolderSyncer * mysyncer, SimpleSyncDlg* Pointer) { m_cfolder = mysyncer; Gui = Pointer; wxFileName sep; Sep = sep.GetPathSeparator(); };
    #endif

    CFolderSyncer *m_cfolder;

    wxCriticalSection csect;

    //Progress "Bar" Functions
    void CountFiles(wxString Path,wxString Filters,int filter_mode);

    bool SyncFolders(SyncParameters Parameter);
    bool SyncFoldersR(wxString Path1,wxString Path2,SyncParameters Parameter);
    bool FilterCheck(wxString file, wxString filter, int mode);
    bool ClearDirectories(wxString dir1,wxString dir2, wxString direction);
    bool RekrusiveDel(wxString Path);
    void StartSyncList();

    virtual void* Entry();
    //virtual void* OnExit(){  };
private:
    wxString Sep;
    int prefilecount;
    int current_filecount;
    #ifndef SHELL_BUILD
    SimpleSyncDlg* Gui;
    #endif

    #if defined(__WXGTK__) || defined(__WXX11__)
	bool CopySymlink(wxString linkfilepath,wxString target);
	__time_t file_modtime(wxString name);
	#endif
};



