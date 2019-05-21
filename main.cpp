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
 wxImage::AddHandler(new wxPNGHandler);            // z jakich bedziemy korzytsac
 wxImage image;
 {
	 if (!image.LoadFile("0.png"))
	 {
		 wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 obrazka"));
		 mainFrame->Destroy();
		 return true;
	 }
	 else
	 {
		 mainFrame->ksztaltImage = image.Copy();              // Kopiujemy obrazek do Img_Org
	 }
 }
 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}