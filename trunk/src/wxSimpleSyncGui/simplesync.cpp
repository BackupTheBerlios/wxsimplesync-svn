/////////////////////////////////////////////////////////////////////////////
// Name:        simplesync.cpp
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

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "simplesync.h"
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

#include "simplesync.h"
#include <wx/cmdline.h>

////@begin XPM images
////@end XPM images



/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( SimpleSyncApp )
////@end implement app

/*!
 * SimpleSyncApp type definition
 */

IMPLEMENT_CLASS( SimpleSyncApp, wxApp )

/*!
 * SimpleSyncApp event table definition
 */

BEGIN_EVENT_TABLE( SimpleSyncApp, wxApp )

////@begin SimpleSyncApp event table entries
////@end SimpleSyncApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for SimpleSyncApp
 */

SimpleSyncApp::SimpleSyncApp()
{
    Init();
}

/*!
 * Member initialisation
 */

void SimpleSyncApp::Init()
{
////@begin SimpleSyncApp member initialisation
////@end SimpleSyncApp member initialisation
}
/*!
 * Initialisation for SimpleSyncApp
 */

bool SimpleSyncApp::OnInit()
{
    wxLocale::AddCatalogLookupPathPrefix(wxT("recources/languages"));


#ifdef __LINUX__
    {
        wxLogNull noLog;
        m_locale.AddCatalog(_T("fileutils"));
    }
#endif

    m_locale.Init(wxLANGUAGE_DEFAULT, wxLOCALE_LOAD_DEFAULT | wxLOCALE_CONV_ENCODING);

    m_locale.AddCatalog(wxT("wxSimpleSync"));

    wxCmdLineParser parser;
	parser.SetCmdLine(this->argc,this->argv);
    wxLogNull logNo;
	wxMessageOutput* old = wxMessageOutput::Set(new wxMessageOutputStderr);

    static const wxCmdLineEntryDesc cmdLineDesc[] =
    {
        { wxCMD_LINE_PARAM,  NULL, NULL, _("input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_NONE },
        { wxCMD_LINE_SWITCH, _("d"), _("daemon"), _("Start wxSS without GUI in Deamon mode")},
        { wxCMD_LINE_NONE }
    };


    parser.SetDesc(cmdLineDesc);

    logger = new CLogging(wxT("log.txt"));
	wxLog::SetActiveTarget(logger);


    wxString ProfilePath;
    if( wxString(argv[1]).Left(1) != _("-") &&  wxFileExists(argv[1])) {
        ProfilePath = wxString(argv[1]);
    }


    if(parser.Parse(false) != 0) {
        parser.SetLogo(_("wxSimpleSync Version 2.0"));
        parser.Usage();
        return false;
    }

    bool DeamonMode = false;

    //RUN IN DEAMON MODE
    if(parser.Found(L"d")) {
        Syncer = new CFolderSyncer(logger);

        if(!Syncer->OpenSettings(wxT("wxSimpleSyncSettings.xml"))) {
            logger->LogMessage(_("Could not Load Setting file wxSimpleSyncSettings.xml taking default settings"));
            Syncer->Settings.AutoOpenProfile = false;
            Syncer->Settings.AutoSync = true;
            Syncer->Settings.InTray = Tray::MINIMIZE;
            Syncer->Settings.Priority = WXTHREAD_DEFAULT_PRIORITY;
            Syncer->Settings.ShowStatusbar = true;
            Syncer->Settings.StartasTray = false;
            Syncer->Settings.WriteLogfile = true;
        }

        if(!Syncer->Settings.AutoSync)
            Syncer->StopAutoSync();

        if(ProfilePath != wxT("")) {
            Syncer->OpenProfile(wxFileName(ProfilePath).GetFullPath());
        }
        else if(Syncer->Settings.AutoOpenProfile) {
            Syncer->OpenProfile(Syncer->Settings.LastProfile);
        }
        else {
            logger->LogError(_("Can't run in Deamon mode without a Profile, Closeing!"));
            parser.Usage();
            return false;
        }
        DeamonMode = true;
    }

    if(!DeamonMode) {
    ////@begin SimpleSyncApp initialisation
        // Remove the comment markers above and below this block
        // to make permanent changes to the code.

    #if wxUSE_XPM
        wxImage::AddHandler(new wxXPMHandler);
    #endif
    #if wxUSE_LIBPNG
        wxImage::AddHandler(new wxPNGHandler);
    #endif
    #if wxUSE_LIBJPEG
        wxImage::AddHandler(new wxJPEGHandler);
    #endif
    #if wxUSE_GIF
        wxImage::AddHandler(new wxGIFHandler);
    #endif
        SimpleSyncDlg* mainWindow = new SimpleSyncDlg( NULL, ID_SIMPLESYNCDLG , ProfilePath);
        mainWindow->Show(true);
    //	glob = mainWindow;
    ////@end SimpleSyncApp initialisation
    }

    return true;
}

/*!
 * Cleanup for SimpleSyncApp
 */
int SimpleSyncApp::OnExit()
{
////@begin SimpleSyncApp cleanup
	return wxApp::OnExit();
////@end SimpleSyncApp cleanup
}

