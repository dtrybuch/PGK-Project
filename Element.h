#pragma once
#include <wx/dcclient.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
class Matrix;

//edited 21.05
//konwencja elementow - podajemy wspó³rzêdne od lewego górnego, zgodnie z wskazówkami zegara
//end editing

class Element{
public:
	virtual void Draw(wxDC *dc, int w, int h, int alfa, int beta) = 0;
	virtual Matrix LeftRotate(int alfa, int w, int h) = 0;
	virtual Matrix RightRotate(int beta, int w, int h) = 0;
	virtual void Symetria() = 0;
	Matrix Set_Translate() ;
	Matrix 	Set_ReturnTranslate() ;
	bool isUsing = false;
	bool isClicking = false;
	int srodekX;
	int srodekY;
protected:
};

class Triangle :public Element
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		Points[0] = wxPoint(x1,y1);
		Points[1] = wxPoint(x2,y2);
		Points[2] = wxPoint(x3,y3);
		srodekX = (Points[0].x + Points[1].x + Points[2].x) / 3;
		srodekY = (Points[0].y + Points[1].y + Points[2].y) / 3;
	}
	void Draw( wxDC *dc,int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	void Symetria();
protected:
	wxPoint Points[3];
	bool rotated; //czy jest odwrocony bokiem bo sa dwa
};

class Square :public Element{
public:
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		Points[0] = wxPoint(x1, y1);
		Points[1] = wxPoint(x2, y2);
		Points[2] = wxPoint(x3, y3);
		Points[3] = wxPoint(x4, y4);
		srodekX = (Points[0].x + Points[2].x)  / 2;//w zaleznosci ktory punkt w jakiej kolejnosci
		srodekY = (Points[0].y + Points[1].y)  / 2;//jak wyzej
	}
	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	void Symetria();
protected:
	wxPoint Points[4];

};

//edited 22.05
class Parallelogram : public Element
{
public:
	Parallelogram(int x1, int y1, int x2, int y2, int x3, int y3) 
	{
		int length = x2 - x1;
		//int width = y3 - y2;
		//double tangens = (y3 - y2) / (x3 - x2);
		int x4 = x1 + (x3 - x2);
		int y4 = y3;
		Points[0] = wxPoint(x1, y1);
		Points[1] = wxPoint(x2, y2);
		Points[2] = wxPoint(x3, y3);
		Points[3] = wxPoint(x4, y4);

		srodekX = (x3 + x1) / 2;
		srodekY = (y4 + y2) / 2;
	}

	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	void Symetria();


protected:
	wxPoint Points[4];

};
//end editing