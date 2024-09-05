#include "Header.h"

CODEMODEL nCode = CD_Ceasar;
char TextCode[128]{ "������������ ������� Windows" },
TextCoding[128]{ "������������ ������� Windows" };
int Limit = 1;


void encode() {
	nCode = CD_Ceasar;
	TextCoding[0] = 0;
	CLEAR;

	setColor(0x0C);
	cout << "����������� ������ ������� \"������\"\n\n";
	//SetColor(0, 15);
	setColor(0x0B);
	cout << "����� ��� ���������� => ";
	setColor(0x0F);
	cout << TextCode << endl;
	setColor(0x0B);
	cout << "�� ������� �������� ������� ����?\n=> "; setColor(0x0F); cin >> Limit;

	for (int i = 0; i < strlen(TextCode); i++) {
		UCHAR ch = TextCode[i], cch = 0;
		UCHAR bc = '�', ec = '�', chE = '�', che = '�';
		UCHAR bbc = 'A', eec = 'z';
		if (ch >= bc && ch <= ec) {
			cch = bc + (ch + Limit - bc) % (ec - bc + 1);
			TextCoding[i] = cch;
		}
		else if (ch >= bbc && ch <= eec) {
			cch = bbc + (ch + Limit - bbc) % (eec - bbc + 1);
			TextCoding[i] = cch;
		}
		else if (ch == chE) {
			TextCoding[i] = '#';
		}
		else if (ch == che) {
			TextCoding[i] = '*';
		}
		else /*if (ch == ' ')*/ TextCoding[i] = ch;
	}
	TextCoding[strlen(TextCode)] = 0;
	cout << "��������� ����������� ��� ������������� => " << TextCoding << endl << endl;
	PAUSE;
}

void decode() {
	CLEAR;
	switch (nCode) {
	case CD_Ceasar:
		for (int i = 0; i < strlen(TextCoding); i++) {
			UCHAR ch = TextCoding[i], cch = 0;
			UCHAR bc = '�', ec = '�', chE = '�', che = '�';
			UCHAR bbc = 'A', eec = 'z';
			if (ch >= bc && ch <= ec) {
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch >= bbc && ch <= eec) {
				cch = (ch - Limit < bbc) ? eec - (bbc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch == '#') {
				TextCoding[i] = chE;
			}
			else if (ch == '*') {
				TextCoding[i] = che;
			}
			else /*if (ch == ' ')*/ TextCoding[i] = ch;
		}
		cout << "��������� ����������� ��� ������������� => " << TextCoding << endl << endl;
		PAUSE;
		break;
	case CD_Dynamic:
		for (int i = 0; i < strlen(TextCoding); i++) {
			UCHAR ch = TextCoding[i], cch = 0;
			UCHAR bc = '�', ec = '�', chE = '�', che = '�';
			UCHAR bbc = 'A', eec = 'z';
			if (ch >= bc && ch <= ec) {
				Limit = i + 1;
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch >= bbc && ch <= eec) {
				Limit = i + 1;
				cch = (ch - Limit < bbc) ? eec - (bbc - (ch - Limit + 1)) : ch - Limit;
				TextCoding[i] = cch;
			}
			else if (ch == '#') {
				TextCoding[i] = chE;
			}
			else if (ch == '*') {
				TextCoding[i] = che;
			}
			else /*if (ch == ' ')*/ TextCoding[i] = ch;
		}
		cout << "��������� ����������� ��� ������������� => " << TextCoding << endl << endl;
		PAUSE;
		break;
	case CD_Bit:
		bitCode(false);
		break;
	}
}


void bitCode(bool pToLeft) {
	nCode = CD_Bit;

	CLEAR;
	int nLen = strlen(TextCoding);
	UCHAR sbit = 0;
	switch (pToLeft) {
	case true:
		sbit = TextCoding[0] & 0x80;
		for (int i = 0; i < nLen - 1; i++) {
			TextCoding[i] <<= 1;
			TextCoding[i] |= ((UCHAR)TextCoding[i + 1] & 0x80) >> 7;
		}
		TextCoding[nLen - 1] <<= 1;
		TextCoding[nLen - 1] |= sbit >> 7;
		break;
	case false:
		sbit = TextCoding[nLen - 1] & 0x01;
		for (int i = nLen - 1; i > 0; i--) {
			TextCoding[i] = (UCHAR)TextCoding[i] >> 1;
			TextCoding[i] |= (TextCoding[i - 1] & 0x01) << 7;
		}
		TextCoding[0] = (UCHAR)TextCoding[0] >> 1;
		TextCoding[0] |= sbit << 7;
		break;
	}
	cout << "��������� ����������� ��� ������������� => " << TextCoding << endl << endl;
	PAUSE;
}

void dynamic() {
	nCode = CD_Dynamic;
	TextCoding[0] = 0;

	CLEAR;
	cout << "����������� ������ ������� \"������ � ������������ ���������\"\n\n";
	setColor(0x0B);
	cout << "����� ��� ���������� => ";
	setColor(0x0F);
	cout << TextCode << endl;


	for (int i = 0; i < strlen(TextCode); i++) {
		UCHAR ch = TextCode[i], cch = 0;
		UCHAR bbc = 'A', eec = 'z';
		UCHAR bc = '�', ec = '�', chE = '�', che = '�';
		if (ch >= bc && ch <= ec) {
			Limit = i + 1;
			cch = bc + (ch + Limit - bc) % (ec - bc + 1);
			TextCoding[i] = cch;
		}
		else if (ch == chE) {
			TextCoding[i] = '#';
		}
		else if (ch == che) {
			TextCoding[i] = '*';
		}
		else if (ch >= bbc && ch <= eec) {
			Limit = i + 1;
			cch = bbc + (ch + Limit - bbc) % (eec - bbc + 1);
			TextCoding[i] = cch;
		}
		else TextCoding[i] = ch;
	}
	TextCoding[strlen(TextCode)] = 0;
	CLEAR;
	cout << "��������� ����������� ��� ������������� => " << TextCoding << endl << endl;
	PAUSE;
}

void labCoding() {
	UCHAR ch = 0;
	do {
		system("cls");
		setColor(0x0C);
		cout << "���� ����������� ������ \n";
		setColor(0x0F);
		cout << "1 - ����� ������\n";
		cout << "2 - ������������ �����������\n";
		cout << "3 - ������� ��������\n";
		cout << "0 - �������������\n";
		cout << "4 - ���������� ������ �����������\n";
		cout << "5 - ���������� ����� ����������\n";
		cout << "6 - ���������� ����������� �����\n";
		cout << "\n\n��� ������ ������� ������� ESC\n";

		ch = _getch();

		switch (ch) {
		case'1':encode();  break;
		case'2':dynamic(); break;
		case'3':bitCode(); break;
		case'0':decode(); break;
		case'4':
			CLEAR;
			setColor(0x0B);
			cout << "������� ����� ��� ����������\n=> ";
			setColor(0x0F);
			cin.getline((char*)TextCode, 128);
			break;
		case'5':CLEAR;
			setColor(0x0B);
			cout << "����� ����������\n=> ";
			setColor(0x0F);
			cout << TextCode << endl; PAUSE;
			break;
		case'6':CLEAR;
			setColor(0x0B);
			cout << "����������� �����\n=> ";
			setColor(0x0F); 
			cout << TextCoding << endl; PAUSE;
			break;
		}
	} while (ch != 27);
}
