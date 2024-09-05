// ������������ ������ 4

#include "header.h"

void lab5() {
	setlocale(LC_ALL, "Russian");
	printf("������� 4:\t��������� � ���������� �������:\n\t\t��������� ������");
	printf("\n\n��������:\t������� ��. 1����2\n\t\t������� �.�.\n\n");
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