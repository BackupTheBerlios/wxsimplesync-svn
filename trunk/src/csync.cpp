/////////////////////////////////////////////////////////////////////////////
// Name:        csync.cpp
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

#ifndef CSYNC
#define CSYNC
#include "csync.h"
#endif


#if defined(__WXMSW__)
#include <windows.h>
#endif

#if defined(__WXGTK__) || defined(__WXX11)
#include <sys/stat.h>
#include <sys/types.h>
#endif

//STRANGE STUFF FOR THE wxArray
#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(SyncParametersArray);
//HAS TO BE DONE

void* CSyncThread::Entry(){
    #ifndef SHELL_BUILD
    wxMutexGuiEnter();
    Gui->m_StatusBar->SetStatusText(L"Syncing...");
    wxMutexGuiLeave();
    #endif
    StartSyncList();
    wxCriticalSectionLocker  locker(m_cfolder->csect);
    #ifndef SHELL_BUILD
    wxMutexGuiEnter();
    Gui->m_Toolbar->EnableTool(10010,true);
    Gui->m_Toolbar->EnableTool(10033,false);
    Gui->Menu->FindItem(10012)->Enable(false);
    Gui->Menu->FindItem(10011)->Enable(true);
    Gui->m_StatusBar->SetStatusText(L"Finished Syncing");
    Gui->m_StatusBar->SetStatusText(L"",1);
    wxMutexGuiLeave();
    #endif
    m_cfolder->running=false;

    return 0;
}

bool CSyncThread::RekrusiveDel(wxString Path)
{
    wxDir dir1;
    dir1.Open(Path);
    //check if accesable
    if ( !dir1.IsOpened())
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return false;
    }

    wxString filename,filespec,Sep,temp;
    wxFileName file1,sep;
    Sep = sep.GetPathSeparator();

	int flags = wxDIR_FILES | wxDIR_DIRS | wxDIR_HIDDEN;

        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {

            if(wxDirExists(Path + Sep + filename))
            {
                temp = Path + Sep + filename;
                #if defined(__WXMSW__)
                SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                #endif
                RekrusiveDel(Path + Sep + filename);
                wxRmdir(Path + Sep + filename);
            }
            else
            {
                temp = Path + Sep + filename;
                #if defined(__WXMSW__)
                SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                #endif
                wxRemoveFile(Path + Sep + filename);
            }

            cont = dir1.GetNext(&filename);
        }

    return true;
}

bool CSyncThread::ClearDirectories(wxString Pdir1,wxString Pdir2, wxString direction)
{
    wxDir dir1;
    wxDir dir2;
    //Open directories
    dir1.Open(Pdir1);
    dir2.Open(Pdir2);
    //check if both are accesable
    if ( !dir1.IsOpened() || !dir2.IsOpened() )
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return false;
    }

    if(TestDestroy()) return false;

    wxString filename,filespec,Sep,temp;
    wxFileName file1,file2,sep;
    Sep = sep.GetPathSeparator();

	int flags = wxDIR_FILES | wxDIR_DIRS | wxDIR_HIDDEN;

    if(direction == L"->")
    {
        bool cont = dir2.GetFirst(&filename, filespec, flags);
        while ( cont )
        {

            if(wxDirExists(Pdir2 + Sep + filename))
            {
                if(!wxDirExists(Pdir1 + Sep + filename)) {
                    temp = Pdir2 + Sep + filename;
                    #if defined(__WXMSW__)
                    SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                    #endif
                    RekrusiveDel(Pdir2 + Sep + filename);
                    wxRmdir(Pdir2 + Sep + filename);
                }
                else
                    ClearDirectories(Pdir1 + Sep + filename, Pdir2 + Sep + filename,direction);

            }
            else
            {
                    file1.SetPath(Pdir1 + Sep + filename);
                    file2.SetPath(Pdir2 + Sep + filename);

                    if(!wxFileExists(file1.GetPath())) //File exists
                    {
                        temp = file2.GetPath();
                        #if defined(__WXMSW__)
                        SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                        #endif
                        wxRemoveFile(file2.GetPath());
                    }
            }
            cont = dir2.GetNext(&filename);
        }
    }
    else if (direction == L"<-")
    {
        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {

            if(wxDirExists(Pdir1 + Sep + filename))
            {
                if(!wxDirExists(Pdir2 + Sep + filename)) {
                    temp = Pdir1 + Sep + filename;
                    #if defined(__WXMSW__)
                    SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                    #endif
                    RekrusiveDel(Pdir1 + Sep + filename); wxRmdir(Pdir1 + Sep + filename);
                }
                else
                    ClearDirectories(Pdir1 + Sep + filename, Pdir2 + Sep + filename,direction);

            }
            else
            {
                    file1.SetPath(Pdir1 + Sep + filename);
                    file2.SetPath(Pdir2 + Sep + filename);

                    if(!wxFileExists(file2.GetPath())) //File exists
                    {
                        temp = file1.GetPath();
                        #if defined(__WXMSW__)
                        SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                        #endif
                        wxRemoveFile(file1.GetPath());
                    }
            }
            cont = dir1.GetNext(&filename);
        }
    }

    return true;
}

