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
	cout << "Сортировка текстового массива\n\nМассив:\n\n";
	setColor(0x0F);
	string s[20] = {
		"ИвановСМ",
		"БалашовДЗ",
		"ГерасимовАР",
		"ЛитвиновМН",
		"АлександровАМ",
		"ЗайцевЯМ",
		"КазаковФА",
		"МоисееваВГ",
		"СергееваЕЯ",
		"БеловТД",
		"ИльинаЯЯ",
		"МалаховаСГ",
		"РожковаДМ",
		"ЧеркасовМС",
		"ГерасимовНЯ",
		"БолдыреваВА",
		"ЛогиновДИ",
		"ОрловАД",
		"ЛапинаАМ",
		"КиселевДК"
	};
	for (int i = 0; i < 20; i++) {
		printf("%d. ", i + 1);
		cout << s[i] << endl;
	}
	for (int i = 0; i < 20; i++)
		a[i] = s[i];

	char key;
	cout << "\nПорядок сортировки:\n";
	cout << "1) По возрастанию\n";
	cout << "2) По убыванию\n";
	key = _getch();
	cout << "\nСортировка по ";
	setColor(0x0C);
	switch (key) {
	case '1':
		ascending = false;
		cout << "возрастанию\n";
		break;
	case '2':
		ascending = true;
		cout << "убыванию\n";
		break;
	}
	setColor(0x0F);
	cout << "\nВыбор сортировки:\n";
	cout << "1) Пузырьком\n";
	cout << "2) Выбором\n";
	cout << "3) Быстрая\n";
	key = _getch();
	string cnt;
	int k;
	setColor(0x0F);
	cout << "\nМассив, отсортированный методом ";
	setColor(0x0C);
	long long start_time, end_time;
	switch (key) {
	case '1':
		cout << "пузырька";
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
		cout << "выбора";
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
		cout << "быстрой сортировки";
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
	//Выбор, пузырька, быстрой
	cout << endl;
	setColor(0x0B);
	for (int i = 0; i < 20; i++) {
		printf("%d. ", i + 1);
		cout << a[i] << endl;
	}
	setColor(0x0F);
	cout << "\nВремя, затраченное на сортировку: ";
	setColor(0x0C);
	cout << time / 1000.0 << "мс.";
	setColor(0x0F);
	system("PAUSE");
}