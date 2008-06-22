/////////////////////////////////////////////////////////////////////////////
// Name:        foldercomparedlg.cpp
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
#pragma implementation "foldercomparedlg.h"
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

#include "foldercomparedlg.h"
#include <wx/dir.h>
#include <wx/filename.h>

////@begin XPM images
////@end XPM images


/*!
 * FolderCompareDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( FolderCompareDlg, wxDialog )


/*!
 * FolderCompareDlg event table definition
 */

BEGIN_EVENT_TABLE( FolderCompareDlg, wxDialog )

////@begin FolderCompareDlg event table entries
    EVT_BUTTON( ID_BUTTON_COMPARE, FolderCompareDlg::OnButtonCompareClick )

////@end FolderCompareDlg event table entries

END_EVENT_TABLE()


/*!
 * FolderCompareDlg constructors
 */

FolderCompareDlg::FolderCompareDlg()
{
    Init();
}

FolderCompareDlg::FolderCompareDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * FolderCompareDlg creator
 */

bool FolderCompareDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin FolderCompareDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end FolderCompareDlg creation
    return true;
}


/*!
 * FolderCompareDlg destructor
 */

FolderCompareDlg::~FolderCompareDlg()
{
////@begin FolderCompareDlg destruction
////@end FolderCompareDlg destruction
}


/*!
 * Member initialisation
 */

void FolderCompareDlg::Init()
{
////@begin FolderCompareDlg member initialisation
    m_dir1 = NULL;
    m_dir2 = NULL;
////@end FolderCompareDlg member initialisation
}


/*!
 * Control creation for FolderCompareDlg
 */