bool CSyncThread::FilterCheck(wxString file, wxString filter, int mode)
{
    switch(mode)
    {
        case 1: //Filter files with FilterString Part Strings in Name
        {
            wxStringTokenizer tkz(filter, wxT(";"));
            while ( tkz.HasMoreTokens() )
            {
                if(file.find(tkz.GetNextToken()) != wxNOT_FOUND)
                    return false;
            }
            return true;
            break;
        }
        case 2: //Only Sync files with FilterStrings Part Strings in Name
        {
            wxStringTokenizer tkz(filter, wxT(";"));
            while ( tkz.HasMoreTokens() )
            {
                if(file.find(tkz.GetNextToken()) != wxNOT_FOUND)
                    return true;
            }
            return false;
        }
        default:
        {
            return true;
            break;
        }
    }

    return true;
}

bool CSyncThread::SyncFolders(SyncParameters Parameter)
{
    wxDir dir1;
    wxDir dir2;
    //Open directories
    dir1.Open(Parameter.dir1);
    dir2.Open(Parameter.dir2);

    //check if both are accesable
    if ( !dir1.IsOpened() || !dir2.IsOpened() || !wxDirExists(Parameter.dir1) || !wxDirExists(Parameter.dir2))
    {
        wxLogError(wxString::Format(_("Could not sync entry number:%i access one or both of these folders for syncing: ") + Parameter.dir1 + L" + " + Parameter.dir2 ,Parameter.id+1));
        return false;
    }
    wxLogMessage(wxString::Format(_("Syncing entry number:%i folders: ") + Parameter.dir1 + L" " + Parameter.direction + L" " + Parameter.dir2,Parameter.id+1));

    if(TestDestroy()) return false;

    wxString filename,filespec,Sep,temp;
    wxFileName file1,file2,sep;
    Sep = sep.GetPathSeparator(); // MAKE CLASS GLOBAL (PERFORMANCE)
    #if defined(__WXGTK__) || defined(__WXX11)
    struct stat att;
    wxString tmp;
    #endif

    if(Parameter.TargedClear)
        ClearDirectories(Parameter.dir1, Parameter.dir2, Parameter.direction);

	int flags = wxDIR_FILES | wxDIR_DIRS;
	if(Parameter.HiddenFiles)
        flags = flags | wxDIR_HIDDEN;

    if(Parameter.direction == L"->")
    {
        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
            #if defined(__WXGTK__) || defined(__WXX11)
            tmp = Parameter.dir1 + Sep + filename;
            lstat(tmp.fn_str(),&att);
            if(!S_ISLNK(att.st_mode))
            #endif
            if(FilterCheck(filename,Parameter.Filters,Parameter.filter_mode))
            {
                if(wxDirExists(Parameter.dir1 + Sep + filename))
                {
                    if(!wxDirExists(Parameter.dir2 + Sep + filename)) {
                        wxMkdir(Parameter.dir2 + Sep + filename);
                        #if defined(__WXMSW__)
                        temp = Parameter.dir1 + Sep + filename;
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = Parameter.dir2 + Sep + filename;
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }

                    SyncFoldersR(Parameter.dir1 + Sep + filename, Parameter.dir2  + Sep + filename, Parameter);
                }
                else
                {
                    file1.SetPath(Parameter.dir1 + Sep + filename);
                    file2.SetPath(Parameter.dir2 + Sep + filename);

                    if(wxFileExists(file2.GetPath())) //File exists
                    {
                        if( file1.GetModificationTime() > file2.GetModificationTime() || Parameter.noTimeCheck)
                        {
                            #if defined(__WXMSW__)
                            temp = file2.GetPath();
                            SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                            #endif
                            wxCopyFile(file1.GetPath(),file2.GetPath(),true);
                            #if defined(__WXMSW__)
                            temp = file1.GetPath();
                            //MSW PLATFORM CODE ONLY
                            DWORD att = GetFileAttributes(temp.c_str());
                            temp = file2.GetPath();
                            SetFileAttributes(temp.c_str(),att);
                            #endif
                        }
                    }
                    else
                    {
                        wxCopyFile(file1.GetPath(),file2.GetPath(),true);
                        #if defined(__WXMSW__)
                        temp = file1.GetPath();
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = file2.GetPath();
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }
                }
            }
            cont = dir1.GetNext(&filename);
        }
    }
    else if(Parameter.direction == L"<-")
    {
        bool cont = dir2.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
            #if defined(__WXGTK__) || defined(__WXX11)
            tmp = Parameter.dir2 + Sep + filename;
            lstat(tmp.fn_str(),&att);
            if(!S_ISLNK(att.st_mode))
            #endif
            if(FilterCheck(filename,Parameter.Filters,Parameter.filter_mode))
            {
                if(wxDirExists(Parameter.dir2 + Sep + filename))
                {
                    if(!wxDirExists(Parameter.dir1 + Sep + filename)) {
                        wxMkdir(Parameter.dir1 + Sep + filename);
                        #if defined(__WXMSW__)
                        temp = Parameter.dir2 + Sep + filename;
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = Parameter.dir1 + Sep + filename;
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }

                   SyncFoldersR(Parameter.dir1 + Sep + filename, Parameter.dir2  + Sep + filename, Parameter);
                }
                else
                {
                    file1.SetPath(Parameter.dir1 + Sep + filename);
                    file2.SetPath(Parameter.dir2 + Sep + filename);

                    if(wxFileExists(file1.GetPath())) //File exists
                    {
                        if( file2.GetModificationTime() > file1.GetModificationTime() || Parameter.noTimeCheck)
                        {
                            #if defined(__WXMSW__)
                            temp = file1.GetPath();
                            SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                            #endif
                            wxCopyFile(file2.GetPath(),file1.GetPath(),true);
                            #if defined(__WXMSW__)
                            temp = file2.GetPath();
                            //MSW PLATFORM CODE ONLY
                            DWORD att = GetFileAttributes(temp.c_str());
                            temp = file1.GetPath();
                            SetFileAttributes(temp.c_str(),att);
                            #endif
                        }
                    }
                    else
                    {
                        wxCopyFile(file2.GetPath(),file1.GetPath(),true);
                        #if defined(__WXMSW__)
                        temp = file2.GetPath();
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = file1.GetPath();
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }
                }
            }
            cont = dir2.GetNext(&filename);
        }
    }

    wxLogMessage(wxString::Format(_("Finished syncing entry number:%i"),Parameter.id+1));
    return true;
}

