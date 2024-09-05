// Лабораторная работа 4

#include "header.h"

void lab5() {
	setlocale(LC_ALL, "Russian");
	printf("Задание 4:\tАлгоритмы с вложенными циклами:\n\t\tОбработка матриц");
	printf("\n\nВыполнил:\tСтудент гр. 1бИТС2\n\t\tБрянцев А.М.\n\n");
	printf("Введите размер матрицы в формате \"ШИРИНА ВЫСОТА\": ");
	const int N = 100;
	int w, h;
	cin >> w >> h;
	float m[N][N];
	int sel;
	do {
		printf("Введите способ задания матрицы:\n1. Случайные числа\n2. Вручную\n");
		cin >> sel;
		if (sel < 1 && sel > 2)
			printf(ERR);
	} while (sel < 1 && sel > 2);
	for (int i = 0; i < h; i++) {
		printf("\nСтрока %d", i + 1);
		for (int j = 0; j < w; j++) {
			printf("\nЯчейка [%d, %d] = ", i + 1, j + 1);
			if (sel == 1) {
				m[i][j] = rand() % 20;
				cout << m[i][j];
			}
			else { cin >> m[i][j]; }
		}
	}
	float sum = 0;
	cout << "\n\nМатрица:\n";
	// вывод матрицы
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) { cout << setw(4) << m[i][j]; sum += m[i][j]; }
		cout << endl;
	}
	float sr = sum / (w * h);
	printf("\nСреднее арифметическое матрицы - %f\n", sr);
	int arr[N], k = 0;
	// проверка условий по столбцам
	for (int i = 0; i < w; i++) {
		// первый элемент столбца меньше удвоенного значения последнего.
		if (m[0][i] < (m[h - 1][i] * 2)) {
			arr[k] = i;
			k++;
			for (int j = 0; j < h; j++) { m[j][i] /= sr; }
		}
	}
	cout << "\nМассив из номеров столбцов, соответствующих условию задачи: [";
	for (int i = 0; i < k; i++) {
		cout << arr[i] + 1;
		if (i < k - 1) cout << ", ";
	}
	cout << "]\n\nИтоговая матрица:\n";
	// вывод матрицы
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) { cout << setw(16) << m[i][j]; }
		cout << endl;
	}
}