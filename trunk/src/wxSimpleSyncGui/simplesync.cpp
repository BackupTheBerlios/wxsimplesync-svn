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
	SimpleSyncDlg* mainWindow = new SimpleSyncDlg( NULL, ID_SIMPLESYNCDLG );
	mainWindow->Show(true);
//	glob = mainWindow;
////@end SimpleSyncApp initialisation

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

