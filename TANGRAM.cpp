///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TANGRAM.h"

///////////////////////////////////////////////////////////////////////////

Frame::Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer(wxVERTICAL);

	menu = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer91->Add(menu, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxHORIZONTAL);

	symetria = new wxButton(this, wxID_ANY, wxT("Symetria"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(symetria, 0, wxALIGN_CENTER | wxALL, 5);

	staticTextObrotLewo = new wxStaticText(this, wxID_ANY, wxT("Obrot w lewo:"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextObrotLewo->Wrap(-1);
	bSizer11->Add(staticTextObrotLewo, 0, wxALL, 10);

	obrotLewo = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL);
	bSizer11->Add(obrotLewo, 0, wxALIGN_CENTER | wxALL, 5);

	staticTextObrotLewoWartosc = new wxStaticText(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextObrotLewoWartosc->Wrap(-1);
	bSizer11->Add(staticTextObrotLewoWartosc, 0, wxALL, 10);

	staticTextObrotPrawo = new wxStaticText(this, wxID_ANY, wxT("Obrot w prawo:"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextObrotPrawo->Wrap(-1);
	bSizer11->Add(staticTextObrotPrawo, 0, wxALL, 10);

	obrotPrawo = new wxScrollBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL);
	bSizer11->Add(obrotPrawo, 0, wxALIGN_CENTER | wxALL, 5);

	staticTextObrotPrawoWartosc = new wxStaticText(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0);
	staticTextObrotPrawoWartosc->Wrap(-1);
	bSizer11->Add(staticTextObrotPrawoWartosc, 0, wxALL, 10);

	clean = new wxButton(this, wxID_ANY, wxT("Clean"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(clean, 0, wxALIGN_CENTER | wxALL, 5);

	zmienKolorButton = new wxButton(this, wxID_ANY, wxT("Zmien kolor"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer11->Add(zmienKolorButton, 0, wxALL, 5);

	bSizer91->Add(bSizer11, 0, wxALIGN_CENTER, 5);


	bSizer10->Add(bSizer91, 5, wxEXPAND, 5);

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer(wxVERTICAL);

	instrukcja1 = new wxStaticText(this, wxID_ANY, wxT("Celem gry jest"), wxDefaultPosition, wxDefaultSize, 0);
	instrukcja1->Wrap(-1);
	bSizer101->Add(instrukcja1, 0, wxALIGN_CENTER | wxALL, 5);

	instrukcja2 = new wxStaticText(this, wxID_ANY, wxT("ulozenie ponizszej"), wxDefaultPosition, wxDefaultSize, 0);
	instrukcja2->Wrap(-1);
	bSizer101->Add(instrukcja2, 0, wxALIGN_CENTER | wxALL, 5);

	instrukcja3 = new wxStaticText(this, wxID_ANY, wxT("figury za pomoca"), wxDefaultPosition, wxDefaultSize, 0);
	instrukcja3->Wrap(-1);
	bSizer101->Add(instrukcja3, 0, wxALIGN_CENTER | wxALL, 5);

	instrukcja4 = new wxStaticText(this, wxID_ANY, wxT("kart znajdujacych"), wxDefaultPosition, wxDefaultSize, 0);
	instrukcja4->Wrap(-1);
	bSizer101->Add(instrukcja4, 0, wxALIGN_CENTER | wxALL, 5);

	instrukcja5 = new wxStaticText(this, wxID_ANY, wxT("sie w polu obok."), wxDefaultPosition, wxDefaultSize, 0);
	instrukcja5->Wrap(-1);
	bSizer101->Add(instrukcja5, 0, wxALIGN_CENTER | wxALL, 5);

	ksztalt = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	bSizer101->Add(ksztalt, 1, wxEXPAND | wxALL, 5);

	start = new wxButton(this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer101->Add(start, 0, wxALIGN_CENTER | wxBOTTOM, 100);


	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer(wxVERTICAL);

	wybierzKat = new wxStaticText(this, wxID_ANY, wxT("Wybierz kat:"), wxDefaultPosition, wxDefaultSize, 0);
	wybierzKat->Wrap(-1);
	bSizer92->Add(wybierzKat, 0, wxALL, 5);


	bSizer101->Add(bSizer92, 0, wxALIGN_CENTER, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxHORIZONTAL);

	stopnie45 = new wxRadioButton(this, wxID_ANY, wxT("45"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie45, 0, wxBOTTOM, 10);

	stopnie90 = new wxRadioButton(this, wxID_ANY, wxT("90"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie90, 0, wxBOTTOM, 10);

	stopnie135 = new wxRadioButton(this, wxID_ANY, wxT("135"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie135, 3, wxBOTTOM, 10);

	stopnie180 = new wxRadioButton(this, wxID_ANY, wxT("180"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie180, 0, wxBOTTOM, 10);

	stopnie235 = new wxRadioButton(this, wxID_ANY, wxT("225"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie235, 0, wxBOTTOM, 10);

	stopnie270 = new wxRadioButton(this, wxID_ANY, wxT("270"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie270, 0, wxBOTTOM, 10);

	stopnie315 = new wxRadioButton(this, wxID_ANY, wxT("315"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer6->Add(stopnie315, 0, wxBOTTOM, 10);


	bSizer101->Add(bSizer6, 0, wxALIGN_BOTTOM, 30);

	bSizer10->Add(bSizer101, 2, wxEXPAND, 5);


	bSizer9->Add(bSizer10, 1, wxEXPAND, 5);


	this->SetSizer(bSizer9);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::UpdateUI));
	menu->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Frame::MouseClick), NULL, this);
	menu->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Frame::MouseUp), NULL, this);
	menu->Connect(wxEVT_MOTION, wxMouseEventHandler(Frame::MouseMotion), NULL, this);
	symetria->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::symetriaButtonClick), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	zmienKolorButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::zmienKolorButtonClick), NULL, this);
	clean->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::cleanButtonClick), NULL, this);
	start->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::startButtonClick), NULL, this);
	stopnie45->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie45Button), NULL, this);
	stopnie90->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie90Button), NULL, this);
	stopnie135->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie135Button), NULL, this);
	stopnie180->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie180Button), NULL, this);
	stopnie235->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie225Button), NULL, this);
	stopnie270->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie270Button), NULL, this);
	stopnie315->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie315Button), NULL, this);
}

Frame::~Frame()
{
	// Disconnect Events
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(Frame::UpdateUI));
	menu->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Frame::MouseClick), NULL, this);
	menu->Disconnect(wxEVT_MOTION, wxMouseEventHandler(Frame::MouseMotion), NULL, this);
	symetria->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::symetriaButtonClick), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotPrawo->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::obrotPrawoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	obrotLewo->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::obrotLewoUpdate), NULL, this);
	zmienKolorButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::zmienKolorButtonClick), NULL, this);
	clean->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::cleanButtonClick), NULL, this);
	start->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::startButtonClick), NULL, this);
	stopnie45->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie45Button), NULL, this);
	stopnie90->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie90Button), NULL, this);
	stopnie135->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie135Button), NULL, this);
	stopnie180->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie180Button), NULL, this);
	stopnie235->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie225Button), NULL, this);
	stopnie270->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie270Button), NULL, this);
	stopnie315->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(Frame::stopnie315Button), NULL, this);
}