bool CSyncThread::SyncFoldersR(wxString Path1,wxString Path2,SyncParameters Parameter)
{
    wxDir dir1;
    wxDir dir2;
    //Open directories
    dir1.Open(Path1);
    dir2.Open(Path2);
    //check if both are accesable
    if ( !dir1.IsOpened() || !dir2.IsOpened() )
    {
        wxLogError(wxString::Format(_("Could not sync entry number:%i access one or both of these folders for syncing: ") + Parameter.dir1 + L" + " + Parameter.dir2 ,Parameter.id+1));
        return false;
    }

    if(TestDestroy()) return false;

    wxString filename,filespec,Sep,temp;
    wxFileName file1,file2,sep;
    Sep = sep.GetPathSeparator(); // MAKE CLASS GLOBAL (PERFORMANCE)
    #if defined(__WXGTK__) || defined(__WXX11)
    struct stat att;
    wxString tmp;
    #endif


	int flags = wxDIR_FILES | wxDIR_DIRS;
	if(Parameter.HiddenFiles)
        flags = flags | wxDIR_HIDDEN;

    if(Parameter.direction == L"->")
    {
        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
            #if defined(__WXGTK__) || defined(__WXX11)
            tmp = Path1 + Sep + filename;
            lstat(tmp.fn_str(),&att);
            if(!S_ISLNK(att.st_mode))
            #endif
            if(FilterCheck(filename,Parameter.Filters,Parameter.filter_mode))
            {
                if(wxDirExists(Path1 + Sep + filename))
                {
                    if(!wxDirExists(Path2 + Sep + filename)) {
                        wxMkdir(Path2 + Sep + filename);
                        #if defined(__WXMSW__)
                        temp = Path1 + Sep + filename;
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = Path2 + Sep + filename;
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }

                    SyncFoldersR(Path1 + Sep + filename, Path2  + Sep + filename, Parameter);


                }
                else
                {
                    file1.SetPath(Path1 + Sep + filename);
                    file2.SetPath(Path2 + Sep + filename);

                    if(wxFileExists(file2.GetPath())) //File exists
                    {
                        if( file1.GetModificationTime() > file2.GetModificationTime() || Parameter.noTimeCheck)
                        {
                            #if defined(__WXMSW__)
                            temp = file2.GetPath();
                            SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                            #endif
                            wxCopyFile(file1.GetPath(),file2.GetPath(),true);
                            #if defined(__WXMSW__)
                            temp = file1.GetPath();
                            //MSW PLATFORM CODE ONLY
                            DWORD att = GetFileAttributes(temp.c_str());
                            temp = file2.GetPath();
                            SetFileAttributes(temp.c_str(),att);
                            #endif
                        }
                    }
                    else
                    {
                        wxCopyFile(file1.GetPath(),file2.GetPath(),true);
                        #if defined(__WXMSW__)
                        temp = file1.GetPath();
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = file2.GetPath();
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }
                }
            }
            cont = dir1.GetNext(&filename);
        }
    }
    else if(Parameter.direction == L"<-")
    {
        bool cont = dir2.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
            #if defined(__WXGTK__) || defined(__WXX11)
            tmp = Path2 + Sep + filename;
            lstat(tmp.fn_str(),&att);
            if(!S_ISLNK(att.st_mode))
            #endif
            if(FilterCheck(filename,Parameter.Filters,Parameter.filter_mode))
            {
                if(wxDirExists(Path2 + Sep + filename))
                {
                    if(!wxDirExists(Path1 + Sep + filename)) {
                        wxMkdir(Path1 + Sep + filename);
                        #if defined(__WXMSW__)
                        temp = Path2 + Sep + filename;
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = Path1 + Sep + filename;
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }

                    SyncFoldersR(Path1 + Sep + filename, Path2  + Sep + filename, Parameter);
                }
                else
                {
                    file1.SetPath(Path1 + Sep + filename);
                    file2.SetPath(Path2 + Sep + filename);

                    if(wxFileExists(file1.GetPath())) //File exists
                    {
                        if( file2.GetModificationTime() > file1.GetModificationTime() || Parameter.noTimeCheck)
                        {
                            #if defined(__WXMSW__)
                            temp = file1.GetPath();
                            SetFileAttributes(temp.c_str(),FILE_ATTRIBUTE_NORMAL);
                            #endif
                            wxCopyFile(file2.GetPath(),file1.GetPath(),true);
                            #if defined(__WXMSW__)
                            temp = file2.GetPath();
                            //MSW PLATFORM CODE ONLY
                            DWORD att = GetFileAttributes(temp.c_str());
                            temp = file1.GetPath();
                            SetFileAttributes(temp.c_str(),att);
                            #endif
                        }
                    }
                    else
                    {
                        wxCopyFile(file2.GetPath(),file1.GetPath(),true);
                        #if defined(__WXMSW__)
                        temp = file2.GetPath();
                        //MSW PLATFORM CODE ONLY
                        DWORD att = GetFileAttributes(temp.c_str());
                        temp = file1.GetPath();
                        SetFileAttributes(temp.c_str(),att);
                        #endif
                    }
                }
            }
            cont = dir2.GetNext(&filename);
        }
    }


    return true;
}

