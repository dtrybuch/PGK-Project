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
	tmpPoints[0].x = first.GetX();
	tmpPoints[0].y = first.GetY();
	tmpPoints[1].x = second.GetX();
	tmpPoints[1].y = second.GetY();
	tmpPoints[2].x = third.GetX();
	tmpPoints[2].y = third.GetY();
	if (isClicking) dc->SetPen(*wxYELLOW);
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(3,tmpPoints);
	dc->SetPen(*wxBLACK);
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

bool Triangle::isCursorInShape(wxPoint mousePoints)
{
	double alfa = 0;
	double dlugosc1, dlugosc2, dlugosc3;
	dlugosc1 = dlugosc(tmpPoints[0],mousePoints);
	dlugosc2 = dlugosc(tmpPoints[1],mousePoints);
	dlugosc3 = dlugosc(tmpPoints[2],mousePoints);
	alfa += acos((pow(dlugosc1, 2) + pow(dlugosc2, 2) - pow(dlugosc12, 2)) / (2*dlugosc1*dlugosc2));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc2, 2) + pow(dlugosc3, 2) - pow(dlugosc23, 2)) / (2 * dlugosc2*dlugosc3));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc3, 2) + pow(dlugosc1, 2) - pow(dlugosc31, 2)) / (2 * dlugosc1*dlugosc3));//z twierdzenia o cosinusach
	if (fabs(360 - alfa * 180./M_PI) < 5) return true;
	return false;
}
void Triangle::setSrodek()
{
	srodekX = (Points[0].x + Points[1].x + Points[2].x) / 3;
	srodekY = (Points[0].y + Points[1].y + Points[2].y) / 3;
}

