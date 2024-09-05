#include "header.h"
#include <ctime>

string a[20];
bool ascending = true;

int part(int start, int end) {
	string opor = a[start];
	int cnt = 0;
	for (int i = start + 1; i <= end; i++) {
		if ((a[i] <= opor) ^ ascending)
			cnt++;
	}
	int oporind = start + cnt;
	string buf = a[start];
	a[start] = a[oporind];
	a[oporind] = buf;

	int i = start, j = end;

	while (i < oporind && j > oporind) {

		while ((a[i] <= opor) ^ ascending) {
			i++;
		}

		while ((a[j] > opor) ^ ascending) {
			j--;
		}

		if (i < oporind && j > oporind) {
			string buf = a[i];
			a[i] = a[j];
			a[j] = buf;
		}
	}

	return oporind;
}

void quickSort(int start, int end) {
	if (start >= end)
		return;

	int p = part(start, end);
	quickSort(start, p - 1);
	quickSort(p + 1, end);
}

void labSort() {
	setColor(0x0E);
	cout << "���������� ���������� �������\n\n������:\n\n";
	setColor(0x0F);
	string s[20] = {
		"��������",
		"���������",
		"�����������",
		"����������",
		"�������������",
		"��������",
		"���������",
		"����������",
		"����������",
		"�������",
		"��������",
		"����������",
		"���������",
		"����������",
		"�����������",
		"�����������",
		"���������",
		"�������",
		"��������",
		"���������"
	};
	for (int i = 0; i < 20; i++) {
		printf("%d. ", i + 1);
		cout << s[i] << endl;
	}
	for (int i = 0; i < 20; i++)
		a[i] = s[i];

	char key;
	cout << "\n������� ����������:\n";
	cout << "1) �� �����������\n";
	cout << "2) �� ��������\n";
	key = _getch();
	cout << "\n���������� �� ";
	setColor(0x0C);
	switch (key) {
	case '1':
		ascending = false;
		cout << "�����������\n";
		break;
	case '2':
		ascending = true;
		cout << "��������\n";
		break;
	}
	setColor(0x0F);
	cout << "\n����� ����������:\n";
	cout << "1) ���������\n";
	cout << "2) �������\n";
	cout << "3) �������\n";
	key = _getch();
	string cnt;
	int k;
	setColor(0x0F);
	cout << "\n������, ��������������� ������� ";
	setColor(0x0C);
	long long start_time, end_time;
	switch (key) {
	case '1':
		cout << "��������";
		start_time = _Xtime_get_ticks();
		for (int j = 19; j > 0; j--) {
			for (int i = 0; i < j; i++) {
				if ((a[i] > a[i + 1]) ^ ascending) {
					string buf = a[i];
					a[i] = a[i + 1];
					a[i + 1] = buf;
				}
			}
		}
		break;
	case '2':
		cout << "������";
		start_time = _Xtime_get_ticks();
		for (int i = 0; i < 19; i++) {
			cnt = a[i];
			k = i;
			for (int j = i + 1; j < 20; j++) {
				if ((a[j] < a[k]) ^ ascending) k = j;
			}
			if (k != i) {
				a[i] = a[k];
				a[k] = cnt;
			}
		}
		break;
	case '3':
		cout << "������� ����������";
		start_time = _Xtime_get_ticks();
		quickSort(0, 19);
		break;
	}
	end_time = _Xtime_get_ticks();
	long long time = end_time - start_time;
	setColor(0x0F);
	/*for (int i = 0; i < 20; i++) {
		printf("%d. ", i + 1);
		cin >> s[i];
	}*/
	//�����, ��������, �������
	cout << endl;
	setColor(0x0B);
	for (int i = 0; i < 20; i++) {
		printf("%d. ", i + 1);
		cout << a[i] << endl;
	}
	setColor(0x0F);
	cout << "\n�����, ����������� �� ����������: ";
	setColor(0x0C);
	cout << time / 1000.0 << "��.";
	setColor(0x0F);
	system("PAUSE");
}