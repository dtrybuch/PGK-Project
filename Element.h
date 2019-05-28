#pragma once
#include <wx/dcclient.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>

class Matrix;
double dlugosc(wxPoint pierwszy, wxPoint drugi);

/**
* <summary> Klasa Element, reprezentujaca jedna z figur tangramu </summary>
*/
class Element{
public:
	/**
	* <summary> Metoda Draw, pozwalaj¹ca na narysowanie elementu na obiekcie 'dc' </summary>
	* <param name = "w"> szerokosc obiektu? </param>
	* <param name = "h"> wysokosc obiektu? <\param>
	* <param name = "alfa"> Obrot w lewo, w stopniach <\param>
	* <param name = "beta"> Obrot w prawo, w stopniach <\param>
	*/
	virtual void Draw(wxDC *dc, int w, int h, int alfa, int beta) = 0;

	/**
	* <returns> Macierz Translacji pozwalajaca na wielokrotne przeksztalcenia <\returns>
	*/
	Matrix Set_Translate();

	/**
	* <returns> Macierz Translacji odwrotnej, wykorzystywana na koncu ciagu przeksztalcen <\returns>
	*/
	Matrix 	Set_ReturnTranslate();
	
	/**
	* <summary> Metoda LeftRotate, obliczajaca macierz rotacji w lewo <\summary>
	* < returns> Macierz rotacji <\returns>
	*/
	Matrix LeftRotate(int alfa, int w, int h);
	
	/**
	* <summary> Metoda RightRotate, obliczajaca macierz rotacji w prawo <\summary>
	* < returns> Macierz rotacji <\returns>
	*/
	Matrix RightRotate(int beta, int w, int h);
	
	/**
	* <summary> Metoda isCursorInShape sprawdzajaca czy kursor 
	* jest aktualnie w obrebie figury <\summary>
	*/
	virtual bool isCursorInShape(wxPoint mousePoints) = 0;
	
	/**
	* <summary> Metoda Symetria, przeksztalcajaca aktualna figure 
	* do postaci symetrucznej wzgledem osi OY <\summary>
	*/
	virtual void Symetria() = 0;

	/**
	* <summary> Metoda setSrodek, wyznaczajaca polozenie srodka figury <\summary>
	* <remarks> Ustawia skladniki srodekX, srodekY figury <\remarks>
	*/
	virtual void setSrodek() = 0;//22.05 dodatkowa funkcja ustwiajaca srodek 
	
	/**
	* <summary> Metoda AddToPoint, wspomagajaca plynne poruszanie sie elementow <\summary>
	* <remarks> Aktualizuje polozenie punktow wierzcholkowych figury w trakcie ruchu
	*			z dokladnoscia do jednego piksela <\remarks>
	*/
	virtual void AddToPoint(int x, int y) = 0;

	/** <value> 
	* Czy ten obiekt sie porusza? 
	* <\value> 
	*/
	bool isMoving = false;

	/** <value> 
	* Czy ten obiekt jest wybrany? 
	* <\value> 
	*/
	bool isClicking = false;
	
	// <value> Wartosc X srodka figury <\value>
	int srodekX;
	// <value> Wartosc Y srodka figury <\value>
	int srodekY;

	// <value> aktualna wartosc kata obrotu w lewo <\value>
	int m_alfa = 0;
	// <value> aktualna wartosc kata obrotu w prawo <\value>
	int	m_beta = 0;

protected:
};


/**
* <summary> Klasa Triangle reprezentujaca trojkat <\summary>
* 
*/
class Triangle :public Element
{
public:
	Triangle(){}
	/**
	* <remarks> 
	* Argumenty konstruktora to kolejne wspolrzedne wierzcholkow, 
	* rozpoczynajac od najbardziej lewego, zgodnie ze wskazowkami zegara
	* <\remarks>
	*/
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
	void Symetria();
	bool isCursorInShape(wxPoint mousePoints);
	void setSrodek();
	void AddToPoint(int x, int y);

protected:
	/**
	* <value> Bazowe punkty wierzcholkowe trojkata <\value>
	*/
	wxPoint Points[3];

	/**
	* <value> Wierzcholki trojkata po transformacji <\value>
	*/
	wxPoint tmpPoints[3];

	/**
	* Kolejne dlugosci bokow trojkata
	*/
	double dlugosc12;
	double dlugosc23;
	double dlugosc31;
};


/**
* <summary> klasa Square reprezentujaca kwadrat <\summary>
*/
class Square :public Element{
public:
	Square(){}
	/**
	* <remarks>
	* Argumenty konstruktora to kolejne wspolrzedne wierzcholkow,
	* rozpoczynajac od najbardziej lewego, zgodnie ze wskazowkami zegara
	* <\remarks>
	*/
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		Points[0] = wxPoint(x1, y1);
		Points[1] = wxPoint(x2, y2);
		Points[2] = wxPoint(x3, y3);
		Points[3] = wxPoint(x4, y4);
		setSrodek();
		dlugoscBoku = dlugosc(Points[0], Points[1]);
	}
	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	bool isCursorInShape(wxPoint mousePoints);
	void Symetria();
	void setSrodek();
	void AddToPoint(int x, int y);
protected:
	/** 
	* <values> Punkty wierzcholkowe kwadratu <\values>
	*/
	wxPoint Points[4];
	
	/**
	* <values> Wierzcholki kwadratu po transformacji <\values>
	*/
	wxPoint tmpPoints[4];

	/**
	* <value> dlugosc boku kwadratu <\value>
	*/
	double dlugoscBoku;
};

/**
* <summary> Klasa Parallelogram reprezentujaca rownoleglobok <\summary>
*/
class Parallelogram : public Element
{
public:
	Parallelogram(){}
	/**
	* <remarks>
	* Argumenty konstruktora to kolejne wspolrzedne wierzcholkow,
	* rozpoczynajac od najbardziej lewego, zgodnie ze wskazowkami zegara.
	* Czwarty wierzcholek jest obliczany automatycznie.
	* <\remarks>
	*/
	Parallelogram(int x1, int y1, int x2, int y2, int x3, int y3) 
	{
		int length = x2 - x1;
		int x4 = x1 + (x3 - x2);
		int y4 = y3;
		Points[0] = wxPoint(x1, y1);
		Points[1] = wxPoint(x2, y2);
		Points[2] = wxPoint(x3, y3);
		Points[3] = wxPoint(x4, y4);
		setSrodek();
		dlugoscPodstawa = dlugosc(Points[0], Points[1]);
		dlugoscRamie = dlugosc(Points[1], Points[2]);

	}

	void Draw(wxDC *dc, int w, int h, int alfa, int beta);
	void SetPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	bool isCursorInShape(wxPoint mousePoints);
	void Symetria();
	void setSrodek();
	void AddToPoint(int x, int y);

protected:
	/**
	* <value> Punkty wierzcholkowe rownolegloboku </value>
	*/
	wxPoint Points[4];

	/**
	* <value> Punkty wierzcholkowe rownolegloboku po transformacji </value>
	*/
	wxPoint tmpPoints[4];

	/**
	* <value> Dlugosci bokow rownolegloboku </value>
	*/
	double dlugoscPodstawa;
	double dlugoscRamie;
};


