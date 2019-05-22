#include "TANGRAMFrame.h"

//edited 22.05
TANGRAMFrame::TANGRAMFrame(wxWindow* parent) :
	Frame(parent)/*, 
	bigTriangle1(menu->GetSize().GetWidth()/2 - 100, 224, 422, 324, 322, 424), bigTriangle2(250, 250, 125, 140, 2, 150), middleTriangle(250, 250, 125, 140, 2, 150),
	smallTriangle1(250, 250, 125, 140, 2, 150), smallTriangle2(250, 250, 125, 140, 2, 150),
	square(125, 150, 125, 200, 175, 200, 175, 150), 
	parallelogram(150,140,250,140,360,400)*/
{
	int wlk_pol = 100; //odleglosc od srodka (wielkosc tangramu)
	int srodekX = (menu->GetSize().GetWidth() / 2) + 1;
	int srodekY = (menu->GetSize().GetHeight() / 2) + 1;

	bigTriangle1 = Triangle(srodekX - wlk_pol, srodekY- wlk_pol, srodekX, srodekY, srodekX- wlk_pol, srodekY+ wlk_pol);
	bigTriangle2 = Triangle(srodekX - wlk_pol, srodekY + wlk_pol, srodekX, srodekY, srodekX+ wlk_pol, srodekY+ wlk_pol);
	middleTriangle = Triangle(srodekX, srodekY-wlk_pol, srodekX+wlk_pol, srodekY-100 , srodekX+wlk_pol, srodekY);
	smallTriangle1 = Triangle(srodekX-wlk_pol/2, srodekY - wlk_pol / 2, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX, srodekY);
	smallTriangle2 = Triangle(srodekX + wlk_pol/2, srodekY+wlk_pol/2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol, srodekY + wlk_pol);
	square = Square(srodekX, srodekY,srodekX + wlk_pol / 2, srodekY - wlk_pol / 2, srodekX + wlk_pol, srodekY, srodekX + wlk_pol / 2, srodekY + wlk_pol / 2);
	parallelogram = Parallelogram(srodekX - wlk_pol, srodekY - wlk_pol, srodekX, srodekY - wlk_pol, srodekX + wlk_pol / 2, srodekY - wlk_pol / 2);
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
	wxClientDC dc1(menu);
	wxBufferedDC dc(&dc1);
	dc.SetBrush(*wxRED);
	dc.DrawRectangle(20, 20, 150, 300);
}

void TANGRAMFrame::MouseMotion(wxMouseEvent& event)
{
	// TODO: Implement MouseMotion
}

void TANGRAMFrame::symetriaButtonClick(wxCommandEvent& event)
{
	// TODO: Implement symetriaButtonClick
}


void TANGRAMFrame::KeyEvent(wxKeyEvent& event)
{
	// TODO: Implement KeyEvent
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
	wxClientDC dc1(menu);
	wxBufferedDC dc(&dc1);
	dc.Clear();
	Draw();
}

void TANGRAMFrame::losujButtonClick(wxCommandEvent& event)
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
	//edited 22.05
	bigTriangle1.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	bigTriangle2.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	square.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	smallTriangle1.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	smallTriangle2.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	middleTriangle.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	parallelogram.Draw(&dc, w, h, obrotLewo->GetThumbPosition(), obrotPrawo->GetThumbPosition());
	//endediting
	
	if (ksztaltImage.IsOk())
	{
		ksztaltImage.Rescale(ksztalt->GetSize().GetWidth(), ksztalt->GetSize().GetHeight());
		wxBitmap bitmap(ksztaltImage);
		wxClientDC dc3(ksztalt);
		wxBufferedDC dc2(&dc3);
		dc2.Clear();
		dc2.DrawBitmap(bitmap, 0, 0);
	}

}

void TANGRAMFrame::UpdateUI(wxUpdateUIEvent& event)
{
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
