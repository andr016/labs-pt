#include "header.h"

#define CLR_WALL 0xAA
#define CLR_BG 0x00
#define CLR_BUG 0xCC
#define CLR_START 0x33
#define CLR_FINISH 0x44

const short START_X = 0,
START_Y = 0,
FINISH_X = 31,
FINISH_Y = 17,
L_WIDTH = 32,
L_HEIGHT = 32;

unsigned int bit = 0b10000000000000000000000000000000;

short bx = 0,
	by = 0;

unsigned int map[32] =
{ 0b0011'1111'1111'1111'1111'1111'1111'1111,
	0b0000'0110'0011'0110'0000'0010'0000'1111,
	0b0011'0110'1111'0110'1111'1011'1110'1111,
	0b1011'0110'1111'0110'1101'1010'0010'1111,
	0b1011'0110'1111'0110'1000'1011'1010'1111,
	0b1011'0110'1111'0110'1000'1010'1010'1111,
	0b1011'0110'1000'0000'1000'1010'1010'0001,
	0b1011'0110'1111'1110'1101'1010'1010'1111,
	0b1011'0110'1111'1110'1111'1110'1010'1101,
	0b1011'0000'0000'0000'0000'0000'1010'1101,
	0b1011'0111'1111'1011'1111'1110'1010'1101,
	0b1011'0100'0000'1000'0000'1110'0010'1101,
	0b1011'0101'1111'1111'1111'1111'1110'1101,
	0b1011'0000'0000'0000'0000'0000'0000'1101,
	0b1011'1111'1111'1110'1111'1111'1011'1101,
	0b1011'0000'0000'0010'0000'0011'1000'1101,
	0b1011'1111'1111'1010'1111'1111'1111'1101,
	0b1000'0000'0001'1010'0000'0000'0000'0000,
	0b1011'1111'1101'1010'1101'1011'1110'1101,
	0b1011'1111'1101'1010'1101'1011'1110'1101,
	0b1010'0000'0001'1010'1101'1000'0010'1101,
	0b1011'1111'1111'1010'1101'1111'1010'1101,
	0b1010'0000'0000'0010'1101'0011'1010'1101,
	0b1010'1111'1111'1110'1101'1010'1010'1101,
	0b1010'1111'1111'1110'1101'1010'1010'1101,
	0b1000'0000'0000'0000'1101'1010'1010'1101,
	0b1111'1111'1111'1111'1101'1010'1110'1101,
	0b1000'0000'0000'0000'0000'1010'1110'1101,
	0b1110'1110'1111'1111'1111'1010'0000'1101,
	0b1110'1110'1111'1111'1111'1011'1111'1101,
	0b1110'1110'0000'0000'0000'1000'0000'0001,
	0b1111'1111'1111'1111'1111'1111'1111'1111
},
* nMov = 0;

short moving(short pbx, short pby) {
	short nRes = 0;

	setColor(0x44);
	setCaret(pbx*2, pby);
	cout << "..";
	nMov[pby] |= bit >> pbx;
	if ((pbx == FINISH_X) && (pby == FINISH_Y)) return 99;

	// up
	if (pby - 1 >= 0) {
		if (!(map[pby - 1] & (bit >> pbx)) && !(nMov[pby - 1] & (bit >> pbx))) { // can
			nRes = moving(pbx, pby - 1);
			if (nRes) return nRes;
		}
	}

	// down
	if (pby + 1 <= 32) {
		if (!(map[pby + 1] & (bit >> pbx)) && !(nMov[pby + 1] & (bit >> pbx))) { // can
			nRes = moving(pbx, pby + 1);
			if (nRes) return nRes;
		}
	}

	// left
	if (pbx - 1 >= 0) {
		if (!(map[pby] & (bit >> pbx - 1)) && !(nMov[pby] & (bit >> pbx - 1))) { // can
			nRes = moving(pbx - 1, pby);
			if (nRes) return nRes;
		}
	}

	// right
	if (pbx + 1 <= 32) {
		if (!(map[pby] & (bit >> pbx + 1)) && !(nMov[pby] & (bit >> pbx + 1))) { // can
			nRes = moving(pbx + 1, pby);
			if (nRes) return nRes;
		}
	}
	
	setCaret(pbx*2, pby);
	setColor(CLR_BG);
	cout << "..";
	return 0;
}

void redraw() {
	if (bx == START_X && by == START_Y) setColor(CLR_START);
	else if (bx == FINISH_X && by == FINISH_Y) setColor(CLR_FINISH);
	else setColor(CLR_BG);
	cout << "..";
}

void labMaze() {
	unsigned char key;
	for (short ny = 0; ny < 32; ny++) {
		for (short nx = 0; nx < 32; nx++) {
			if ((bit >> nx) & map[ny]) {
				setColor(CLR_WALL);
				cout << "ШШ";
			}
			else {
				if (nx == START_X && ny == START_Y) setColor(CLR_START);
				else if (nx == FINISH_X && ny == FINISH_Y) setColor(CLR_FINISH);
				else setColor(CLR_BG);
				cout << "..";
			}
		}
	cout << endl;
	}
	do {
		setCaret(bx*2, by);
		setColor(CLR_BUG);
		cout << "ЖЖ";
		setCaret(bx*2, by);
		
		key = _getch();
		if (key == 224 || key == 0)	key = _getch();
		switch (key) {
		case 63:
			nMov = new UINT[32]{ 0 };
			memset(nMov, 0, sizeof(UINT) * 32);
			moving(bx, by);
			delete[] nMov;
			break;
		case KEY_UP:
			if ((bit >> bx) & map[by - 1])
				cout << "\a";
			else
			{
				redraw();
				by -= 1;
			}
			break;
		case KEY_DOWN:
			if ((bit >> bx) & map[by + 1])
				cout << "\a";
			else
			{
				redraw();
				by += 1;
			}
			break;
		case KEY_LEFT:
			if ((bit >> (bx-1)) & map[by])
				cout << "\a";
			else {
				redraw();
				bx -= 1;
			}
			break;
		case KEY_RIGHT:
			if ((bit >> (bx+1)) & map[by])
				cout << "\a";
			else {
				redraw();
				bx += 1;
			}
			break;
		case KEY_ESCAPE:
			setCaret(24, 16);
			setColor(0xC0);
			cout << "Аварийный выход\n";
			goto end;
		}
		if (bx == 31 || by == 31) {
			setCaret(23, 16);
			setColor(0x4B);
			cout << "Жук дошёл до конца\n";
			goto end;
		}
	} while (key != KEY_ESCAPE);
end:
	setCaret(0, 33);
	setColor(0x0F);
	system("PAUSE");
}