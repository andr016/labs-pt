#include "header.h"

CFigure::CFigure() : nx(0), ny(0), nWidth(20), nHeight(15) {
	brushcolor = RGB(255, 255, 0); //цвет заливки
	pencolor = 0x00FFFFFF; //цвет котура
}

CFigure::CFigure(int pnx, int pny, int pnWidth, int pnHeight) : nx(pnx), ny(pny), nWidth(pnWidth), nHeight(pnHeight) {
	brushcolor = RGB(255, 255, 0); //цвет заливки
	pencolor = 0x00FFFFFF; //цвет котура
}
CFigure::CFigure(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight) {
	brushcolor = pbrushcolor;
	pencolor = ppencolor;
}

CEllipse::CEllipse() : CFigure() {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CEllipse");

}

CEllipse::CEllipse(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight) {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CEllipse");
}
CEllipse::CEllipse(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	SetName("CEllipse");
}
void CEllipse::Draw() {
	HWND hwnd = GetConsoleWindow();
	LOGBRUSH lpBrush;
	lpBrush.lbStyle = BS_SOLID;
	lpBrush.lbColor = BrushColor();


	HDC hdc = GetDC(hwnd);

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);

	//HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 258, 255)), //pink
	//	pen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)), //green
	//	pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)), //red
	//	pen4 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0)); //yellow
	//LOGBRUSH Igbr{ PS_SOLID, RGB(78, 78, 78), 0 };
	//HBRUSH brush = CreateBrushIndirect(&Igbr);
	//SelectObject(hdc, pen2);
	//SelectObject(hdc, brush);

	//graph
	if (cX() != 0) {
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		MoveToEx(hdc, MiddleX(), MiddleY(), NULL);
		SelectObject(hdc, pen);
		LineTo(hdc, cX(), cY());
	}

	Ellipse(hdc, Left(), Top(), Right(), Bottom());
	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(hwnd, hdc);
}

int CManager::AddFigure(CFigure* pFigure) {
	if (pFigure == NULL) return -1;

	figures = (CFigure**)realloc(figures, sizeof(CFigure*) * (++ncount));
	figures[ncount - 1] = pFigure;
	return ncount - 1;
}

void CManager::Draw() {
	for (int i = 0; i < ncount; i++) figures[i]->Draw();

}
CFigure* CManager::GetFigure(int pid) {
	for (int i = 0; i < ncount; i++) {
		if (figures[i]->ID() == pid) return figures[i];
	}
	return NULL;
}

CUnion CManager::GetUnion(int index) {
	if (index < 0 || index >= nunion) return 0;
	return unions[index];
}

int CManager::AddUnion(CFigure* pFig1, CFigure* pFig2) {
	if (pFig1 == NULL || pFig2 == NULL) return -1; 

	unions = (CUnion*)realloc(unions, sizeof(CUnion) * (++nunion));
	unions[nunion - 1] = CUnion(pFig1, pFig2);
	return nunion - 1;
}

CFigure* CManager :: operator[](int index) {
	if (index < 0 && index >= ncount) return NULL;
	return figures[index];
}

void  CManager::Draw(int pid) {
	CFigure* gig = GetFigure(pid);
	if (gig != NULL) gig->Draw();
}
// отрисовка по ID
void  CManager::Draw(string pclass) {
	for (int i = 0; i < ncount; i++) if (figures[i]->GetName() == pclass) figures[i]->Draw();
}
// отрисовка по классу

void CManager::DrawGraph() {
	for (int i = 0; i < nunion; i++)
		unions[i].draw();
	Draw();
}

CRectangle::CRectangle() : CFigure() {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CRectangle");
}

CRectangle::CRectangle(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight) {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CRectangle");
}
CRectangle::CRectangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	SetName("CRectangle");
}
void CRectangle::Draw() {
	HWND hwnd = GetConsoleWindow();
	LOGBRUSH lpBrush;
	lpBrush.lbStyle = BS_SOLID;
	lpBrush.lbColor = BrushColor();


	HDC hdc = GetDC(hwnd);

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);

	//HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 258, 255)), //pink
	//	pen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)), //green
	//	pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)), //red
	//	pen4 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0)); //yellow
	//LOGBRUSH Igbr{ PS_SOLID, RGB(78, 78, 78), 0 };
	//HBRUSH brush = CreateBrushIndirect(&Igbr);
	//SelectObject(hdc, pen2);
	//SelectObject(hdc, brush);

	//ris grapha


	Rectangle(hdc, Left(), Top(), Right(), Bottom());
	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(hwnd, hdc);
}


CTriangle::CTriangle() : CFigure() {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CTriangle");
}

CTriangle::CTriangle(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight) {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CTriangle");
}
CTriangle::CTriangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	: CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	SetName("CTriangle");
}
void CTriangle::Draw() {

	LOGBRUSH lpBrush;
	lpBrush.lbStyle = BS_SOLID;
	lpBrush.lbColor = BrushColor();


	HDC hdc = GetDC(GetConsoleWindow());

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);


	POINT pt[4];
	pt[0].x = MiddleX();	pt[0].y = Top();
	pt[1].x = Right();		pt[1].y = Bottom();
	pt[2].x = Left();		pt[2].y = Bottom();
	pt[3].x = pt[0].x;		pt[3].y = pt[0].y;
	Polygon(hdc, pt, 4);

	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(GetConsoleWindow(), hdc);
}

//CManager::CManager() : figures(NULL), ncount(0), unions(NULL), nunion(0) {}
//CManager::~CManager() {
//	for (int i = 0; i < ncount; i++) delete figures[i];
//	delete[] figures;
//	delete[] unions;
//}
//

void CManager::Load(string pfile) {
	ifstream fin;
	fin.open(pfile);
	if (!fin) return;

	string s;
	int id;
	while (getline(fin, s)) {
		switch (s[0]) {

		}
	}
}

void CManager::Save(string pfile) {
	ofstream fout;
	fout.open(pfile);
	if (!fout) return;

	for (int i = 0; i < ncount; i++) {
		CFigure* fig = figures[i];
		if (fig == NULL) continue;
		fout << fig->GetName() << endl;
		fout << "i=" << fig->GetId() << endl;
		fout << "x=" << fig->X() << endl;
		fout << "y=" << fig->Y() << endl;
		fout << "w=" << fig->Width() << endl;
		fout << "h=" << fig->Height() << endl;
		fout << "b=" << fig->BrushColor() << endl;
		fout << "p=" << fig->PenColor() << endl;
		fout << "end\n";
	}

	for (int i = 0; i < nunion; i++) {
		CUnion ounion = GetUnion(i);
		//fout << ounion.GetName() << endl;
		fout << "fig1=" << ounion.getFigure1()->ID();
		fout << "fig2=" << ounion.getFigure2()->ID();
		fout << "width=" << ounion.getWidth() << endl;
		fout << "color=" << ounion.getColor() << endl;
		fout << "end\n";
	}
	
	fout.close();
}