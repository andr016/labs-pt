// Лабораторная работа 2.1

#include "header.h"

void lab1() {
	// подпись
	cout << "Задание 2.1:\tРазветвляющий алгоритм\n\n";

	const int x_lower = 5;
	const int x_higher = 10;
	double a, b, x, f, y;

	// ввод переменных a, b
	cout << "Введите переменные в формате: \"A B\"\n";
	cin >> a >> b;

	// эхо-печать
	cout << "\nВведённые переменные:\na = " << a << "\nb = " << b << endl << endl;

	// определение x
	//x = sqr(a) * sqr(b) * (a - b);
	x = a * a * b * b * (a - b);

	// определение значения функции f
	if (x < x_lower)
		f = x * (a + b);
	else if (x >= x_higher)
		//	f = sqr(b);
		f = b * b;
	else
		//	f = sqr(x) + a;
		f = x * x + a;

	// определение y
	//y = f * (x / sqr(a - b));
	y = f * (x / (a - b) * (a - b));

	// вывод
	cout << "Результаты:\nx = " << x << "\nf = " << f << "\ny = " << y << endl;
}


void lab2() {
	// подпись
	cout << "Задание 2.2 - Тема: \"Разветвляющий алгоритм\".\n";

	int z, v, x, k;
	int y;

	int i = 1;

	do {
		cout << "Тест " << i << "\n";
		k = 0;

		// ввод переменных
		cout << "Введите переменные в формате \"Z V X\":\n";
		cin >> z >> v >> x;

		cout << "\nz = " << z << "\nv = " << v << "\nx = " << x << "\n\n";

		cout << "Чётные переменные - ";

		if (z % 2 == 0) {
			cout << "z = " << z;
			k++;
		}

		if (v % 2 == 0) {
			cout << "v = " << v;
			k++;
		}

		if (x % 2 == 0) {
			cout << "x = " << x;
			k++;
		}

		if (k == 0) {
			cout << "отсутствуют\n";
		}
		else {
			cout << ". Количество - " << k << endl;
		}
		cout << "Вы хотите продолжить?\n1 - Да\n0 - Нет\n";
		cin >> y;
		i++;
	} while (y != 0);
	cout << "Кол-во выполненных тестов: " << i - 1;
}

#define KOLVO 30

void lab3()
{
	int i, N, toc;
	float a, k, X1, dX, X, Y;

	// подпись
	cout << "Задание 3.1:\tЦиклические алгоритмы\n\t\tОрганизация цикла с несколькими параметрами и проверкой условий\n\n";

	do
	{
		cout << "Введите значение A (положительное): ";
		cin >> a;
		// ввод а
		if (a <= 0)
		{
			cout << "Введено неверное значение a" << "\n";
		}
	} while (a <= 0);


	do
	{
		cout << "Введите целое, положительное значение параметра N (кол-во точек), большее 1: ";
		cin >> N;
		// ввод точек
		if (N <= 1)
		{
			cout << "Введено неверное значение N" << "\n";
		}
	} while (N <= 1);

	// расчёт X1
	X1 = -10 * a;

	cout << "a = " << a << "\nN = " << N << "\nX1 = " << X1 << endl;
	do
	{
		cout << "Введите значение k (k*a > " << X1 / a << "): ";
		cin >> k; //ввод параметра k
		if (k * a <= X1)
		{
			cout << "Введено неверное значение параметра k" << "\n";
		}
	} while (k * a <= X1);

	dX = a / 2; // dX
	X = X1;
	cout << "N" << setw(10) << "X" << setw(10) << "Y" << setw(1) << endl;
	for (toc = 1; toc < KOLVO; toc++)
	{
		cout << ("_");
	}
	cout << endl;
	for (i = 0; i < N; i++)
	{
		if (X <= k * a) //условие
		{
			Y = -((X + 3 * a) * (X + 3 * a)) - 2 * a; //первый вид
		}
		else
		{
			Y = a * cos(X + 3 * a) - 3 * a; //второй вид
		}
		cout << setw(10) << left << i + 1;
		cout << setw(10) << left << floor(X * 1000 + 0.5) / 1000 << right << setw(10) << left << floor(Y * 1000 + 0.5) / 1000 << endl;//Вывод X
		X = X + dX; // +шаг
	}
}

void lab4() {
	const int N = 20;
	float X[N], A, w[N];

	setlocale(LC_ALL, "Russian");

	// Случайные значение
	int sel;
	do {
		cout << "Выберите способ задания:\n1) Случайные значения\n2) Ввести вручную\n: ";
		cin >> sel;
		if (sel < 1 && sel > 2)
			cout << "\nНедопустимое значение, введите либо 1 либо 2.\n";
	} while (sel < 1 && sel > 2);

	if (sel == 1) {
		A = rand() % 10;
		cout << "\nA = " << A;
		for (int i = 0; i < N; i++) {
			do {
				X[i] = rand() % 10;
			} while (X[i] == 0);
			cout << "\nX" << i + 1 << " = " << X[i];
		}
	}
	else {
		cout << "\nВведите число A: ";
		cin >> A;
		for (int i = 0; i < N; i++) {
			do {
				cout << "X" << i + 1 << " = ";
				cin >> X[i];
			} while (X[i] == 0);
		}
	}

	//cout << "Введите число A \n";

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += X[i] + A;
		}
		//cout << "SUM " << sum;
		w[i] = sum / (X[i] * X[i]);
	}

	// вывод массива
	// поменять местами максимальное и минимальное значения
	float max = -99999, min = 99999;
	int max_i, min_i;
	for (int i = 0; i < N; i++) {
		//cout << "\nw" << i+1 << " = " << w[i];
		if (w[i] > max) {
			max = w[i];
			max_i = i;
		}
		if (w[i] < min) {
			min = w[i];
			min_i = i;
		}
	}
	cout << "\n\nМассив w: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]\n";

	cout << "\nМаксимальный элемент в массиве w - " << max << ", под номером " << max_i + 1 << "\nМинимальный элемент в массиве w - " << min << ", под номером " << min_i + 1;
	cout << "\nМаксимальный и минимальный элемент переставлены на позиции друг друга.\n";
	w[max_i] = min;
	w[min_i] = max;

	//красивые скобочки
	cout << "\nМассив w после замены: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]";
}

void lab5() {
	setlocale(LC_ALL, "Russian");
	printf("Задание 4:\tАлгоритмы с вложенными циклами:\n\t\tОбработка матриц");
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