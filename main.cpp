#include <wx/wx.h>
#include "TANGRAMFrame.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	TANGRAMFrame *mainFrame = new TANGRAMFrame(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}