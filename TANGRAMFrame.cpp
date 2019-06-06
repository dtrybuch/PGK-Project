#include "TANGRAMFrame.h"
#include <iostream>

//edited 21.05
TANGRAMFrame::TANGRAMFrame(wxWindow* parent) :
	Frame(parent)
	//,bigTriangle1(250, 250, 125, 140, 2, 150), bigTriangle2(250, 250, 125, 140, 2, 150), _middleTriangle(250, 250, 125, 140, 2, 150),
	//smallTriangle1(250, 250, 125, 140, 2, 150), smallTriangle2(250, 250, 125, 140, 2, 150),
	//square(125, 150, 125, 200, 175, 200, 175, 150), 
	//parallelogram(150,140,250,140,360,400)
{
	menuWidth = menu->GetSize().x;
	menuHeight = menu->GetSize().y;
	_which = &bigTriangle1;
	makeStartSquare();
	this->m_minWidth = 1000;
	this->m_minHeight = 700;
	//end editing
	obrotLewo->SetRange(360);
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetRange(360);
	obrotPrawo->SetThumbPosition(0);
	ksztaltImage.AddHandler(new wxPNGHandler);
	srand(time(NULL));
	losowanie();
}
void TANGRAMFrame::MouseClick(wxMouseEvent& event)
{
	_which->SetBeforePoints();
	firstMousePosition.x = wxGetMousePosition().x - this->GetScreenPosition().x - 14;
	firstMousePosition.y = wxGetMousePosition().y - this->GetScreenPosition().y - 44;
	//edited 27.05
	wxPoint mousePoints{ wxGetMousePosition().x - this->GetScreenPosition().x - 14, wxGetMousePosition().y - this->GetScreenPosition().y - 44 };
	if (bigTriangle1.isCursorInShape(mousePoints))
	{
		if (_which != &bigTriangle1)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &bigTriangle1;
		_which->isClicking = true;
	}
	else if (bigTriangle2.isCursorInShape(mousePoints))
	{
		if (_which != &bigTriangle2)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &bigTriangle2;
		_which->isClicking = true;
	}
	else if (_middleTriangle.isCursorInShape(mousePoints))
	{
		if (_which != &_middleTriangle)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &_middleTriangle;
		_which->isClicking = true;
	}
	else if (smallTriangle1.isCursorInShape(mousePoints))
	{
		if (_which != &smallTriangle1)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &smallTriangle1;
		_which->isClicking = true;
	}
	else if (smallTriangle2.isCursorInShape(mousePoints))
	{
		if (_which != &smallTriangle2)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &smallTriangle2;
		_which->isClicking = true;
	}
	else if (square.isCursorInShape(mousePoints))
	{
		if (_which != &square)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &square;
		_which->isClicking = true;
	}
	else if (parallelogram.isCursorInShape(mousePoints))
	{
		if (_which != &parallelogram)
		{
			_which->m_alfa += obrotLewo->GetThumbPosition();
			_which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		_which->isClicking = false;
		_which = &parallelogram;
		_which->isClicking = true;
	}
	//endediting 27.05

}
void TANGRAMFrame::MouseUp(wxMouseEvent& event)
{
	_which->isMoving = false;
	//24.05
	_which->m_alfa += obrotLewo->GetThumbPosition();
	_which->m_beta += obrotPrawo->GetThumbPosition();
	//end24.05
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetThumbPosition(0);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
	staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
	//endediting 23.05
	if (square.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || square.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || square.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
		smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
		bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
		bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
		_middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
		parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[2]))
	{
		smallTriangle1.SetTmpPoints();
		smallTriangle1.setSrodek();
	}
	else if (square.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || square.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || square.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
		smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
		bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
		bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
		_middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
		parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[2]))
		 {
			smallTriangle2.SetTmpPoints();
			smallTriangle2.setSrodek();
	     }
	else if (square.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || square.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || square.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
		smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
		smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
		bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
		_middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
		parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[2]))
	     {
			bigTriangle1.SetTmpPoints();
			bigTriangle1.setSrodek();
	     }
	else if (square.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || square.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || square.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
		smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
		smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
		bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
		_middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
		parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[2]))
		 {
			bigTriangle2.SetTmpPoints();
			bigTriangle2.setSrodek();
		 }
	else if (square.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || square.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || square.isCursorInShape(_middleTriangle.GetTmpPoints()[2]) ||
		smallTriangle2.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(_middleTriangle.GetTmpPoints()[2]) ||
		smallTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[2]) ||
		bigTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[2]) ||
		bigTriangle2.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(_middleTriangle.GetTmpPoints()[2]) ||
		parallelogram.isCursorInShape(_middleTriangle.GetTmpPoints()[0]) || parallelogram.isCursorInShape(_middleTriangle.GetTmpPoints()[1]) || parallelogram.isCursorInShape(_middleTriangle.GetTmpPoints()[2]))
	     {
			_middleTriangle.SetTmpPoints();
			_middleTriangle.setSrodek();
	     }
	else if (_middleTriangle.isCursorInShape(square.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(square.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(square.GetTmpPoints()[2]) || _middleTriangle.isCursorInShape(square.GetTmpPoints()[3]) ||
		smallTriangle2.isCursorInShape(square.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[2]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[3]) ||
		smallTriangle1.isCursorInShape(square.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[2]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[3]) ||
		bigTriangle1.isCursorInShape(square.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[2]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[3]) ||
		bigTriangle2.isCursorInShape(square.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(square.GetTmpPoints()[2]) || bigTriangle2.isCursorInShape(square.GetTmpPoints()[3]) ||
		parallelogram.isCursorInShape(square.GetTmpPoints()[0]) || parallelogram.isCursorInShape(square.GetTmpPoints()[1]) || parallelogram.isCursorInShape(square.GetTmpPoints()[2])|| parallelogram.isCursorInShape(square.GetTmpPoints()[3]))
		 {
			square.SetTmpPoints();
			square.setSrodek();
		 }
	else if (_middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[0]) || _middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[1]) || _middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[2]) || _middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
		smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[2]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
		smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[2]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
		bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[2]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
		bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[2]) || bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
		square.isCursorInShape(parallelogram.GetTmpPoints()[0]) || square.isCursorInShape(parallelogram.GetTmpPoints()[1]) || square.isCursorInShape(parallelogram.GetTmpPoints()[2]) ||square.isCursorInShape(parallelogram.GetTmpPoints()[3]))
		 {
			parallelogram.SetTmpPoints();
			parallelogram.setSrodek();
	     }
}