void CSyncThread::StartSyncList()
{
    if( !ThreadList.IsEmpty())
    {
        for(int i=0; i<ThreadList.GetCount(); i++) {
            #ifndef SHELL_BUILD
            wxMutexGuiEnter();
            Gui->m_StatusBar->SetStatusText(_("Now Syncing..."));
            Gui->m_StatusBar->SetStatusText( wxString::Format(_("Syncing Entry: %i"),ThreadList[i].id+1) , 1);
            Gui->Menu->FindItem(10012)->Enable(true);
            Gui->Menu->FindItem(10011)->Enable(false);
            wxMutexGuiLeave();
            #endif
            SyncFolders(ThreadList[i]);
        }
    }
    ThreadList.Empty();
}

bool CFolderSyncer::SyncEntry(int entry)
{

    if(SyncList.GetCount() > entry) {
        wxLogMessage(_("Start Syncing Entrys"));
        #ifndef SHELL_BUILD
        Gui->m_Toolbar->EnableTool(10010,false);
        Gui->m_Toolbar->EnableTool(10033,true);
        #endif

        if(!running) {
            Syncer = new CSyncThread(this, Gui);
            if(SyncList[entry].direction == L"<->") {
                SyncParameters temp = SyncList[entry];
                temp.direction = L"->";
                Syncer->ThreadList.Add(temp);
                temp.direction = L"<-";
                Syncer->ThreadList.Add(temp);
            }
            else
                Syncer->ThreadList.Add(SyncList[entry]);

            wxLogMessage(_("Snycing Thread not running starting thread"));
            Syncer->Create();
            Syncer->SetPriority(Settings.Priority);
            running=true;
            Syncer->Run();
        } else
        {
            if(SyncList[entry].direction == L"<->") {
                SyncParameters temp = SyncList[entry];
                temp.direction = L"->";
                Syncer->ThreadList.Add(temp);
                temp.direction = L"<-";
                Syncer->ThreadList.Add(temp);
            }
            else
                Syncer->ThreadList.Add(SyncList[entry]);
        }
    }
	return true;
}

