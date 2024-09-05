#include "header.h"

short choose(short min, short max) {
	printf("\n¬ведите номер работы \"I\": ");
	short sel;
	do {
		cin >> sel;
		if (sel < min || sel > max)
			cout << ERR;
	} while (sel < min || sel > max);
	system("CLS");
	return sel;
}

void creator() {
	system("PAUSE");
}

void setCaret(short x, short y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;
	
	SetConsoleCursorPosition(hCon, pos);
}

void setColor(short clr) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, clr);
}