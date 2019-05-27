#pragma once
#include <wx/dcclient.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
class Matrix;

//edited 21.05
//konwencja elementow - podajemy wspó³rzêdne od lewego górnego, zgodnie z wskazówkami zegara
//end editing

double dlugosc(wxPoint pierwszy, wxPoint drugi);

class Element{
public:
	virtual void Draw(wxDC *dc, int w, int h, int alfa, int beta) = 0;
	virtual Matrix LeftRotate(int alfa, int w, int h) = 0;
	virtual Matrix RightRotate(int beta, int w, int h) = 0;
	virtual bool isCursorInShape(wxPoint mousePoints) = 0;//22.05 dodatkowa funkcja sprawdzajaca czy kursor jest w srodku danegop ksztaltu
	virtual void Symetria() = 0;
	virtual void setSrodek() = 0;//22.05 dodatkowa funkcja ustwiajaca srodek 
	virtual void AddToPoint(int x, int y) = 0;
	virtual void SetNewPoints() = 0; //27.05 zamienia punkty w zaleznosci od alfy i bety
	Matrix Set_Translate() ;
	Matrix 	Set_ReturnTranslate() ;
	bool isMoving = false;
	bool isClicking = false;
	int srodekX;
	int srodekY;
	int m_alfa = 0, m_beta = 0;//katy przechowywane tymczasowo
protected:
};

class Triangle :public Element
{
public:
	Triangle(){}
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		Points[0] = wxPoint(x1,y1);
		Points[1] = wxPoint(x2,y2);
		Points[2] = wxPoint(x3,y3);
		setSrodek();
		dlugosc12 = dlugosc(Points[0], Points[1]);
		dlugosc23 = dlugosc(Points[1], Points[2]);
		dlugosc31 = dlugosc(Points[0], Points[2]);
	}
	void Draw( wxDC *dc,int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	void Symetria();
	bool isCursorInShape(wxPoint mousePoints);//22.05
	void setSrodek();//22.05
	void AddToPoint(int x, int y);//22.05
	void SetNewPoints(); //27.05 dod
protected:
	wxPoint Points[3];
	wxPoint tmpPoints[3];//przechowywane punkty po transformacji 27.05 dla wszystkich
	bool rotated; //czy jest odwrocony bokiem bo sa dwa
	double dlugosc12;
	double dlugosc23;
	double dlugosc31;
};

class Square :public Element{
public:
	Square(){}
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		Points[0] = wxPoint(x1, y1);
		Points[1] = wxPoint(x2, y2);
		Points[2] = wxPoint(x3, y3);
		Points[3] = wxPoint(x4, y4);
		setSrodek();
		dlugosc12 = dlugosc(Points[0], Points[1]);
		dlugosc23 = dlugosc(Points[1], Points[2]);
		dlugosc34 = dlugosc(Points[2], Points[3]);
		dlugosc41 = dlugosc(Points[0], Points[3]);
	}
	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	bool isCursorInShape(wxPoint mousePoints);
	void Symetria();
	void setSrodek();
	void AddToPoint(int x, int y);
	void SetNewPoints() {} //27.05
protected:
	wxPoint Points[4];
	wxPoint tmpPoints[4];
	double dlugosc12;
	double dlugosc23;
	double dlugosc34;
	double dlugosc41;

};

//edited 22.05
class Parallelogram : public Element
{
public:
	Parallelogram(){}
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
		setSrodek();
		dlugosc12 = dlugosc(Points[0], Points[1]);
		dlugosc23 = dlugosc(Points[1], Points[2]);
		dlugosc34 = dlugosc(Points[2], Points[3]);
		dlugosc41 = dlugosc(Points[0], Points[3]);
	}

	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	Matrix LeftRotate(int alfa, int w, int h);
	Matrix RightRotate(int beta, int w, int h);
	bool isCursorInShape(wxPoint mousePoints);
	void Symetria();
	void setSrodek();
	void AddToPoint(int x, int y);
	void SetNewPoints() {} //27.05
protected:
	wxPoint Points[4];
	wxPoint tmpPoints[4];
	double dlugosc12;
	double dlugosc23;
	double dlugosc34;
	double dlugosc41;
};
//end editing