void TANGRAMFrame::MouseMotion(wxMouseEvent& event)
{
	//edited 23.05
	int wlk_pol = 100; //odleglosc od srodka (wielkosc tangramu)
	int srodekX = (menu->GetSize().GetWidth() / 2) + 1;
	int srodekY = (menu->GetSize().GetHeight() / 2) + 1;
	wxPoint mousePoints{ wxGetMousePosition().x - this->GetScreenPosition().x - 14, wxGetMousePosition().y - this->GetScreenPosition().y - 44 };
	int mouseX = mousePoints.x - firstMousePosition.x;
	int mouseY = mousePoints.y - firstMousePosition.y;
	firstMousePosition.x = wxGetMousePosition().x - this->GetScreenPosition().x - 14;
	firstMousePosition.y = wxGetMousePosition().y - this->GetScreenPosition().y - 44;

	if ((bigTriangle1.isCursorInShape(mousePoints) && bigTriangle1.isClicking || bigTriangle1.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, bigTriangle1);
	}
	else if ((bigTriangle2.isCursorInShape(mousePoints) && bigTriangle2.isClicking || bigTriangle2.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, bigTriangle2);
	}
	else if ((_middleTriangle.isCursorInShape(mousePoints) && _middleTriangle.isClicking || _middleTriangle.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, _middleTriangle);
	}
	else if ((smallTriangle1.isCursorInShape(mousePoints) && smallTriangle1.isClicking || smallTriangle1.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, smallTriangle1);
	}
	else if ((smallTriangle2.isCursorInShape(mousePoints) && smallTriangle2.isClicking || smallTriangle2.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, smallTriangle2);
	}
	else if ((square.isCursorInShape(mousePoints) && square.isClicking || square.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, square);
	}
	else if ((parallelogram.isCursorInShape(mousePoints) && parallelogram.isClicking || parallelogram.isMoving) && wxGetMouseState().LeftDown())
	{
		moveShape(mouseX, mouseY, parallelogram);
	}
	if (wxGetMousePosition().x - this->GetScreenPosition().x - 14 > menu->GetSize().x || wxGetMousePosition().x - this->GetScreenPosition().x - 14 < 0 || wxGetMousePosition().y - this->GetScreenPosition().y - 44 > menu->GetSize().y || wxGetMousePosition().y - this->GetScreenPosition().y - 44 < 0)
	{
		_which->isMoving = false;
		//24.05
		_which->m_alfa += obrotLewo->GetThumbPosition();
		_which->m_beta += obrotPrawo->GetThumbPosition();
		//end24.05
	}

	//end editing 23.05
}