void Triangle::AddToPoint(int x, int y)
{
	Points[0].x += x;
	Points[0].y += y;
	Points[1].x += x;
	Points[1].y += y;
	Points[2].x += x;
	Points[2].y += y;
}
void Triangle::SetNewPoints()
{
	int w = 0; int h = 0;
	Matrix transformation;
	transformation = Set_Translate() *RightRotate(m_beta, w, h)* LeftRotate(m_alfa, w, h)*Set_ReturnTranslate();
	Vector first;
	first.Set(Points[0].x, Points[0].y);
	first = transformation * first;
	Vector second;
	second.Set(Points[1].x, Points[1].y);
	second = transformation * second;
	Vector third;
	third.Set(Points[2].x, Points[2].y);
	third = transformation * third;
	Points[0].x = first.GetX();
	Points[0].y = first.GetY();
	Points[1].x = second.GetX();
	Points[1].y = second.GetY();
	Points[2].x = third.GetX();
	Points[2].y = third.GetY();

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
	tmpPoints[0].x = first.GetX();
	tmpPoints[0].y = first.GetY();
	tmpPoints[1].x = second.GetX();
	tmpPoints[1].y = second.GetY();
	tmpPoints[2].x = third.GetX();
	tmpPoints[2].y = third.GetY();
	tmpPoints[3].x = fourth.GetX();
	tmpPoints[3].y = fourth.GetY();
	if (isClicking) dc->SetPen(*wxYELLOW);
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(4, tmpPoints);
	dc->SetPen(*wxBLACK);
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
bool Square::isCursorInShape(wxPoint mousePoints)
{
	double alfa = 0;
	double dlugosc1, dlugosc2, dlugosc3,dlugosc4;
	dlugosc1 = dlugosc(tmpPoints[0], mousePoints);
	dlugosc2 = dlugosc(tmpPoints[1], mousePoints);
	dlugosc3 = dlugosc(tmpPoints[2], mousePoints);
	dlugosc4 = dlugosc(tmpPoints[3], mousePoints);
	alfa += acos((pow(dlugosc1, 2) + pow(dlugosc2, 2) - pow(dlugosc12, 2)) / (2. * dlugosc1*dlugosc2));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc2, 2) + pow(dlugosc3, 2) - pow(dlugosc23, 2)) / (2. * dlugosc2*dlugosc3));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc3, 2) + pow(dlugosc4, 2) - pow(dlugosc34, 2)) / (2. * dlugosc3*dlugosc4));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc4, 2) + pow(dlugosc1, 2) - pow(dlugosc41, 2)) / (2. * dlugosc1*dlugosc4));//z twierdzenia o cosinusach
	if (fabs(360 - alfa * 180 / M_PI) < 12) return true;
	return false;
}
void Square::setSrodek()
{
	srodekX = (Points[2].x + Points[0].x) / 2;
	srodekY = (Points[3].y + Points[1].y) / 2;
}
void Square::AddToPoint(int x, int y)
{
	Points[0].x += x;
	Points[0].y += y;
	Points[1].x += x;
	Points[1].y += y;
	Points[2].x += x;
	Points[2].y += y;
	Points[3].x += x;
	Points[3].y += y;
}
//edited 21.05
void Parallelogram::Draw(wxDC *dc, int w, int h, int alfa, int beta)
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
	tmpPoints[0].x = first.GetX();
	tmpPoints[0].y = first.GetY();
	tmpPoints[1].x = second.GetX();
	tmpPoints[1].y = second.GetY();
	tmpPoints[2].x = third.GetX();
	tmpPoints[2].y = third.GetY();
	tmpPoints[3].x = fourth.GetX();
	tmpPoints[3].y = fourth.GetY();

	if (isClicking) dc->SetPen(*wxYELLOW);
	dc->SetBrush(*wxGREY_BRUSH);
	dc->DrawPolygon(4, tmpPoints);
	dc->SetPen(*wxBLACK);

}
void Parallelogram::SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	Points[0] = wxPoint(x1, y1);
	Points[1] = wxPoint(x2, y2);
	Points[2] = wxPoint(x3, y3);
	Points[3] = wxPoint(x4, y4);

}
Matrix Parallelogram::LeftRotate(int alfa, int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(-alfa * M_PI / 180.0);
	rotate.data[1][1] = cos(-alfa * M_PI / 180.0);
	rotate.data[0][1] = -sin(-alfa * M_PI / 180.0);
	rotate.data[1][0] = sin(-alfa * M_PI / 180.0);
	return rotate;

}
Matrix Parallelogram::RightRotate(int beta, int w, int h)
{
	Matrix rotate;
	rotate.data[0][0] = cos(beta* M_PI / 180.0);
	rotate.data[1][1] = cos(beta* M_PI / 180.0);
	rotate.data[0][1] = -sin(beta* M_PI / 180.0);
	rotate.data[1][0] = sin(beta* M_PI / 180.0);

	return rotate;

}
void Parallelogram::Symetria()
{

}
//end editing
bool Parallelogram::isCursorInShape(wxPoint mousePoints)
{
	double alfa = 0;
	double dlugosc1, dlugosc2, dlugosc3, dlugosc4;
	dlugosc1 = dlugosc(tmpPoints[0], mousePoints);
	dlugosc2 = dlugosc(tmpPoints[1], mousePoints);
	dlugosc3 = dlugosc(tmpPoints[2], mousePoints);
	dlugosc4 = dlugosc(tmpPoints[3], mousePoints);
	alfa += acos((pow(dlugosc1, 2) + pow(dlugosc2, 2) - pow(dlugosc12, 2)) / (2 * dlugosc1*dlugosc2));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc2, 2) + pow(dlugosc3, 2) - pow(dlugosc23, 2)) / (2 * dlugosc2*dlugosc3));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc3, 2) + pow(dlugosc4, 2) - pow(dlugosc34, 2)) / (2 * dlugosc3*dlugosc4));//z twierdzenia o cosinusach
	alfa += acos((pow(dlugosc4, 2) + pow(dlugosc1, 2) - pow(dlugosc41, 2)) / (2 * dlugosc1*dlugosc4));//z twierdzenia o cosinusach
	if (fabs(360 - alfa * 180 / M_PI) < 10) return true;
	return false;
}
void Parallelogram::setSrodek()
{
	srodekX = (Points[2].x + Points[0].x) / 2;
	srodekY = (Points[3].y + Points[1].y) / 2;
}
void Parallelogram::AddToPoint(int x, int y)
{
	Points[0].x += x;
	Points[0].y += y;
	Points[1].x += x;
	Points[1].y += y;
	Points[2].x += x;
	Points[2].y += y;
	Points[3].x += x;
	Points[3].y += y;
}
double dlugosc(wxPoint pierwszy, wxPoint drugi)
{
	double tmpX = pierwszy.x - drugi.x;
	double tmpY = pierwszy.y - drugi.y;
	return sqrt(pow(tmpX,2) + pow(tmpY,2));
}