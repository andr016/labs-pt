#include "header.h"

#define FRAME_INTERVAL 25

#define MW 32
#define MH 32

#define CLR_BG 0x88
#define CLR_SNAKE 0xFF
#define CLR_FRUIT 0xBB

enum eDirection { STOP = 0, UP, DOWN, LEFT, RIGHT };
eDirection dir;

unsigned char map[MW][MH];

short sx, sy, tail, fx, fy;

bool gameOver;

void randomizeFruit() {
	do {
		fx = rand() % MW;
		fy = rand() % MH;
	} while (map[fx][fy] != 0); // prevent fruit from spawning into snake

	setCaret(fx * 2, fy);
	setColor(CLR_FRUIT);
	cout << "..";
}

void pLabSnake() {
	sx = MW >> 1;
	sy = MH >> 1;
	tail = 5;
	dir = STOP;

	gameOver = false;
	
	// prepare field
	for (int iy = 0; iy < MH; iy++) {
		for (int ix = 0; ix < MW; ix++) {
			map[ix][iy] = 0;
			setColor(CLR_BG);
			cout << "..";
		}
		setColor(0x00);
		cout << endl;
	}
	setColor(0x00);
	randomizeFruit();

	do {
		// logic
		if (dir == LEFT && sx != 0 && map[sx - 1][sy] == 0) sx -= 1;
		else if (dir == RIGHT && sx != MW-1 && map[sx + 1][sy] == 0) sx += 1;
		else if (dir == UP && sy != 0 && map[sx][sy - 1] == 0) sy -= 1;
		else if (dir == DOWN && sy != MH-1 && map[sx][sy + 1] == 0) sy += 1;
		else if (dir == STOP) {}
		else gameOver = true;

		map[sx][sy] = tail;
		for (int iy = 0; iy < MH; iy++) {
			for (int ix = 0; ix < MW; ix++) {
				if (map[ix][iy] == 1) {
					setCaret(ix * 2, iy);
					setColor(CLR_BG);
					cout << "..";
					map[ix][iy] = 0;
				}
				else if (map[ix][iy] == 0) {}
				else map[ix][iy] -= 1;
			}
		}

		if (sx == fx && sy == fy) {
			randomizeFruit();
			tail += 1;
		}

		setCaret(sx * 2, sy);
		setColor(CLR_SNAKE);
		cout << "..";

		if (_kbhit()) {
			unsigned char key = _getch();
			if (key == 224 || key == 0)	key = _getch();
			switch (key) {
			case KEY_UP:
				if (dir != DOWN) dir = UP;
				break;
			case KEY_DOWN:
				if (dir != UP) dir = DOWN;
				break;
			case KEY_LEFT:
				if (dir != RIGHT) dir = LEFT;
				break;
			case KEY_RIGHT:
				if (dir != LEFT) dir = RIGHT;
				break;
			case KEY_ESCAPE:
				setCaret(24, 16);
				setColor(0xC0);
				cout << "Аварийный выход\n";
				goto end;
			}
		}
		Sleep(FRAME_INTERVAL);
	} while (!gameOver);
	//game over
	setCaret(18, 16);
	setColor(0xC0);
	printf("Игра окончена, длина змейки - %d", tail);
	//end game
end:
	setCaret(0, 33);
	setColor(0x0F);
	system("PAUSE");
}