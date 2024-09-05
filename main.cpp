#include "header.h"

#include <utilapiset.h>

#define NOTE_C 523
#define NOTE_D 587
#define NOTE_E 659
#define NOTE_F 698
#define NOTE_G 784
#define NOTE_A 880
#define NOTE_B 987

int main() {
	// подключение кириллицы
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	setColor(0x0F);
	
	char key;
	// очистка экрана
	do {
	start:
		system("CLS");
		//short a = 4;
		//cout << sizeof(a);
		printf("Задание 5:\tСоздание итогового меню\n\n");
		cout << "0) Информация о программисте\n\n";
		cout << "СПИСОК ЛАБОРАТОРНЫХ РАБОТ:\n";
		cout << "1) Работы 1-го семестра\n";
		cout << "2) Битовые операции (маска)\n";
		cout << "L) Лабиринт\n";
		cout << "R) Рекурсия\n";
		cout << "5) Змейка\n";
		cout << "M) Макросы\n";
		cout << "6) Кодирование цезарем\n";
		cout << "S) Сортировка\n";
		cout << "C) Классы\n";
		key = _getch();
		system("CLS");
		switch (key) {
		case 63:
			goto start;
			break;
		case '0':
			creator();
			break;
		case '1':
				system("CLS");
				cout << "0) ..\n";
				cout << "1) Вычисление с выбором формул (2.1)\n";
				cout << "2) Анализ исходных данных и принятие решения(2.2)\n";
				cout << "3) Организация цикла с несколькими параметрами и проверкой условий (3.1)\n";
				cout << "4) Обработка одномерных массивов (3.2)\n";
				cout << "5) Обработка матриц (4)\n";
				key = _getch();
				switch (key) {
				case '0':
					break;
				case '1':
					lab1();
					break;
				case '2':
					lab2();
					break;
				case '3':
					lab3();
					break;
				case '4':
					lab4();
					break;
				case '5':
					lab5();
					system("PAUSE");
					break;
				}
			break;
		case '2':
			labMask();
			break;
		case 'L':case 'l':case 'Д':case 'д':
			labMaze();
			break;
		case 'R':case 'r':case 'К':case 'к':
			system("CLS");
			cout << "0) ..\n";
			cout << "1) Рекурсия (таблица)\n";
			cout << "2) Рекурсия (график)\n";
			cout << "3) График (первый семестр)\n";
			key = _getch();
			switch (key) {
			case '0':
				break;
			case '1':
				labTable();
				break;
			case '2':
				labGraph();
				break;
			case '3':
				labTerm();
				break;
			}
			break;
		case 'M':case 'm':case 'Ь':case 'ь':
			labMacro();
			break;
		case '5':
			pLabSnake();
			break;
		case '6':
			labCoding();
			break;
		case 'C':case 'c':case 'С':case 'с':
			ClassesMenu();
		case 'S':case 's':case 'Ы':case 'ы':
			labSort();
			break;
		case '4':
			do {
				system("CLS");
				cout << "0) ..\n";
				cout << "1) Битовые операции (маска)\n";
				switch (choose(0, 1)) {
				case 0:
					break;
				case 1:
					labMask();
					break;
				}
				system("PAUSE");
			} while (key != KEY_ESCAPE);
		}
	} while (key != KEY_ESCAPE);
	/*cout << "\nВы хотите продолжить?\n1. Да\n2. Нет\nВвод \"I\": ";
	do {
		cin >> cont;
		if (cont < 1 || cont > 2)
			cout << ERR;
	} while (cont < 1 || cont > 2);*/
	return 0;
}