#include"Element.h"
#include"vecmat.h"

Matrix Element::Set_ReturnTranslate()
{
	Matrix 	returnTranslate;
	returnTranslate.data[0][0] = 1;
	returnTranslate.data[1][1] = 1;
	returnTranslate.data[0][2] = -srodekX;
	returnTranslate.data[1][2] = -srodekY;
	return returnTranslate;
}
Matrix Element::Set_Translate()
{
	Matrix translate;
	translate.data[0][0] = 1;
	translate.data[1][1] = 1;
	translate.data[0][2] = srodekX;
	translate.data[1][2] = srodekY;
	return translate;
}

void Triangle::Draw(wxDC *dc,int w, int h, int alfa, int beta)
{
	Matrix transformation;
	
	transformation = Set_Translate() *RightRotate(beta, w, h)* LeftRotate(alfa,w,h)*Set_ReturnTranslate();
	Vector first;
	first.Set(Points[0].x, Points[0].y);
	first = transformation * first;
	Vector second;
	second.Set(Points[1].x, Points[1].y);
	second = transformation * second;
	Vector third;
	third.Set(Points[2].x, Points[2].y);
	third = transformation * third;
	wxPoint newPoints[3];
	newPoints[0].x = first.GetX();
	newPoints[0].y = first.GetY();
	newPoints[1].x = second.GetX();
	newPoints[1].y = second.GetY();
	newPoints[2].x = third.GetX();
	newPoints[2].y = third.GetY();
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(3,newPoints);
}
void Triangle::SetPoints(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Points[0] = wxPoint(x1, y1);
	Points[1] = wxPoint(x2, y2);
	Points[2] = wxPoint(x3, y3);
}

Matrix Triangle::LeftRotate(int alfa,int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(-alfa* M_PI / 180.0);
	rotate.data[1][1] = cos(-alfa* M_PI / 180.0);
	rotate.data[0][1] = -sin(-alfa* M_PI / 180.0);
	rotate.data[1][0] = sin(-alfa* M_PI / 180.0);
	return rotate;
}
Matrix Triangle::RightRotate(int beta, int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(beta* M_PI / 180.0);
	rotate.data[1][1] = cos(beta* M_PI / 180.0);
	rotate.data[0][1] = -sin(beta* M_PI / 180.0);
	rotate.data[1][0] = sin(beta* M_PI / 180.0);

	return rotate;
}

void Triangle:: Symetria()
{

}
//////////////////////////////////////////////////////////////////////////////
void Square::Draw(wxDC *dc, int w, int h, int alfa, int beta)
{
	Matrix transformation;

	transformation = Set_Translate() *RightRotate(beta, w, h)* LeftRotate(alfa, w, h)*Set_ReturnTranslate();
	Vector first;
	first.Set(Points[0].x, Points[0].y);
	first = transformation * first;
	Vector second;
	second.Set(Points[1].x, Points[1].y);
	second = transformation * second;
	Vector third;
	third.Set(Points[2].x, Points[2].y);
	third = transformation * third;
	Vector fourth;
	fourth.Set(Points[3].x, Points[3].y);
	fourth = transformation * fourth;
	wxPoint newPoints[4];
	newPoints[0].x = first.GetX();
	newPoints[0].y = first.GetY();
	newPoints[1].x = second.GetX();
	newPoints[1].y = second.GetY();
	newPoints[2].x = third.GetX();
	newPoints[2].y = third.GetY();
	newPoints[3].x = fourth.GetX();
	newPoints[3].y = fourth.GetY();

	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(4, newPoints);
}
void Square::SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Points[0] = wxPoint(x1, y1);
	Points[1] = wxPoint(x2, y2);
	Points[2] = wxPoint(x3, y3);
	Points[3] = wxPoint(x4, y4);
}
Matrix Square::LeftRotate(int alfa, int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(-alfa * M_PI / 180.0);
	rotate.data[1][1] = cos(-alfa * M_PI / 180.0);
	rotate.data[0][1] = -sin(-alfa * M_PI / 180.0);
	rotate.data[1][0] = sin(-alfa * M_PI / 180.0);
	return rotate;
}
Matrix Square::RightRotate(int beta, int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(beta* M_PI / 180.0);
	rotate.data[1][1] = cos(beta* M_PI / 180.0);
	rotate.data[0][1] = -sin(beta* M_PI / 180.0);
	rotate.data[1][0] = sin(beta* M_PI / 180.0);

	return rotate;
}

void Square::Symetria()
{

}