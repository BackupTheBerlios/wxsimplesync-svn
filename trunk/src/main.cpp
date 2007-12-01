#define SHELL_BUILD

#include "csync.h"
#include <wx/dynarray.h>
#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/tokenzr.h>
#include <iostream>
#include <wx/app.h>
#include <wx/cmdline.h>



//#include "clogging.h"
class DerivedApp : public wxApp {
public:
  virtual bool OnInit();
  wxLocale m_locale;
  CFolderSyncer *Syncer;
  CLogging *logger;
};
IMPLEMENT_APP(DerivedApp)
bool DerivedApp::OnInit()
{
    //SyncParameters lol3;
	//lol3.id=1;
	//lol3.time = wxDateTime::Now();
	//lol3.noTimeCheck =  lol3.time.IsValid();
	SetAppName(wxT("wxSimpleSync"));
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

	static const wxCmdLineEntryDesc cmdLineDesc[] =
    {
        { wxCMD_LINE_SWITCH, L"->", _("right"), _("the syncing direction (folder1 -> fodler2)")},
        { wxCMD_LINE_SWITCH, L"<-", _("left"),   _("the syncing direction (folder1 <- fodler2)") },
        { wxCMD_LINE_SWITCH, L"<->", _("both"),   _("the syncing direction (folder1 <-> fodler2)") },

        { wxCMD_LINE_OPTION, L"f1", _("folder1"),  _("first sync folder ") },
        { wxCMD_LINE_OPTION, L"f2", _("folder2"),   _("second sync folder") },

        { wxCMD_LINE_NONE }
    };

    parser.SetDesc(cmdLineDesc);

    if(parser.Parse() != 0)
        return false;




	logger = new CLogging(wxT("log.txt"));
	wxLog::SetActiveTarget(logger);
	logger->LogMessage(wxT("wxSimpleSync Shell Version Started"));
	Syncer = new CFolderSyncer(logger);



	Syncer->OpenProfile(L"profile.xml");

    Syncer->SyncEntry(0);


    return true;
}



/*
int main()
{
	//more tests
	SyncParameters lol3;
	lol3.id=1;
	//SyncList.Add(lol);
	//std::cout << SyncList[0].id << std::endl;
	//std::cout << SyncList.GetCount();

	CLogging logger(wxT("log.txt"));
	logger.LogMessage(wxT("Logging works"));
	CFolderSyncer Syncer(&logger);

	Syncer.SyncList.Add(lol3);
	Syncer.SaveProfiel(L"profiel.xml");
	Syncer.OpenProfiel(L"profiel.xml");

	CXmlOutput lol(wxT("lol.xml"));
	lol.SetRootName(wxT("SimpleSyncProfiel"));
	lol.StartNewEntry(wxT("first"));
	lol.AddValues(wxT("Vaule"),wxT("1"));
	lol.EndNewEntry();

//test wxdate
	wxDateTime ts = wxDateTime::Now();
	std::cout << wxDateTime::GetWeekDayName(ts.GetWeekDay()).mb_str();
	std::cout << std::endl << wxDateTime::GetMonthName(ts.GetMonth()).mb_str() << std::endl; //= Numer from 1 Monday - 6 Saturday and Sunday=0


	lol.StartNewEntry(wxT("second"));
	lol.AddValues(wxT("lol2"),wxT("lol2"));
	lol.AddDateTime(L"datum",ts);
	lol.AddBoolean(L"BOOL",false);
	lol.AddNumber(L"hm",3445);
	lol.EndNewEntry();

	lol.SaveXmlFile();

	CXmlInput lol2(wxT("lol.xml"));
	lol2.StartReading();

	std::cout << lol2.GetProfileName().mb_str();
	lol2.NextEntry();
	std::cout << lol2.GetEntryValue(wxT("lol2")).mb_str();
	logger.LogMessage(lol2.GetEntryValue(wxT("lol2")));

	logger.LogMessage(lol2.GetEntryDate(wxT("datum")).FormatISODate());
	std::cout << std::endl << lol2.GetEntryBoolean(L"BOOL");
	std::cout << std::endl << lol2.GetEntryNumber(L"hm");


	return 0;
}
*/