void TANGRAMFrame::symetriaButtonClick(wxCommandEvent& event)
{
	if (_which->isSymetriaClicking) _which->isSymetriaClicking = false;
	else _which->isSymetriaClicking = true;
}

void TANGRAMFrame::obrotPrawoUpdate(wxScrollEvent& event)
{
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
	Draw();
}

void TANGRAMFrame::obrotLewoUpdate(wxScrollEvent& event)
{
	staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
	Draw();
}

void TANGRAMFrame::cleanButtonClick(wxCommandEvent& event)
{
	makeStartSquare();
}
void TANGRAMFrame::zmienKolorButtonClick(wxCommandEvent& event)
{
	if (isBlackColour)
	{
		menu->SetBackgroundColour(*wxWHITE);
		ksztalt->SetBackgroundColour(*wxWHITE);
		isBlackColour = false;
	}
	else
	{
		isBlackColour = true;
		menu->SetBackgroundColour(*wxBLACK);
		ksztalt->SetBackgroundColour(*wxBLACK);
	}
}
void TANGRAMFrame::startButtonClick(wxCommandEvent& event)
{
	licznik = 0;
	isStartButtonClicked = true;
	losowanie();
}

void TANGRAMFrame::Draw()
{
	wxClientDC dc1(menu);
	wxBufferedDC dc(&dc1);
	int w, h;
	menu->GetSize(&w, &h);
	dc.Clear();
	if (obrotLewo->GetThumbPosition() == 359) obrotLewo->SetThumbPosition(0);
	if (obrotPrawo->GetThumbPosition() == 359) obrotPrawo->SetThumbPosition(0);
	//edited 24.05 
	if (smallTriangle1.isClicking) smallTriangle1.Draw(&dc, w, h, smallTriangle1.m_alfa + obrotLewo->GetThumbPosition(), smallTriangle1.m_beta + obrotPrawo->GetThumbPosition());
	else smallTriangle1.Draw(&dc, w, h, smallTriangle1.m_alfa, smallTriangle1.m_beta);
	if (smallTriangle2.isClicking) smallTriangle2.Draw(&dc, w, h, smallTriangle2.m_alfa + obrotLewo->GetThumbPosition(), smallTriangle2.m_beta + obrotPrawo->GetThumbPosition());
	else smallTriangle2.Draw(&dc, w, h, smallTriangle2.m_alfa, smallTriangle2.m_beta);
	if (square.isClicking) square.Draw(&dc, w, h, square.m_alfa + obrotLewo->GetThumbPosition(), square.m_beta + obrotPrawo->GetThumbPosition());
	else square.Draw(&dc, w, h, square.m_alfa, square.m_beta);
	if (parallelogram.isClicking)parallelogram.Draw(&dc, w, h, parallelogram.m_alfa + obrotLewo->GetThumbPosition(), parallelogram.m_beta + obrotPrawo->GetThumbPosition());
	else parallelogram.Draw(&dc, w, h, parallelogram.m_alfa, parallelogram.m_beta);
	if (_middleTriangle.isClicking) _middleTriangle.Draw(&dc, w, h, _middleTriangle.m_alfa + obrotLewo->GetThumbPosition(), _middleTriangle.m_beta + obrotPrawo->GetThumbPosition());
	else  _middleTriangle.Draw(&dc, w, h, _middleTriangle.m_alfa, _middleTriangle.m_beta);
	if (bigTriangle1.isClicking) bigTriangle1.Draw(&dc, w, h, bigTriangle1.m_alfa + obrotLewo->GetThumbPosition(), bigTriangle1.m_beta + obrotPrawo->GetThumbPosition());
	else bigTriangle1.Draw(&dc, w, h, bigTriangle1.m_alfa, bigTriangle1.m_beta);
	if (bigTriangle2.isClicking) bigTriangle2.Draw(&dc, w, h, bigTriangle2.m_alfa + obrotLewo->GetThumbPosition(), bigTriangle2.m_beta + obrotPrawo->GetThumbPosition());
	else bigTriangle2.Draw(&dc, w, h, bigTriangle2.m_alfa, bigTriangle2.m_beta);

	if (_which->isClicking)_which->Draw(&dc, w, h, _which->m_alfa + obrotLewo->GetThumbPosition(), _which->m_beta + obrotPrawo->GetThumbPosition());
		//endediting 24.05

	if (ksztaltImage.IsOk())
	{
		ksztaltImage.Rescale(ksztalt->GetSize().GetWidth(), ksztalt->GetSize().GetHeight());
		wxBitmap bitmap(ksztaltImage);
		wxClientDC dc3(ksztalt);
		wxBufferedDC dc2(&dc3);
		dc2.Clear();
		dc2.DrawBitmap(bitmap, 0, 0);
	}
	if (isStartButtonClicked) Rozszczepienie(&dc);

	menuWidth = menu->GetSize().x;
	menuHeight = menu->GetSize().y;
}