bool CFolderSyncer::SyncPath(wxString Diection, wxString Dir1, wxString Dir2, bool HiddenFiles, bool DeleteOld) {
    wxLogMessage(_("Start Syncing"));
        #ifndef SHELL_BUILD
        Gui->m_Toolbar->EnableTool(10010,false);
        Gui->m_Toolbar->EnableTool(10033,true);
        #endif
        SyncParameters temp;
        temp.id = -1;
        temp.dir1 = Dir1;
        temp.dir2 = Dir2;
        temp.direction = Diection;
        temp.HiddenFiles = HiddenFiles;
        temp.filter_mode = 0;
        temp.TargedClear = DeleteOld;
        temp.SyncAuto = false;

        if(!running) {
            Syncer = new CSyncThread(this, Gui);
             if(temp.direction == L"<->") {
                temp.direction = L"->";
                Syncer->ThreadList.Add(temp);
                temp.direction = L"<-";
                Syncer->ThreadList.Add(temp);
             }
             else
                Syncer->ThreadList.Add(temp);

            wxLogMessage(_("Snycing Thread not running starting thread"));
            Syncer->Create();
            Syncer->SetPriority(Settings.Priority);
            running=true;
            Syncer->Run();
        } else
        {
            if(temp.direction == L"<->") {
                temp.direction = L"->";
                Syncer->ThreadList.Add(temp);
                temp.direction = L"<-";
                Syncer->ThreadList.Add(temp);
             }
             else
                Syncer->ThreadList.Add(temp);
        }

    return true;
}

