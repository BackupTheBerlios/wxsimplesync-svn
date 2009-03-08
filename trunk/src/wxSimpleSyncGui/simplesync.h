/////////////////////////////////////////////////////////////////////////////
// Name:        simplesync.h
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

#ifndef _SIMPLESYNC_H_
#define _SIMPLESYNC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "simplesync.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "simplesyncdlg.h"
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
////@end control identifiers

/*!
 * SimpleSyncApp class declaration
 */




class SimpleSyncApp: public wxApp
{
    DECLARE_CLASS( SimpleSyncApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    SimpleSyncApp();

    /// Initialises member variables
    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

    wxLocale m_locale;

    CLogging *logger;
    CFolderSyncer *Syncer;

////@begin SimpleSyncApp event handler declarations

////@end SimpleSyncApp event handler declarations

////@begin SimpleSyncApp member function declarations

////@end SimpleSyncApp member function declarations

////@begin SimpleSyncApp member variables
////@end SimpleSyncApp member variables

};

/*!
 * Application instance declaration
 */

////@begin declare app
DECLARE_APP(SimpleSyncApp)
////@end declare app

#endif
    // _SIMPLESYNC_H_