void FolderCompareDlg::CreateControls()
{
////@begin FolderCompareDlg content construction
    FolderCompareDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxButton* itemButton4 = new wxButton( itemDialog1, ID_BUTTON_COMPARE, _("Compare Folders"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemButton4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton5 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemButton5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer6, 1, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer6->Add(itemBoxSizer7, 1, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("Files only in Dir1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(itemStaticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_dir1 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    itemBoxSizer7->Add(m_dir1, 2, wxGROW|wxALL, 1);

    wxBoxSizer* itemBoxSizer10 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer6->Add(itemBoxSizer10, 1, wxGROW|wxALL, 0);

    wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("Files Only in Dir2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer10->Add(itemStaticText11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_dir2 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL2, _T(""), wxDefaultPosition, wxSize(300, 400), wxTE_MULTILINE );
    itemBoxSizer10->Add(m_dir2, 2, wxGROW|wxALL, 1);

////@end FolderCompareDlg content construction
}


/*!
 * Should we show tooltips?
 */

bool FolderCompareDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap FolderCompareDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin FolderCompareDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end FolderCompareDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon FolderCompareDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin FolderCompareDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end FolderCompareDlg icon retrieval
}


void FolderCompareDlg::CompareFolders() {
    wxDir dir1;
    wxDir dir2;
    //Open directories
    dir1.Open(Dir1);
    dir2.Open(Dir2);
    //check if both are accesable
    if ( !dir1.IsOpened() || !dir2.IsOpened() || !wxDirExists(Dir1) || !wxDirExists(Dir2))
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return;
    }
    #if defined(__WXGTK__) || defined(__WXX11)
    struct stat att;
    wxString tmp;
    #endif

    int flags = wxDIR_FILES | wxDIR_DIRS  | wxDIR_HIDDEN;

    wxString filename,filespec,Sep,temp;
    wxFileName sep;
    Sep = sep.GetPathSeparator(); // MAKE CLASS GLOBAL (PERFORMANCE)

        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
                #if defined(__WXGTK__) || defined(__WXX11)
                tmp = Dir1 + Sep + filename;
                lstat(tmp.fn_str(),&att);
                if(!S_ISLNK(att.st_mode)) {
                #endif
                if(wxDirExists(Dir1 + Sep + filename))
                {
                    if(!wxDirExists(Dir2 + Sep + filename)) {
                        m_dir1->AppendText(L"[DIR]" +filename + L"\n");
                    }
                    else
                    {
                        CompareFoldersR(filename, Dir1 + Sep + filename, Dir2 + Sep + filename, L">");
                    }
                }
                else
                {
                    if(!wxFileExists(Dir2 + Sep + filename))
                    {
                         m_dir1->AppendText(filename + L"\n");
                    }
                }
                #if defined(__WXGTK__) || defined(__WXX11)
                } else {
                    tmp = Dir2 + Sep + filename;
                    if(lstat(tmp.fn_str(),&att) == -1 || !S_ISLNK(att.st_mode)) {
                        m_dir1->AppendText(L"[LINK]" + filename + L"\n");
                    }
                }
                #endif


                cont = dir1.GetNext(&filename);
        }

        cont = dir2.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
                #if defined(__WXGTK__) || defined(__WXX11)
                tmp = Dir2 + Sep + filename;
                lstat(tmp.fn_str(),&att);
                if(!S_ISLNK(att.st_mode)) {
                #endif
                if(wxDirExists(Dir2 + Sep + filename))
                {
                    if(!wxDirExists(Dir1 + Sep + filename)) {
                        m_dir2->AppendText(L"[DIR]" +filename + L"\n");
                    }
                    else
                    {
                         CompareFoldersR(filename, Dir1 + Sep + filename, Dir2 + Sep + filename, L"<");
                    }
                }
                else
                {
                    if(!wxFileExists(Dir1 + Sep + filename))
                    {
                         m_dir2->AppendText(filename + L"\n");
                    }
                }
                #if defined(__WXGTK__) || defined(__WXX11)
                } else {
                    tmp = Dir1 + Sep + filename;
                    if(lstat(tmp.fn_str(),&att) == -1 || !S_ISLNK(att.st_mode)) {
                        m_dir2->AppendText(L"[LINK]" + filename + L"\n");
                    }
                }
                #endif

                cont = dir2.GetNext(&filename);

        }

}


void FolderCompareDlg::CompareFoldersR(wxString folder, wxString Dir_1,wxString Dir_2, wxString direction) {
    wxDir dir1;
    wxDir dir2;
    //Open directories
    dir1.Open(Dir_1);
    dir2.Open(Dir_2);
    //check if both are accesable
    if ( !dir1.IsOpened() || !dir2.IsOpened() || !wxDirExists(Dir_1) || !wxDirExists(Dir_2))
    {
        // deal with the error here - wxDir would already log an error message
        // explaining the exact reason of the failure
        return;
    }
    #if defined(__WXGTK__) || defined(__WXX11)
    struct stat att;
    wxString tmp;
    #endif

    int flags = wxDIR_FILES | wxDIR_DIRS  | wxDIR_HIDDEN;

    wxString filename,filespec,Sep,temp;
    wxFileName sep;
    Sep = sep.GetPathSeparator(); // MAKE CLASS GLOBAL (PERFORMANCE)

    if(direction == L">") {
        bool cont = dir1.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
                #if defined(__WXGTK__) || defined(__WXX11)
                tmp = Dir_1 + Sep + filename;
                lstat(tmp.fn_str(),&att);
                if(!S_ISLNK(att.st_mode)) {
                #endif
                if(wxDirExists(Dir_1 + Sep + filename))
                {
                    if(!wxDirExists(Dir_2 + Sep + filename)) {
                        m_dir1->AppendText(L"[DIR]" + folder +Sep+ filename + L"\n");
                    }
                    else
                    {
                        CompareFoldersR(folder + Sep + filename,Dir_1 + Sep + filename,Dir_2 + Sep + filename, L">");
                    }
                }
                else
                {
                    if(!wxFileExists(Dir_2 + Sep + filename))
                    {
                         m_dir1->AppendText(folder +Sep+ filename + L"\n");
                    }
                }
                #if defined(__WXGTK__) || defined(__WXX11)
                } else {
                    tmp = Dir_2 + Sep + filename;
                    if(lstat(tmp.fn_str(),&att) == -1 || !S_ISLNK(att.st_mode)) {
                        m_dir1->AppendText(L"[LINK]" + filename + L"\n");
                    }
                }
                #endif

                cont = dir1.GetNext(&filename);
        }


    }
    else if( direction == L"<") {
        bool cont = dir2.GetFirst(&filename, filespec, flags);
        while ( cont )
        {
                #if defined(__WXGTK__) || defined(__WXX11)
                tmp = Dir_2 + Sep + filename;
                lstat(tmp.fn_str(),&att);
                if(!S_ISLNK(att.st_mode)) {
                #endif
                if(wxDirExists(Dir_2 + Sep + filename))
                {
                    if(!wxDirExists(Dir_1 + Sep + filename)) {
                        m_dir2->AppendText(L"[DIR]" +folder +Sep+ filename + L"\n");
                    }
                    else
                    {
                        CompareFoldersR(folder + Sep + filename,Dir_1 + Sep + filename,Dir_2 + Sep + filename, L"<");
                    }
                }
                else
                {
                    if(!wxFileExists(Dir_1 + Sep + filename))
                    {
                         m_dir2->AppendText(folder +Sep+ filename + L"\n");
                    }
                }
                #if defined(__WXGTK__) || defined(__WXX11)
                } else {
                    tmp = Dir_1 + Sep + filename;
                    if(lstat(tmp.fn_str(),&att) == -1 || !S_ISLNK(att.st_mode)) {
                        m_dir2->AppendText(L"[LINK]" + filename + L"\n");
                    }
                }
                #endif

                cont = dir2.GetNext(&filename);

        }
    }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTOn_COMPARE
 */

void FolderCompareDlg::OnButtonCompareClick( wxCommandEvent& event )
{
    m_dir1->Clear();
    m_dir2->Clear();
    CompareFolders();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTOn_COMPARE in FolderCompareDlg.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTOn_COMPARE in FolderCompareDlg.
}