void CFolderSyncer::SyncAllEntrys()
{
    if( !SyncList.IsEmpty()) {
        for(int i=0; i<SyncList.GetCount(); i++) {
            SyncEntry(i);
        }
    }
}

void CFolderSyncer::AbortSync()
{
    if(running) {
        Syncer->Delete();
    }
}

bool CFolderSyncer::RemoveEntry(int index)
{
    if( SyncList.GetCount() > index) {
        SyncList.RemoveAt(index);
        ProfileModified = true;
        return true;
    }
    return false;
}

void CFolderSyncer::Notify()
{
    wxDateTime now = wxDateTime::Now();

    //30sec timer checks if this minute was already checked (don't trust minute accureat check on all platforms)
    if( !SyncList.IsEmpty() ) {
        if( now.GetHour() != LastCheck.GetHour() || now.GetMinute() !=  LastCheck.GetMinute() ) {
            for(int i=0; i<SyncList.GetCount(); i++)
                if( SyncList[i].SyncAuto == 1) {
                    if( SyncList[i].time.GetHour() == now.GetHour() && SyncList[i].time.GetMinute() == now.GetMinute() ){
                        wxLogMessage(_("Starting AutoSync (Mode 1 Exact Time)"));
                        SyncEntry(i);
                        SyncList[i].lastSynced = now;
                    }
                }
                else if( SyncList[i].SyncAuto == 2) {
                    //TODO ( init lastchek with HOUR = 0 MINUTE = 0 )
                    if( ((SyncList[i].time.GetHour() * 60) + SyncList[i].time.GetMinute()) >=
                        ((SyncList[i].lastSynced.GetHour() - now.GetHour()) * 60 + SyncList[i].lastSynced.GetMinute() - now.GetMinute())) {
                            wxLogMessage(_("Starting AutoSync(Mode 2 TimeSpan)"));
                            SyncEntry(i);
                            SyncList[i].lastSynced = now;
                    }
                }

            }
            LastCheck = now;
    }
}


bool CFolderSyncer::OpenProfile(wxString file)
{
    CXmlInput In(file);
    if(In.StartReading()) {
        SyncList.Empty();

        ProfileName = In.GetProfileName();
        SyncParameters InP;
        do
        {
            InP.id = In.GetEntryNumber(L"ID");
            InP.dir1 = In.GetEntryValue(L"DIR1");
            InP.dir2 = In.GetEntryValue(L"DIR2");
            InP.direction = In.GetEntryValue(L"DIRECTION");
            InP.TargedClear = In.GetEntryBoolean(L"CLEAR_TARGED");
            InP.SyncAuto = In.GetEntryNumber(L"AUTO_SYNC");
            InP.time = In.GetEntryDate(L"TIME");
            //InP.lastchecked =  In.GetEntryDate(L"LASTCHECKED");
            InP.HiddenFiles =  In.GetEntryBoolean(L"SYNC_HIDDENFILES");
            InP.filter_mode =  In.GetEntryNumber(L"FILTERMODE");
            InP.Filters =  In.GetEntryValue(L"FILTER");
            InP.noTimeCheck =  In.GetEntryBoolean(L"TIMECHECK");

            SyncList.Add(InP);

        } while (In.NextEntry());
        Settings.LastProfile = file;
        return true;

    }
    return false;

}

