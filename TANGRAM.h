///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/scrolbar.h>
#include <wx/frame.h>
#include <wx/radiobut.h>
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame
{
private:

protected:
	wxPanel* menu;
	wxButton* symetria;
	wxStaticText* staticTextObrotLewo;
	wxScrollBar* obrotPrawo;
	wxStaticText* staticTextObrotLewoWartosc;
	wxStaticText* staticTextObrotPrawo;
	wxScrollBar* obrotLewo;
	wxStaticText* staticTextObrotPrawoWartosc;
	wxButton* clean;
	wxStaticText* instrukcja1;
	wxStaticText* instrukcja2;
	wxStaticText* instrukcja3;
	wxStaticText* instrukcja4;
	wxStaticText* instrukcja5;
	wxPanel* ksztalt;
	wxButton* start;
	wxStaticText* wybierzKat;
	wxRadioButton* stopnie45;
	wxRadioButton* stopnie90;
	wxRadioButton* stopnie135;
	wxRadioButton* stopnie180;
	wxRadioButton* stopnie235;
	wxRadioButton* stopnie270;
	wxRadioButton* stopnie315;
	// Virtual event handlers, overide them in your derived class
	virtual void MouseClick(wxMouseEvent& event) { event.Skip(); }
	virtual void MouseUp(wxMouseEvent& event) { event.Skip(); }
	virtual void MouseMotion(wxMouseEvent& event) { event.Skip(); }
	virtual void symetriaButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void obrotPrawoUpdate(wxScrollEvent& event) { event.Skip(); }
	virtual void KeyEvent(wxKeyEvent& event) { event.Skip(); }
	virtual void obrotLewoUpdate(wxScrollEvent& event) { event.Skip(); }
	virtual void cleanButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void startButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void UpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void stopnie45Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie90Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie135Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie180Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie235Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie270Button(wxCommandEvent& event) { event.Skip(); }
	virtual void stopnie315Button(wxCommandEvent& event) { event.Skip(); }

public:

	Frame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("TANGRAM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1213, 751), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~Frame();

};