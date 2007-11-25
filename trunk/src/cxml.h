/////////////////////////////////////////////////////////////////////////////
// Name:        cxml.h
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


#include <wx/xml/xml.h>
#include <wx/tokenzr.h>

class CXmlOutput
{
public:
    CXmlOutput(wxString file)
    {   FileName = file; };

    void SetRootName(wxString Name, wxString PropFName = L"")
    {
     root = new wxXmlNode(wxXML_ELEMENT_NODE, Name);

      if(PropFName != L"")
      root->AddProperty(new wxXmlProperty(wxT("Name"), PropFName));

      doc.SetRoot(root);
    };

    void StartNewEntry(wxString Name) {
        node =  new wxXmlNode(wxXML_ELEMENT_NODE, Name);
    }
    void AddValues(wxString Name, wxString Value) {
        wxXmlNode *node2 = new wxXmlNode(wxXML_ELEMENT_NODE, Name);
        node->AddChild(node2);
        node2->AddChild(new wxXmlNode(wxXML_TEXT_NODE, Name ,Value));
    }

    void AddNumber(wxString Name, int Value) {
        wxXmlNode *node2 = new wxXmlNode(wxXML_ELEMENT_NODE, Name);
        node->AddChild(node2);
        node2->AddChild(new wxXmlNode(wxXML_TEXT_NODE, Name ,wxString::Format(L"%d",Value)));
    }

    void AddBoolean(wxString Name, bool Value) {
        wxXmlNode *node2 = new wxXmlNode(wxXML_ELEMENT_NODE, Name);
        node->AddChild(node2);
        if(Value)
        node2->AddChild(new wxXmlNode(wxXML_TEXT_NODE, Name , wxT("true")));
        else
        node2->AddChild(new wxXmlNode(wxXML_TEXT_NODE, Name , wxT("false")));
    }

    void AddDateTime(wxString Name, wxDateTime dt) {
        wxXmlNode *node2 = new wxXmlNode(wxXML_ELEMENT_NODE, Name);
        node->AddChild(node2);
        wxString date;
        date.Printf(L"%d:%d:%d:%d:%d:%d",dt.GetDay(), dt.GetMonth(), dt.GetYear(), dt.GetHour(), dt.GetMinute(), dt.GetSecond());
        node2->AddChild(new wxXmlNode(wxXML_TEXT_NODE, Name ,date));
    }


    void EndNewEntry() {
        root->AddChild(node);
    }

    bool SaveXmlFile()
    { return doc.Save(FileName);  };

    bool IsOpen()
    { return doc.IsOk(); }



private:
    wxString FileName;
    wxXmlDocument doc;
    wxXmlNode *root,*node;
};

class CXmlInput
{
public:

    CXmlInput(wxString file)
    {   FileName = file; };

    bool StartReading() {
        if (!doc.Load(FileName)) return false;
        if(doc.GetRoot()->HasProp(L"Name"))
        Name = doc.GetRoot()->GetProperties()->GetValue();
        root = doc.GetRoot();
        node = root->GetChildren();
        return true;
    }

    wxString GetEntryValue(wxString Name) {
        wxXmlNode* temp = node->GetChildren();
        while (temp) {
            if(temp->GetName() == Name)
             return temp->GetNodeContent();
            temp = temp->GetNext();
        }
        return L"";
    }

    int GetEntryNumber(wxString Name) {
        wxXmlNode* temp = node->GetChildren();
        while (temp) {
            if(temp->GetName() == Name) {
             long  int a;
             temp->GetNodeContent().ToLong(&a);
             return a;
            }
            temp = temp->GetNext();
        }
        return 0;
    }

    bool GetEntryBoolean(wxString Name) {
        wxXmlNode* temp = node->GetChildren();
        while (temp) {
            if(temp->GetName() == Name) {
             if(temp->GetNodeContent() == wxT("1") || temp->GetNodeContent() == wxT("true"))
             return true;
             else
             return false;
            }
            temp = temp->GetNext();
        }
    }

    wxDateTime GetEntryDate(wxString Name) {
        wxXmlNode* temp = node->GetChildren();
        while (temp) {
            if(temp->GetName() == Name) {
                long int num;
                wxDateTime dt;
                wxStringTokenizer tkz(temp->GetNodeContent(), wxT(":"));

                wxString token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetDay(num);
                token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetMonth( (wxDateTime::Month) num);
                token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetYear(num);
                token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetHour(num);
                token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetMinute(num);
                token = tkz.GetNextToken();
                token.ToLong(&num);
                dt.SetSecond(num);

                return dt;
            }
            temp = temp->GetNext();
        }
    }

    bool NextEntry() {
        node = node->GetNext();
        if (node) return true;
        else return false;
    }



    wxString GetProfileName() { return Name; }

    private:
    wxString FileName;
    wxString Name;
    wxXmlDocument doc;
    wxXmlNode *root,*node;
};