void TANGRAMFrame::UpdateUI(wxUpdateUIEvent& event)
{
	int wlk_pol = 100; //odleglosc od srodka (wielkosc tangramu)
	int srodekX = (menu->GetSize().GetWidth() / 2) + 1;
	int srodekY = (menu->GetSize().GetHeight() / 2) + 1;
	bigTriangle1.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	bigTriangle2.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	smallTriangle1.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	smallTriangle2.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	_middleTriangle.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	square.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	parallelogram.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	Draw();
	if( licznik > 360 ) isStartButtonClicked = false;
}

void TANGRAMFrame::losowanie()
{
	wylosowana = rand() % 21;
	if (wylosowana == 0) ksztaltImage.LoadFile("ksztalty/0.png");
	if (wylosowana == 1) ksztaltImage.LoadFile("ksztalty/1.png");
	if (wylosowana == 2) ksztaltImage.LoadFile("ksztalty/2.png");
	if (wylosowana == 3) ksztaltImage.LoadFile("ksztalty/3.png");
	if (wylosowana == 4) ksztaltImage.LoadFile("ksztalty/4.png");
	if (wylosowana == 5) ksztaltImage.LoadFile("ksztalty/5.png");
	if (wylosowana == 6) ksztaltImage.LoadFile("ksztalty/6.png");
	if (wylosowana == 7) ksztaltImage.LoadFile("ksztalty/7.png");
	if (wylosowana == 8) ksztaltImage.LoadFile("ksztalty/8.png");
	if (wylosowana == 9) ksztaltImage.LoadFile("ksztalty/9.png");
	if (wylosowana == 10) ksztaltImage.LoadFile("ksztalty/10.png");
	if (wylosowana == 11) ksztaltImage.LoadFile("ksztalty/11.png");
	if (wylosowana == 12) ksztaltImage.LoadFile("ksztalty/12.png");
	if (wylosowana == 13) ksztaltImage.LoadFile("ksztalty/13.png");
	if (wylosowana == 14) ksztaltImage.LoadFile("ksztalty/14.png");
	if (wylosowana == 15) ksztaltImage.LoadFile("ksztalty/15.png");
	if (wylosowana == 16) ksztaltImage.LoadFile("ksztalty/16.png");
	if (wylosowana == 17) ksztaltImage.LoadFile("ksztalty/17.png");
	if (wylosowana == 18) ksztaltImage.LoadFile("ksztalty/18.png");
	if (wylosowana == 19) ksztaltImage.LoadFile("ksztalty/19.png");
	if (wylosowana == 20) ksztaltImage.LoadFile("ksztalty/20.png");
}

void TANGRAMFrame::stopnie45Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(45);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie90Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(90);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie135Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(135);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie180Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(180);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie225Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(225);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie270Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(270);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::stopnie315Button(wxCommandEvent& event)
{
	obrotPrawo->SetThumbPosition(315);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
}

