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
	void MouseClick(wxMouseEvent& event); //22.05
	void MouseUp(wxMouseEvent& event); //22.05
	void MouseMotion(wxMouseEvent& event);
	void symetriaButtonClick(wxCommandEvent& event);
	void obrotPrawoUpdate(wxScrollEvent& event);
	void KeyEvent(wxKeyEvent& event);
	void obrotLewoUpdate(wxScrollEvent& event);
	void cleanButtonClick(wxCommandEvent& event);
	void startButtonClick(wxCommandEvent& event);
	void UpdateUI(wxUpdateUIEvent& event);
	void losowanie();
	void stopnie45Button(wxCommandEvent& event);
	void stopnie90Button(wxCommandEvent& event);
	void stopnie135Button(wxCommandEvent& event);
	void stopnie180Button(wxCommandEvent& event);
	void stopnie235Button(wxCommandEvent& event);
	void stopnie270Button(wxCommandEvent& event);
	void stopnie315Button(wxCommandEvent& event);
public:
	/** Constructor */
	TANGRAMFrame(wxWindow* parent);
	//// end generated class members

	void DrawFish(wxDC *dc, int w, int h);
	void Draw();
	wxImage ksztaltImage;
	int wylosowana;
	Element * which;//ktory element jest nacisniety
protected:

	//edited 21.05
	Triangle bigTriangle1;
	Triangle bigTriangle2;
	Triangle middleTriangle;
	Triangle smallTriangle1;
	Triangle smallTriangle2;
	Square square;
	Parallelogram parallelogram;
	wxPoint firstMousePosition;
	int menuWidth;//poprzednia szerokosc okna
	int menuHeight;//poprzednia dlugosc okna
	//end editing

};

#endif // __TANGRAMFrame__