bool CFolderSyncer::SaveProfile(wxString file)
{
    CXmlOutput Out(file);
    Out.SetRootName(L"SimpleSyncProfile",ProfileName);
    if(!SyncList.IsEmpty()) {
        for ( int i=0; i < SyncList.GetCount(); i++) {
            Out.StartNewEntry( wxString::Format(L"SyncEntryNr%d",i+1) );
            Out.AddNumber(L"ID",SyncList[i].id);
            Out.AddValues(L"DIR1",SyncList[i].dir1);
            Out.AddValues(L"DIR2",SyncList[i].dir2);
            Out.AddValues(L"DIRECTION",SyncList[i].direction);
            Out.AddBoolean(L"CLEAR_TARGED",SyncList[i].TargedClear);
            Out.AddNumber(L"AUTO_SYNC", SyncList[i].SyncAuto);
            Out.AddDateTime(L"TIME",SyncList[i].time);
            //Out.AddDateTime(L"LASTCHECKED",SyncList[i].lastchecked);
            Out.AddBoolean(L"SYNC_HIDDENFILES",SyncList[i].HiddenFiles);
            Out.AddNumber(L"FILTERMODE",SyncList[i].filter_mode);
            Out.AddValues(L"FILTER", SyncList[i].Filters);
            Out.AddBoolean(L"TIMECHECK",SyncList[i].noTimeCheck);
            Out.EndNewEntry();
        }
        bool ret = Out.SaveXmlFile();
        if ( ret ) {
            Settings.LastProfile = file;
            ProfileModified = false;
        }
        return ret;
    }
    return false;
}

bool CFolderSyncer::OpenSettings(wxString Path)
{
    CXmlInput In(Path);
    if(In.StartReading()) {
        // = In.GetProfileName();
        int i = In.GetEntryNumber(L"IN_TRAY");
        if(i == 1)
            Settings.InTray = Tray::MINIMIZE;
        else if(i == 2)
            Settings.InTray = Tray::CLOSE;
        else
            Settings.InTray = Tray::NONE;

        Settings.ShowStatusbar = In.GetEntryBoolean(L"SHOW_STATUSBAR");
        Settings.Priority = In.GetEntryNumber(L"PRIORITY");
        Settings.AutoSync = In.GetEntryBoolean(L"AUTO_SYNC");
        Settings.AutoOpenProfile = In.GetEntryBoolean(L"AUTO_OPEN_PROFILE");
        Settings.LastProfile = In.GetEntryValue(L"LAST_PROFILE");
        Settings.StartasTray = In.GetEntryBoolean(L"START_AS_TRAY");
        Settings.WriteLogfile = In.GetEntryBoolean(L"WRITE_LOGFILE");
        return true;
    }
    return false;
}

bool CFolderSyncer::SaveSettings(wxString Path)
{
    CXmlOutput Out(Path);
    Out.SetRootName(L"wxSimpleSyncSettings",L"wxSimpleSync");
    if(Out.IsOpen()) {
        int i = Settings.InTray;

        Out.StartNewEntry(L"Settings");
        Out.AddNumber(L"IN_TRAY", i);
        Out.AddBoolean(L"SHOW_STATUSBAR", Settings.ShowStatusbar);
        Out.AddNumber(L"PRIORITY",Settings.Priority);
        Out.AddBoolean(L"AUTO_SYNC",Settings.AutoSync);
        Out.AddBoolean(L"AUTO_OPEN_PROFILE",Settings.AutoOpenProfile);
        Out.AddValues(L"LAST_PROFILE",Settings.LastProfile);
        Out.AddBoolean(L"START_AS_TRAY",Settings.StartasTray);
        Out.AddBoolean(L"WRITE_LOGFILE",Settings.WriteLogfile);
        Out.EndNewEntry();

        return Out.SaveXmlFile();
    }
    return false;
}