void TANGRAMFrame::makeStartSquare()
{
	int wlk_pol = 100; //odleglosc od srodka (wielkosc tangramu)
	int srodekX = (menu->GetSize().GetWidth() / 2) + 1;
	int srodekY = (menu->GetSize().GetHeight() / 2) + 1;

	bigTriangle1 = Triangle(srodekX - wlk_pol, srodekY - wlk_pol, srodekX, srodekY, srodekX - wlk_pol, srodekY + wlk_pol);
	bigTriangle2 = Triangle(srodekX - wlk_pol, srodekY + wlk_pol, srodekX, srodekY, srodekX + wlk_pol, srodekY + wlk_pol);
	_middleTriangle = Triangle(srodekX, srodekY - wlk_pol, srodekX + wlk_pol, srodekY - 100, srodekX + wlk_pol, srodekY);
	smallTriangle1 = Triangle(srodekX - wlk_pol / 2, srodekY - wlk_pol / 2, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX, srodekY);
	smallTriangle2 = Triangle(srodekX + wlk_pol / 2, srodekY + wlk_pol / 2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol, srodekY + wlk_pol);
	square = Square(srodekX, srodekY, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol / 2, srodekY + wlk_pol / 2);
	parallelogram = Parallelogram(srodekX - wlk_pol, srodekY - wlk_pol, srodekX, srodekY - wlk_pol, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2);
	_which = &bigTriangle1;
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetThumbPosition(0);
}
void TANGRAMFrame::Rozszczepienie(wxBufferedDC dc)
{
	if (licznik == 0) makeStartSquare();
	int w, h;
	dc.Clear();
	this->Refresh();
	menu->GetSize(&w, &h);
	licznik += 2;
	smallTriangle1.AddToPoint(1.75*licznik / 130,  1.7*licznik / 140 );
	smallTriangle1.setSrodek();
	smallTriangle1.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	smallTriangle1.SetBeforePoints();

	smallTriangle2.AddToPoint(1.75*licznik / 150, 0);
	smallTriangle2.setSrodek();
	smallTriangle2.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	smallTriangle2.SetBeforePoints();

	bigTriangle2.AddToPoint(0, 1.5*licznik / 170);
	bigTriangle2.setSrodek();
	bigTriangle2.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	bigTriangle2.SetBeforePoints();

	bigTriangle1.AddToPoint(1.65*-licznik / 140, 1.5 * licznik / 170);
	bigTriangle1.setSrodek();
	bigTriangle1.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	bigTriangle1.SetBeforePoints();

	_middleTriangle.AddToPoint(1.65*-licznik / 112,1.5* -licznik / 170);
	_middleTriangle.setSrodek();
	_middleTriangle.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	_middleTriangle.SetBeforePoints();

	square.AddToPoint(1.65*licznik / 140, 1.6*-licznik / 150);
	square.setSrodek();
	square.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	square.SetBeforePoints();

	parallelogram.AddToPoint(0, 1.5*-licznik / 170);
	parallelogram.setSrodek();
	parallelogram.Draw(&dc, w, h, smallTriangle1.m_alfa + licznik, 0);
	parallelogram.SetBeforePoints();
}
void TANGRAMFrame::moveShape(int mouseX, int mouseY, Element & shape)
{
	shape.AddToPoint(mouseX, mouseY);
	shape.setSrodek();
	_which->isMoving = false;
	shape.isMoving = true;
	_which = &shape;
}
//
//
//void TANGRAMFrame::closeWindow(wxKeyEvent &event) {
//	if (event.GetKeyCode() == WXK_LEFT) wxWindow::Close();
//}
//// funkcja zmieniaj¹ca po³o¿enie elementu przez klikniêcie odpowiedniego klawisza strza³ki 
//void TANGRAMFrame::keyMove(wxKeyEvent& event, Element &elem) {
//
//	if (bigTriangle1.isClicking || bigTriangle1.isMoving && event.GetKeyCode() == WXK_LEFT)
//	{
//		bigTriangle1.AddToPoint(10, 0);
//		bigTriangle1.setSrodek();
//		_which->isMoving = false;
//		bigTriangle1.isMoving = true;
//		_which = &bigTriangle1;
//	}
//
//	//}
//	//if (wxGetMousePosition().x - this->GetScreenPosition().x - 14 > menu->GetSize().x || wxGetMousePosition().x - this->GetScreenPosition().x - 14 < 0 || wxGetMousePosition().y - this->GetScreenPosition().y - 44 > menu->GetSize().y || wxGetMousePosition().y - this->GetScreenPosition().y - 44 < 0)
//	//{
//	//	_which->isMoving = false;
//	//	//24.05
//	//	_which->m_alfa += obrotLewo->GetThumbPosition();
//	//	_which->m_beta += obrotPrawo->GetThumbPosition();
//	//	//end24.05
//	//}
///*
//	if (elem.isClicking || elem.isMoving) &&{
//		switch (event.GetKeyCode())
//		{
//		case WXK_LEFT:
//			elem.AddToPoint(-5, 0);
//			elem.setSrodek();
//			_which->isMoving = false;
//			elem.isMoving = true;
//			_which = &elem;
//			break;
//		case WXK_RIGHT:
//			parallelogram.AddToPoint(5, 0);
//			parallelogram.setSrodek();
//			_which->isMoving = false;
//			parallelogram.isMoving = true;
//			_which = &parallelogram;
//			break;
//		case WXK_DOWN:
//			parallelogram.AddToPoint(0, -5);
//			parallelogram.setSrodek();
//			_which->isMoving = false;
//			parallelogram.isMoving = true;
//			_which = &parallelogram;
//			break;
//		case WXK_UP:
//			parallelogram.AddToPoint(0, 5);
//			parallelogram.setSrodek();
//			_which->isMoving = false;
//			parallelogram.isMoving = true;
//			_which = &parallelogram;
//			break;
//		}
//	}*/
//}
