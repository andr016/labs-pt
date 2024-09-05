#include "header.h"

typedef
struct _row {
	short i;
	float a;
	float s;
	_row() {
		i = 0;
		a = 0;
		s = 0;
	}
} row, *prow;

prow arrs=0;
float epsilon;
float x;

bool term = false;

int cnt;

float gMin = 999999;
float gMax = -999999;
float gxMin, gxMax;

void labRecursion() {
	cout << "Условие задачи  : Вычислить значения последовательности, вывести их в табличном виде\nи посчитать сумму всех элементов последовательности с точностью e\n";
	cout << "Входные данные  : x (|x| <= 1), e\n";
	cout << "Выходные данные : Значения элементов последовательности в табличном виде\nи сумма всех элементов последовательности с точностью e\n\n";

	setColor(0x04);
	cout << "Введите значения x (|x| <= 1), e\n";
	setColor(0x0F);
	do {
		cin >> x;
	} while (abs(x) > 1);

	cin >> epsilon;

	gMin = x;
	gMax = x;

	setColor(0x08);
	arrs = (row*)realloc(arrs, sizeof(row));
	arrs[0].a = 1;
	arrs[0].s = 1;
	arrs[0].i = 1;
}

void drawGraph() {
	HWND hwnd = GetConsoleWindow();

	const short maR = 50,
		maL = 550,
		maT = 50,
		maB = 50;

	const short gHeight = 300, gWidth = 400;
	RECT WinCoord = {}; //Массив координат окна 
	GetWindowRect(hwnd, &WinCoord); //Узнаём координаты
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, maL, maT, NULL);

	int winT = WinCoord.top,
		winB = WinCoord.bottom,
		winL = WinCoord.left,
		winR = WinCoord.right;

	HFONT holdfont = 0, hfTitle = CreateFontA(20, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	SetTextColor(hDC, RGB(255, 255, 0));
	SetBkColor(hDC, RGB(0, 0, 0));

	holdfont = (HFONT)SelectObject(hDC, hfTitle);
	char sTitle[45]{ "График значений рекуррентного соотношения" };
	SIZE sz;
	GetTextExtentPoint32A(hDC, sTitle, strlen(sTitle), &sz);
	TextOutA(hDC, maL + (gWidth - sz.cx) / 2, maT - 24, sTitle, strlen(sTitle));

	SetTextColor(hDC, RGB(255, 255, 255));

	HPEN dPen = CreatePen(PS_SOLID, 1, RGB(127, 127, 127));
	SelectObject(hDC, dPen);

	const short vLines = 5;
	float tStep = gWidth / vLines;
	for (int i = 1; i < vLines + 1; i++) {
		char txt[30];
		if(term) sprintf_s(txt, "%f", gxMin + ((gxMax - gxMin) / vLines)*i);
		else sprintf_s(txt, "%d", i);
		TextOutA(hDC, (maL + tStep * i) - 4, maT + gHeight, txt, strlen(txt));
		MoveToEx(hDC, maL + tStep * i, maT, NULL);
		LineTo(hDC, maL + tStep * i, maT + gHeight);
	}

	const short hLines = 5;
	tStep = gHeight / hLines;
	for (int i = 0; i < hLines + 1; i++) {
		char txt[30];
		sprintf_s(txt, "%f", gMax - ((gMax - gMin) / hLines) * i);
		TextOutA(hDC, maL - 70, maT + tStep * i - 4, txt, strlen(txt));
		MoveToEx(hDC, maL, maT + tStep * i, NULL);
		LineTo(hDC, maL + gWidth, maT + tStep * i);
	}


	SetTextColor(hDC, RGB(255, 0, 0));
	GetTextExtentPoint32A(hDC, "Номер члена ряда", strlen("Номер члена ряда"), &sz);
	TextOutA(hDC, maL + (gWidth - sz.cx) / 2, maT + gHeight + 24, "Номер члена ряда", strlen("Номер члена ряда"));

	DeleteObject(SelectObject(hDC, holdfont)); hfTitle = 0;

	HFONT haixtitle = CreateFontA(24, 18, 900, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	SelectObject(hDC, haixtitle);
	TextOutA(hDC, maL - 120, maT + (gHeight*4/5), "Значения", strlen("Значения"));

	/*SetTextColor(hDC, RGB(255, 0, 0));
	sTitle = "Номер члена ряда";
	GetTextExtentPoint32A(hDC, sTitle, strlen(sTitle), &sz);
	TextOutA(hDC, maL + (gWidth - sz.cx) / 2, maT + gHeight + 24, sTitle, strlen(sTitle));*/

	//пунктир

	float vRatio = gHeight / (gMax - gMin);
	float hStep = gWidth / (cnt - 1);


	/*for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - center
	{
		MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);//10 - scale
		LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
	}*/

	/*float rRange = gMax - gMin;
	float gRange = WinCoord.bottom - maT - maB;
	float ratio = gRange / rRange;*/

	SelectObject(hDC, Pen);
	MoveToEx(hDC, maL, gHeight + maT, NULL);

	for (int i = 0; i < cnt; i++) {
		LineTo(hDC, maL + (hStep * i), (gHeight + maT) - ((arrs[i].s-gMin) * vRatio));
		//MoveToEx(hDC, winL + (hStep * cnt), winB - maB - (arrs[i].a * vRatio), NULL);
	}

	MoveToEx(hDC, maL, maT, NULL);
	LineTo(hDC, maL, gHeight + maT);
	MoveToEx(hDC, maL, gHeight + maT, NULL);
	LineTo(hDC, maL + gWidth, gHeight + maT);

	system("pause");
}

float calc(float px, float pe, short pn) {
	arrs = (row*)realloc(arrs, sizeof(row) * pn);

	float step = -1 * (px * px * (2 * pn - 3)) / (2 * pn - 1);
	float res = arrs[pn-2].a * step;
	if (res < gMin)
		gMin = res;
	if (res > gMax)
		gMax = res;
	arrs[pn-1].i = pn;
	arrs[pn-1].a = res;
	arrs[pn-1].s = res + arrs[pn-2].s;
	printf("%3d %10f %10f\n", arrs[pn-1].i, arrs[pn-1].a, arrs[pn-1].s);
	if (abs(res) < abs(pe)) {
		cnt = pn;
		return arrs[pn - 2].s + res;
	}
	calc(px, pe, pn + 1);
}

void drawTable() {
	printf("\n №а   значение   накопленное значение\n");
	setColor(0x0F);
	printf("%3d %10f %10f\n", 1, x, x);
	printf("\ny = %f\n\n", calc(x, epsilon, 2));
	system("PAUSE");
}

void labGraph() {
	labRecursion();
	system("CLS");
	drawTable();
	drawGraph();
}

void labTable() {
	labRecursion();
	drawTable();
	return;
}

/*typedef struct stRect {
	UCHAR nLeft,
		nTop,
		nWidth,
		nHeight;
	stRect():nLeft(0), nTop(0), nWidth(0), nHeight(0){}
	stRect(UCHAR pLeft, UCHAR pTop):stRect(), nLeft(pLeft), nTop(pTop){}
	stRect(UCHAR pLeft, UCHAR pTop, UCHAR pHel):nLeft(pLeft), nTop(pTop), nWdith(pWid), nHeight(pHei){}

	UCHAR nBottom() { return nTop + nHeight; }
	UCHAR nRight() { return nLeft + nWidth; }
};*/

void labTerm() {
	int i, N, toc;
	float a, k, X1, dX, X, Y;

	// подпись
	cout << "Задание 3.1:\tЦиклические алгоритмы\n\t\t(с графиком)\n\n";

	do
	{
		cout << "Введите значение A (положительное): ";
		cin >> a;
		// ввод а
		if (a <= 0)
		{
			cout << "Введено неверное значение a" << "\n";
		}
	} while (a <= 0);


	do
	{
		cout << "Введите N (кол-во точек), большее 1: ";
		cin >> N;
		// ввод точек
		if (N <= 1)
		{
			cout << "Введено неверное значение N" << "\n";
		}
	} while (N <= 1);
	arrs = (row*)realloc(arrs, sizeof(row) * N);
	// расчёт X1
	X1 = -10 * a;

	cout << "a = " << a << "\nN = " << N << "\nX1 = " << X1 << endl;
	do
	{
		cout << "Введите значение k (k*a > " << X1 / a << "): ";
		cin >> k; //ввод параметра k
		if (k * a <= X1)
		{
			cout << "Введено неверное значение параметра k" << "\n";
		}
	} while (k * a <= X1);

	dX = a / 2; // dX
	X = X1;
	/*cout << "N" << setw(10) << "X" << setw(10) << "Y" << setw(1) << endl;
	for (toc = 1; toc < N; toc++)
	{
		cout << ("_");
	}*/
	cout << endl;
	gxMin = X;
	printf("\n №    X          Y\n");
	for (i = 0; i < N; i++)
	{
		if (X <= k * a) //условие
		{
			Y = -((X + 3 * a) * (X + 3 * a)) - 2 * a; //первый вид
		}
		else
		{
			Y = a * cos(X + 3 * a) - 3 * a; //второй вид
		}
		arrs[i].i = i+1;
		arrs[i].a = floor(X * 1000 + 0.5) / 1000;
		arrs[i].s = floor(Y * 1000 + 0.5) / 1000;
		gMin = Y < gMin ? Y : gMin;
		gMax = Y > gMax ? Y : gMax;
		gxMax = arrs[i].a;
		printf("%3d %10f %10f\n", arrs[i].i, arrs[i].a, arrs[i].s);
		/*cout << setw(10) << left << i + 1;
		cout << setw(10) << left << floor(X * 1000 + 0.5) / 1000 << right << setw(10) << left << floor(Y * 1000 + 0.5) / 1000 << endl;//Вывод X*/
		X = X + dX; // +шаг
	}
	system("PAUSE");
	cnt = N;
	term = true;
	drawGraph();
	system("PAUSE");
}