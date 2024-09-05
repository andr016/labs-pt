#include "header.h"

//class CUnion {
//	CFigure* fig1, * fig2;
//	int color, width;
//public:
CUnion::CUnion(CFigure* pFig1, CFigure* pFig2) :fig1(pFig1), fig2(pFig2), color(RGB(255, 255, 255)), width(3) {	 };
CUnion::~CUnion() {
	fig1 = 0; fig2 = 0;
}
void CUnion::setFigure1(CFigure* pFig) {
	fig1 = pFig;
};
void CUnion::setFigure2(CFigure* pFig) {
	fig2 = pFig;
};
void CUnion::setColor(int pColor) {
	color = pColor;
}
void CUnion::setWidth(int pWidth) {
	width = pWidth;
};

CFigure* CUnion::getFigure1() {
	return fig1;
};
CFigure* CUnion::getFigure2() {
	return fig2;
};
int CUnion::getColor() {
	return color;
};
int CUnion::getWidth() {
	return width;
};

void CUnion::draw() {
	if (fig1 == 0 || fig2 == 0) return;
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN pen = CreatePen(PS_SOLID, width, color);
	SelectObject(hdc, pen);

	MoveToEx(hdc, fig1->MiddleX(), fig1->MiddleY(), NULL);
	LineTo(hdc, fig2->MiddleX(), fig2->MiddleY());


	DeleteObject(pen);

};