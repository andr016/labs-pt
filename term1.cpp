// ������������ ������ 2.1

#include "header.h"

void lab1() {
	// �������
	cout << "������� 2.1:\t������������� ��������\n\n";

	const int x_lower = 5;
	const int x_higher = 10;
	double a, b, x, f, y;

	// ���� ���������� a, b
	cout << "������� ���������� � �������: \"A B\"\n";
	cin >> a >> b;

	// ���-������
	cout << "\n�������� ����������:\na = " << a << "\nb = " << b << endl << endl;

	// ����������� x
	//x = sqr(a) * sqr(b) * (a - b);
	x = a * a * b * b * (a - b);

	// ����������� �������� ������� f
	if (x < x_lower)
		f = x * (a + b);
	else if (x >= x_higher)
		//	f = sqr(b);
		f = b * b;
	else
		//	f = sqr(x) + a;
		f = x * x + a;

	// ����������� y
	//y = f * (x / sqr(a - b));
	y = f * (x / (a - b) * (a - b));

	// �����
	cout << "����������:\nx = " << x << "\nf = " << f << "\ny = " << y << endl;
}


void lab2() {
	// �������
	cout << "������� 2.2 - ����: \"������������� ��������\".\n";

	int z, v, x, k;
	int y;

	int i = 1;

	do {
		cout << "���� " << i << "\n";
		k = 0;

		// ���� ����������
		cout << "������� ���������� � ������� \"Z V X\":\n";
		cin >> z >> v >> x;

		cout << "\nz = " << z << "\nv = " << v << "\nx = " << x << "\n\n";

		cout << "׸���� ���������� - ";

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
			cout << "�����������\n";
		}
		else {
			cout << ". ���������� - " << k << endl;
		}
		cout << "�� ������ ����������?\n1 - ��\n0 - ���\n";
		cin >> y;
		i++;
	} while (y != 0);
	cout << "���-�� ����������� ������: " << i - 1;
}

#define KOLVO 30

void lab3()
{
	int i, N, toc;
	float a, k, X1, dX, X, Y;

	// �������
	cout << "������� 3.1:\t����������� ���������\n\t\t����������� ����� � ����������� ����������� � ��������� �������\n\n";

	do
	{
		cout << "������� �������� A (�������������): ";
		cin >> a;
		// ���� �
		if (a <= 0)
		{
			cout << "������� �������� �������� a" << "\n";
		}
	} while (a <= 0);


	do
	{
		cout << "������� �����, ������������� �������� ��������� N (���-�� �����), ������� 1: ";
		cin >> N;
		// ���� �����
		if (N <= 1)
		{
			cout << "������� �������� �������� N" << "\n";
		}
	} while (N <= 1);

	// ������ X1
	X1 = -10 * a;

	cout << "a = " << a << "\nN = " << N << "\nX1 = " << X1 << endl;
	do
	{
		cout << "������� �������� k (k*a > " << X1 / a << "): ";
		cin >> k; //���� ��������� k
		if (k * a <= X1)
		{
			cout << "������� �������� �������� ��������� k" << "\n";
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
		if (X <= k * a) //�������
		{
			Y = -((X + 3 * a) * (X + 3 * a)) - 2 * a; //������ ���
		}
		else
		{
			Y = a * cos(X + 3 * a) - 3 * a; //������ ���
		}
		cout << setw(10) << left << i + 1;
		cout << setw(10) << left << floor(X * 1000 + 0.5) / 1000 << right << setw(10) << left << floor(Y * 1000 + 0.5) / 1000 << endl;//����� X
		X = X + dX; // +���
	}
}

void lab4() {
	const int N = 20;
	float X[N], A, w[N];

	setlocale(LC_ALL, "Russian");

	// ��������� ��������
	int sel;
	do {
		cout << "�������� ������ �������:\n1) ��������� ��������\n2) ������ �������\n: ";
		cin >> sel;
		if (sel < 1 && sel > 2)
			cout << "\n������������ ��������, ������� ���� 1 ���� 2.\n";
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
		cout << "\n������� ����� A: ";
		cin >> A;
		for (int i = 0; i < N; i++) {
			do {
				cout << "X" << i + 1 << " = ";
				cin >> X[i];
			} while (X[i] == 0);
		}
	}

	//cout << "������� ����� A \n";

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += X[i] + A;
		}
		//cout << "SUM " << sum;
		w[i] = sum / (X[i] * X[i]);
	}

	// ����� �������
	// �������� ������� ������������ � ����������� ��������
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
	cout << "\n\n������ w: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]\n";

	cout << "\n������������ ������� � ������� w - " << max << ", ��� ������� " << max_i + 1 << "\n����������� ������� � ������� w - " << min << ", ��� ������� " << min_i + 1;
	cout << "\n������������ � ����������� ������� ������������ �� ������� ���� �����.\n";
	w[max_i] = min;
	w[min_i] = max;

	//�������� ��������
	cout << "\n������ w ����� ������: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]";
}

void lab5() {
	setlocale(LC_ALL, "Russian");
	printf("������� 4:\t��������� � ���������� �������:\n\t\t��������� ������");
	printf("������� ������ ������� � ������� \"������ ������\": ");
	const int N = 100;
	int w, h;
	cin >> w >> h;
	float m[N][N];
	int sel;
	do {
		printf("������� ������ ������� �������:\n1. ��������� �����\n2. �������\n");
		cin >> sel;
		if (sel < 1 && sel > 2)
			printf(ERR);
	} while (sel < 1 && sel > 2);
	for (int i = 0; i < h; i++) {
		printf("\n������ %d", i + 1);
		for (int j = 0; j < w; j++) {
			printf("\n������ [%d, %d] = ", i + 1, j + 1);
			if (sel == 1) {
				m[i][j] = rand() % 20;
				cout << m[i][j];
			}
			else { cin >> m[i][j]; }
		}
	}
	float sum = 0;
	cout << "\n\n�������:\n";
	// ����� �������
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) { cout << setw(4) << m[i][j]; sum += m[i][j]; }
		cout << endl;
	}
	float sr = sum / (w * h);
	printf("\n������� �������������� ������� - %f\n", sr);
	int arr[N], k = 0;
	// �������� ������� �� ��������
	for (int i = 0; i < w; i++) {
		// ������ ������� ������� ������ ���������� �������� ����������.
		if (m[0][i] < (m[h - 1][i] * 2)) {
			arr[k] = i;
			k++;
			for (int j = 0; j < h; j++) { m[j][i] /= sr; }
		}
	}
	cout << "\n������ �� ������� ��������, ��������������� ������� ������: [";
	for (int i = 0; i < k; i++) {
		cout << arr[i] + 1;
		if (i < k - 1) cout << ", ";
	}
	cout << "]\n\n�������� �������:\n";
	// ����� �������
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) { cout << setw(16) << m[i][j]; }
		cout << endl;
	}
}