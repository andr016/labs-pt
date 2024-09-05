#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <fstream>

#include "myFunction.h"

#define ERR "Некорректные данные\nВведите повторно: "
#define CLEAR system("CLS")
#define PAUSE system("PAUSE")

#define KEY_ESCAPE 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main();

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();

void labMask();
void labMaze();
void labGraph();
void labTable();
void labTerm();
void labMacro();
void labCoding();
void labSort();
void ClassesMenu();

void pLabSnake();

// coding

typedef enum enCoding {
	CD_Ceasar,
	CD_Coding,
	CD_Dynamic,
	CD_Bit
}CODEMODEL;


void encode();
void decode();
void bitCode(bool pToleft = true);
void dynamic();

// classes


class CID {
	int nid;	//идентификатор объекта
protected:
	string sname;	//имя класса
public:
	CID() : nid(0), sname("CID") {}
	CID(int pid, string pname = "CID") : nid(pid), sname(pname) {}
	int ID() { return nid; }

	int GetId() { return nid; }
	void SetId(int pid) { nid = pid; }
	string GetName() { return sname; }
	void SetName(string pname) { sname = pname; }
};

class CFigure : public CID {
	int nx, //координата левого верхнего угла прямоугольника по оси x
		ny,  //координата левого верхнего угла прямоугольника по оси y
		nWidth, //ширина прямоугольника
		nHeight; // высота прямугольника
	int brushcolor, //цвет заливки
		pencolor; //цвет котура
	int cx = 0, cy;

public:
	CFigure();
	CFigure(int pnx, int pny, int pnWidth, int pnHeight);
	CFigure(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);



	int X() { return nx; }
	void X(int px) { nx = px; }
	int Y() { return ny; }
	void Y(int py) { ny = py; }

	int cX() { return cx; }
	void cX(int px) { cx = px; }
	int cY() { return ny; }
	void cY(int py) { cy = py; }

	int Width() { return nWidth; }
	void Width(int pWidth) { nWidth = pWidth; }
	int Height() { return nHeight; }
	void Height(int pHeight) { nHeight = pHeight; }

	int BrushColor() { return brushcolor; }
	void BrushColor(int pbrushcolor) { brushcolor = pbrushcolor; }
	int PenColor() { return pencolor; }
	void PenColor(int ppencolor) { pencolor = ppencolor; }

	int Left() { return nx; }
	int Top() { return ny; }
	int Right() { return nx + nWidth; }
	int Bottom() { return ny + nHeight; }

	int MiddleX() { return nx + nWidth / 2; }
	int MiddleY() { return ny + nHeight / 2; }

	virtual void Draw() { cout << " да."; };
};

class CRectangle : public CFigure {
public:
	CRectangle();
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight);
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CTriangle : public CFigure {


public:
	CTriangle();
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight);
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CEllipse : public CFigure {

public:
	CEllipse();
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight);
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CUnion {
	CFigure* fig1, * fig2;
	int color, width;
public:
	CUnion(CFigure* pFig1 = NULL, CFigure* pFig2 = NULL);
	~CUnion();

	void setFigure1(CFigure *pFig);
	void setFigure2(CFigure *pFig);
	void setColor(int pColor);
	void setWidth(int pWidth);

	CFigure* getFigure1();
	CFigure* getFigure2();
	int getColor();
	int getWidth();

	void draw();
};

class CManager {
private:
	CFigure** figures;		// это динамический массив объектов: прямоугольников, треугольников и овалов
	int ncount;				// количесво объектов в figures
	CUnion* unions; //dinam massiv union
	int nunion;
public:
	CManager() : figures(NULL), ncount(0), unions(NULL), nunion(0) {}
	~CManager() {}

	CFigure* operator[](int index);
	int AddFigure(CFigure* pFigure);
	int Count() { return ncount; }
	CFigure* GetFigure(int pid);

	CUnion GetUnion(int index);
	int AddUnion(CFigure* pFig1, CFigure* pFig2);
	int Union() { return nunion;}

	void Draw();
	void Draw(int pid); // отрисовка по ID
	void Draw(string pclass); // отрисовка по классу
	void DrawGraph(); //otr figur i liniy

	void Load(string pfile);
	void Save(string pfile);
};

void ParamMenu(CManager& manager);
