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
	// ����������� ���������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	setColor(0x0F);
	
	char key;
	// ������� ������
	do {
	start:
		system("CLS");
		//short a = 4;
		//cout << sizeof(a);
		printf("������� 5:\t�������� ��������� ����\n\n");
		cout << "0) ���������� � ������������\n\n";
		cout << "������ ������������ �����:\n";
		cout << "1) ������ 1-�� ��������\n";
		cout << "2) ������� �������� (�����)\n";
		cout << "L) ��������\n";
		cout << "R) ��������\n";
		cout << "5) ������\n";
		cout << "M) �������\n";
		cout << "6) ����������� �������\n";
		cout << "S) ����������\n";
		cout << "C) ������\n";
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
				cout << "1) ���������� � ������� ������ (2.1)\n";
				cout << "2) ������ �������� ������ � �������� �������(2.2)\n";
				cout << "3) ����������� ����� � ����������� ����������� � ��������� ������� (3.1)\n";
				cout << "4) ��������� ���������� �������� (3.2)\n";
				cout << "5) ��������� ������ (4)\n";
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
		case 'L':case 'l':case '�':case '�':
			labMaze();
			break;
		case 'R':case 'r':case '�':case '�':
			system("CLS");
			cout << "0) ..\n";
			cout << "1) �������� (�������)\n";
			cout << "2) �������� (������)\n";
			cout << "3) ������ (������ �������)\n";
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
		case 'M':case 'm':case '�':case '�':
			labMacro();
			break;
		case '5':
			pLabSnake();
			break;
		case '6':
			labCoding();
			break;
		case 'C':case 'c':case '�':case '�':
			ClassesMenu();
		case 'S':case 's':case '�':case '�':
			labSort();
			break;
		case '4':
			do {
				system("CLS");
				cout << "0) ..\n";
				cout << "1) ������� �������� (�����)\n";
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
	/*cout << "\n�� ������ ����������?\n1. ��\n2. ���\n���� \"I\": ";
	do {
		cin >> cont;
		if (cont < 1 || cont > 2)
			cout << ERR;
	} while (cont < 1 || cont > 2);*/
	return 0;
}