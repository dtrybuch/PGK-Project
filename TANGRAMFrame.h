#ifndef __TANGRAMFrame__
#define __TANGRAMFrame__

/**
@file
Subclass of Frame, which is generated by wxFormBuilder.
*/

#include "TANGRAM.h"

//// end generated include
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <memory>
#include"Element.h"
#include<cstdlib>
#include<time.h>
/** Implementing Frame */
class TANGRAMFrame : public Frame
{

	protected:
			// Handlers for Frame events.
			void MouseClick(wxMouseEvent& event);
			void MouseMotion(wxMouseEvent& event);
			void symetriaButtonClick(wxCommandEvent& event);
			void obrotPrawoUpdate(wxScrollEvent& event);
			void KeyEvent(wxKeyEvent& event);
			void obrotLewoUpdate(wxScrollEvent& event);
			void cleanButtonClick(wxCommandEvent& event);
			void losujButtonClick(wxCommandEvent& event);
			void UpdateUI(wxUpdateUIEvent& event);
			void losowanie();
		public:
			/** Constructor */
			TANGRAMFrame(wxWindow* parent);
			//// end generated class members

		void DrawFish(wxDC *dc, int w ,int h);
		void Draw();
		wxImage ksztaltImage;
		int wylosowana;
protected:
	Triangle bigTriangle;
	Square square;

};

#endif // __TANGRAMFrame__
