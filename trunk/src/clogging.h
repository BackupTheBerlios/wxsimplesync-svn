/////////////////////////////////////////////////////////////////////////////
// Name:        clogging.h
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
#include <wx/textfile.h>
#include <wx/datetime.h>


//TODO a initial check if file exists andis already over MAXLOGLINES

class CLogging : public wxLog
{

public:

	CLogging()
	{MaxLogLines=90000; LogFile.Create(wxT("log.txt")); LogFile.Open(wxT("log.txt"),wxConvUTF8); };
	CLogging(wxString File, size_t MaxLinesCount = 90000)
	{MaxLogLines=MaxLinesCount; LogFile.Create(File); LogFile.Open(File,wxConvUTF8); };
	~CLogging() { LogFile.Close();};

	void LogMessage(wxString message)
	{ Time = wxDateTime::Now(); CheckSize(); LogFile.AddLine(Time.FormatISODate() + wxT(" ") + Time.FormatISOTime() + _(" Message: ") + message); LogFile.Write(); };
	void LogError(wxString error)
	{ Time = wxDateTime::Now(); CheckSize(); LogFile.AddLine(Time.FormatISODate() + wxT(" ") + Time.FormatISOTime() + _(" Error: ") + error); LogFile.Write();};

	void CheckSize()
	{ if(LogFile.GetLineCount() > MaxLogLines) {
        LogFile.RemoveLine(0);
        }
    };

    virtual void DoLogString(const wxChar *msg, time_t timestamp) {
        LogMessage(msg);
    }

protected:
    wxDateTime Time;
    size_t MaxLogLines;
	wxTextFile LogFile;
};
