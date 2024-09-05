// лаб 6

#include "header.h"

void labMask() {
	// cyr
	setlocale(LC_ALL, "Russian");

	const short N = 20, // arr size
		MIN = 100,
		MAX = 32500;

	short m[N];
	cout << "Условие задачи  : Из массива, состоящего из 20 целых случайных чисел в диапазоне от 100 до 32500, вывести числа, удовлетворяющие битовой маске.\n";
	cout << "Входные данные  : Массив из 20 случайных целых чисел в диапазоне от 100 до 32500, вводимая пользователем битовая маска в целочисленном формате\n";
	cout << "Выходные данные : Числа, удовлетворяющие битовой маске\n\n";
	cout << "Массив:\n";

	for (int i = 0; i < N; i++) {
		m[i] = rand() % (MAX - MIN) + MIN;
		cout << m[i] << endl;
	}

	unsigned short bitMask;

	cout << "\nВведите битовую маску: ";
	cin >> bitMask;

	cout << "Числа, удовлетворяющие битовой маске: \n";
	for (int i = 0; i < N; i++) {
		if ((m[i] & bitMask) == m[i] || (m[i] & bitMask) == bitMask)
				printf("%d\n", m[i]);
	}

	system("PAUSE");
}
