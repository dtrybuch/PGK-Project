#include "TANGRAMFrame.h"
TANGRAMFrame::TANGRAMFrame( wxWindow* parent ) 
: 
Frame( parent ), bigTriangle(250, 250, 125, 140, 2, 150), square(125,150,125,200,175,200,175,150)
{
	obrotLewo->SetRange(360);
	obrotLewo->SetThumbPosition(0);
	obrotPrawo->SetRange(360);
	obrotPrawo->SetThumbPosition(0);
	ksztaltImage.AddHandler(new wxPNGHandler);
	ksztaltImage.LoadFile("ksztalty/0.png");
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




void TANGRAMFrame::obrotPrawoUpdate( wxScrollEvent& event )
{
	staticTextObrotPrawoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotPrawo->GetThumbPosition()));
	Draw();
}

void TANGRAMFrame::obrotLewoUpdate( wxScrollEvent& event )
{
	staticTextObrotLewoWartosc->SetLabel(wxString::Format(wxT("%d"), obrotLewo->GetThumbPosition()));
	Draw();
}

void TANGRAMFrame::cleanButtonClick( wxCommandEvent& event )
{
	wxClientDC dc1(menu);
	wxBufferedDC dc(&dc1);
	dc.Clear();
	Draw();
}

void TANGRAMFrame::losujButtonClick( wxCommandEvent& event )
{
// TODO: Implement losujButtonClick
}

void TANGRAMFrame::Draw()
{
	wxClientDC dc1(menu);
	wxBufferedDC dc(&dc1);
	int w, h;
	menu->GetSize(&w, &h);
	dc.Clear();
	bigTriangle.Draw(&dc, w, h, obrotLewo->GetThumbPosition(),obrotPrawo->GetThumbPosition());
	square.Draw(&dc, w, h, obrotLewo->GetThumbPosition(),obrotPrawo->GetThumbPosition());

	ksztaltImage.Rescale(ksztalt->GetSize().GetWidth(), ksztalt->GetSize().GetHeight());
	wxBitmap bitmap(ksztaltImage);
	wxClientDC dc3(ksztalt);
	wxBufferedDC dc2(&dc3);
	dc2.Clear();
	dc2.DrawBitmap(bitmap, 0, 0);
}

void TANGRAMFrame::UpdateUI(wxUpdateUIEvent& event)
{
	Draw();
}

void TANGRAMFrame::DrawFish(wxDC *dc, int w, int h)
{
	wxPoint Points[9];
	Points[0].x = w/2 - 100;
	Points[0].y = h / 2 - 10;
	Points[1].x = w/2 - 100;
	Points[1].y = h / 2 +10;
	Points[2].x = w/2-20;
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
	Points[7].y = h / 2 ;
	Points[8].x = w / 2 - 20;
	Points[8].y = h / 2 - 40;
	dc->Clear();
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(9, Points);
}



