#include "TANGRAMFrame.h"

//edited 21.05
TANGRAMFrame::TANGRAMFrame(wxWindow* parent) :
	Frame(parent)
	//,bigTriangle1(250, 250, 125, 140, 2, 150), bigTriangle2(250, 250, 125, 140, 2, 150), middleTriangle(250, 250, 125, 140, 2, 150),
	//smallTriangle1(250, 250, 125, 140, 2, 150), smallTriangle2(250, 250, 125, 140, 2, 150),
	//square(125, 150, 125, 200, 175, 200, 175, 150), 
	//parallelogram(150,140,250,140,360,400)
{
	menuWidth = menu->GetSize().x;
	menuHeight = menu->GetSize().y;
	which = &bigTriangle1;
	makeStartSquare();

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
	which->SetBeforePoints();
	firstMousePosition.x = wxGetMousePosition().x - this->GetScreenPosition().x - 14;
	firstMousePosition.y = wxGetMousePosition().y - this->GetScreenPosition().y - 44;
	//edited 27.05
	wxPoint mousePoints{ wxGetMousePosition().x - this->GetScreenPosition().x - 14, wxGetMousePosition().y - this->GetScreenPosition().y - 44 };
	if (bigTriangle1.isCursorInShape(mousePoints))
	{
		if (which != &bigTriangle1)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &bigTriangle1;
		which->isClicking = true;
	}
	else if (bigTriangle2.isCursorInShape(mousePoints))
	{
		if (which != &bigTriangle2)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &bigTriangle2;
		which->isClicking = true;
	}
	else if (middleTriangle.isCursorInShape(mousePoints))
	{
		if (which != &middleTriangle)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &middleTriangle;
		which->isClicking = true;
	}
	else if (smallTriangle1.isCursorInShape(mousePoints))
	{
		if (which != &smallTriangle1)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &smallTriangle1;
		which->isClicking = true;
	}
	else if (smallTriangle2.isCursorInShape(mousePoints))
	{
		if (which != &smallTriangle2)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &smallTriangle2;
		which->isClicking = true;
	}
	else if (square.isCursorInShape(mousePoints))
	{
		if (which != &square)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &square;
		which->isClicking = true;
	}
	else if (parallelogram.isCursorInShape(mousePoints))
	{
		if (which != &parallelogram)
		{
			which->m_alfa += obrotLewo->GetThumbPosition();
			which->m_beta += obrotPrawo->GetThumbPosition();
			obrotLewo->SetThumbPosition(0);
			obrotPrawo->SetThumbPosition(0);
			staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
			staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
		}
		which->isClicking = false;
		which = &parallelogram;
		which->isClicking = true;
	}
	//endediting 27.05

}
void TANGRAMFrame::MouseUp(wxMouseEvent& event)
{
	which->isMoving = false;
	//24.05
	which->m_alfa += obrotLewo->GetThumbPosition();
	which->m_beta += obrotPrawo->GetThumbPosition();
	//end24.05
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetThumbPosition(0);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
	staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
	//endediting 23.05
	//if (square.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || square.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || square.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
	//	smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
	//	bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
	//	bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
	//	middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(smallTriangle1.GetTmpPoints()[2]) ||
	//	parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[0]) || parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[1]) || parallelogram.isCursorInShape(smallTriangle1.GetTmpPoints()[2]))
	//{
	//	smallTriangle1.SetTmpPoints();
	//	smallTriangle1.setSrodek();
	//}
	//else if (square.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || square.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || square.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
	//	smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
	//	bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
	//	bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
	//	middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(smallTriangle2.GetTmpPoints()[2]) ||
	//	parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[0]) || parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[1]) || parallelogram.isCursorInShape(smallTriangle2.GetTmpPoints()[2]))
	//	 {
	//		smallTriangle2.SetTmpPoints();
	//		smallTriangle2.setSrodek();
	//     }
	//else if (square.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || square.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || square.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
	//	smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
	//	smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
	//	bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
	//	middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(bigTriangle1.GetTmpPoints()[2]) ||
	//	parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[0]) || parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[1]) || parallelogram.isCursorInShape(bigTriangle1.GetTmpPoints()[2]))
	//     {
	//		bigTriangle1.SetTmpPoints();
	//		bigTriangle1.setSrodek();
	//     }
	//else if (square.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || square.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || square.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
	//	smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
	//	smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
	//	bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
	//	middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(bigTriangle2.GetTmpPoints()[2]) ||
	//	parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[0]) || parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[1]) || parallelogram.isCursorInShape(bigTriangle2.GetTmpPoints()[2]))
	//	 {
	//		bigTriangle2.SetTmpPoints();
	//		bigTriangle2.setSrodek();
	//	 }
	//else if (square.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || square.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || square.isCursorInShape(middleTriangle.GetTmpPoints()[2]) ||
	//	smallTriangle2.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(middleTriangle.GetTmpPoints()[2]) ||
	//	smallTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[2]) ||
	//	bigTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[2]) ||
	//	bigTriangle2.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(middleTriangle.GetTmpPoints()[2]) ||
	//	parallelogram.isCursorInShape(middleTriangle.GetTmpPoints()[0]) || parallelogram.isCursorInShape(middleTriangle.GetTmpPoints()[1]) || parallelogram.isCursorInShape(middleTriangle.GetTmpPoints()[2]))
	//     {
	//		middleTriangle.SetTmpPoints();
	//		middleTriangle.setSrodek();
	//     }
	//else if (middleTriangle.isCursorInShape(square.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(square.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(square.GetTmpPoints()[2]) || middleTriangle.isCursorInShape(square.GetTmpPoints()[3]) ||
	//	smallTriangle2.isCursorInShape(square.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[2]) || smallTriangle2.isCursorInShape(square.GetTmpPoints()[3]) ||
	//	smallTriangle1.isCursorInShape(square.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[2]) || smallTriangle1.isCursorInShape(square.GetTmpPoints()[3]) ||
	//	bigTriangle1.isCursorInShape(square.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[2]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[3]) ||
	//	bigTriangle2.isCursorInShape(square.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(square.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(square.GetTmpPoints()[2]) || bigTriangle2.isCursorInShape(square.GetTmpPoints()[3]) ||
	//	parallelogram.isCursorInShape(square.GetTmpPoints()[0]) || parallelogram.isCursorInShape(square.GetTmpPoints()[1]) || parallelogram.isCursorInShape(square.GetTmpPoints()[2])|| parallelogram.isCursorInShape(square.GetTmpPoints()[3]))
	//	 {
	//		square.SetTmpPoints();
	//		square.setSrodek();
	//	 }
	//else if (middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[0]) || middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[1]) || middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[2]) || middleTriangle.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
	//	smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[0]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[1]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[2]) || smallTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
	//	smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[0]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[2]) || smallTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
	//	bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[2]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
	//	bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[0]) || bigTriangle1.isCursorInShape(parallelogram.GetTmpPoints()[1]) || bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[2]) || bigTriangle2.isCursorInShape(parallelogram.GetTmpPoints()[3]) ||
	//	square.isCursorInShape(parallelogram.GetTmpPoints()[0]) || square.isCursorInShape(parallelogram.GetTmpPoints()[1]) || square.isCursorInShape(parallelogram.GetTmpPoints()[2]) ||square.isCursorInShape(parallelogram.GetTmpPoints()[3]))
	//	 {
	//		parallelogram.SetTmpPoints();
	//		parallelogram.setSrodek();
	//     }
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
		bigTriangle1.AddToPoint(mouseX, mouseY);
		bigTriangle1.setSrodek();
		which->isMoving = false;
		bigTriangle1.isMoving = true;
		which = &bigTriangle1;
	}
	else if ((bigTriangle2.isCursorInShape(mousePoints) && bigTriangle2.isClicking || bigTriangle2.isMoving) && wxGetMouseState().LeftDown())
	{
		bigTriangle2.AddToPoint(mouseX, mouseY);
		bigTriangle2.setSrodek();
		which->isMoving = false;
		bigTriangle2.isMoving = true;
		which = &bigTriangle2;
	}
	else if ((middleTriangle.isCursorInShape(mousePoints) && middleTriangle.isClicking || middleTriangle.isMoving) && wxGetMouseState().LeftDown())
	{
		middleTriangle.AddToPoint(mouseX, mouseY);
		middleTriangle.setSrodek();
		which->isMoving = false;
		middleTriangle.isMoving = true;
		which = &middleTriangle;
	}
	else if ((smallTriangle1.isCursorInShape(mousePoints) && smallTriangle1.isClicking || smallTriangle1.isMoving) && wxGetMouseState().LeftDown())
	{
		smallTriangle1.AddToPoint(mouseX, mouseY);
		smallTriangle1.setSrodek();
		which->isMoving = false;
		smallTriangle1.isMoving = true;
		which = &smallTriangle1;
	}
	else if ((smallTriangle2.isCursorInShape(mousePoints) && smallTriangle2.isClicking || smallTriangle2.isMoving) && wxGetMouseState().LeftDown())
	{
		smallTriangle2.AddToPoint(mouseX, mouseY);
		smallTriangle2.setSrodek();
		which->isMoving = false;
		smallTriangle2.isMoving = true;
		which = &smallTriangle2;
	}
	else if ((square.isCursorInShape(mousePoints) && square.isClicking || square.isMoving) && wxGetMouseState().LeftDown())
	{
		square.AddToPoint(mouseX, mouseY);
		square.setSrodek();
		which->isMoving = false;
		square.isMoving = true;
		which = &square;
	}
	else if ((parallelogram.isCursorInShape(mousePoints) && parallelogram.isClicking || parallelogram.isMoving) && wxGetMouseState().LeftDown())
	{
		parallelogram.AddToPoint(mouseX, mouseY);
		parallelogram.setSrodek();
		which->isMoving = false;
		parallelogram.isMoving = true;
		which = &parallelogram;
	}
	if (wxGetMousePosition().x - this->GetScreenPosition().x - 14 > menu->GetSize().x || wxGetMousePosition().x - this->GetScreenPosition().x - 14 < 0 || wxGetMousePosition().y - this->GetScreenPosition().y - 44 > menu->GetSize().y || wxGetMousePosition().y - this->GetScreenPosition().y - 44 < 0)
	{
		which->isMoving = false;
		//24.05
		which->m_alfa += obrotLewo->GetThumbPosition();
		which->m_beta += obrotPrawo->GetThumbPosition();
		//end24.05
	}

	//end editing 23.05
}

void TANGRAMFrame::symetriaButtonClick(wxCommandEvent& event)
{
	if (which->isSymetriaClicking) which->isSymetriaClicking = false;
	else which->isSymetriaClicking = true;
}


void TANGRAMFrame::KeyEvent(wxKeyEvent& event)
{
	char key = event.GetKeyCode();
	if (key == 'w') obrotPrawo->SetThumbPosition(250);
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
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

void TANGRAMFrame::startButtonClick(wxCommandEvent& event)
{
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
	if (middleTriangle.isClicking) middleTriangle.Draw(&dc, w, h, middleTriangle.m_alfa + obrotLewo->GetThumbPosition(), middleTriangle.m_beta + obrotPrawo->GetThumbPosition());
	else  middleTriangle.Draw(&dc, w, h, middleTriangle.m_alfa, middleTriangle.m_beta);
	if (bigTriangle1.isClicking) bigTriangle1.Draw(&dc, w, h, bigTriangle1.m_alfa + obrotLewo->GetThumbPosition(), bigTriangle1.m_beta + obrotPrawo->GetThumbPosition());
	else bigTriangle1.Draw(&dc, w, h, bigTriangle1.m_alfa, bigTriangle1.m_beta);
	if (bigTriangle2.isClicking) bigTriangle2.Draw(&dc, w, h, bigTriangle2.m_alfa + obrotLewo->GetThumbPosition(), bigTriangle2.m_beta + obrotPrawo->GetThumbPosition());
	else bigTriangle2.Draw(&dc, w, h, bigTriangle2.m_alfa, bigTriangle2.m_beta);

	which->Draw(&dc, w, h, which->m_alfa + obrotLewo->GetThumbPosition(), which->m_beta + obrotPrawo->GetThumbPosition());
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
	middleTriangle.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	square.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	parallelogram.AddToPoint(menu->GetSize().x / 2 - menuWidth / 2, menu->GetSize().y / 2 - menuHeight / 2);
	Draw();
}

void TANGRAMFrame::DrawFish(wxDC *dc, int w, int h)
{
	wxPoint Points[9];
	Points[0].x = w / 2 - 100;
	Points[0].y = h / 2 - 10;
	Points[1].x = w / 2 - 100;
	Points[1].y = h / 2 + 10;
	Points[2].x = w / 2 - 20;
	Points[2].y = h / 2 + 40;
	Points[3].x = w / 2;
	Points[3].y = h / 2 + 10;
	Points[4].x = w / 2 + 20;
	Points[4].y = h / 2 + 10;
	Points[5].x = w / 2 + 30;
	Points[5].y = h / 2 + 20;
	Points[6].x = w / 2 + 30;
	Points[6].y = h / 2 - 10;
	Points[7].x = w / 2 + 20;
	Points[7].y = h / 2;
	Points[8].x = w / 2 - 20;
	Points[8].y = h / 2 - 40;
	dc->Clear();
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(9, Points);
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

void TANGRAMFrame::stopnie235Button(wxCommandEvent& event)
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
	middleTriangle = Triangle(srodekX, srodekY - wlk_pol, srodekX + wlk_pol, srodekY - 100, srodekX + wlk_pol, srodekY);
	smallTriangle1 = Triangle(srodekX - wlk_pol / 2, srodekY - wlk_pol / 2, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX, srodekY);
	smallTriangle2 = Triangle(srodekX + wlk_pol / 2, srodekY + wlk_pol / 2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol, srodekY + wlk_pol);
	square = Square(srodekX, srodekY, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol / 2, srodekY + wlk_pol / 2);
	parallelogram = Parallelogram(srodekX - wlk_pol, srodekY - wlk_pol, srodekX, srodekY - wlk_pol, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2);
	which = &bigTriangle1;
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetThumbPosition(0);
}
