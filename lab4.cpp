// ˠ᮰ಮ𭠿 𠡮򠠳.2

#include "header.h"

void lab4() {
	const int N = 20;
	float X[N], A, w[N];

	setlocale(LC_ALL, "Russian");

	// ѫ󷠩� 筠��半	int sel;
	do {
		cout << "»ᥰ貥 񯮱砤୨��1) ѫ󷠩� 筠����) ¢屲蠢𳷭󾜮: ";
		cin >> sel;
		if (sel < 1 && sel > 2)
			cout << "\nͥ䮯󱲨쮥 筠��嬠⢥䨲堫衮 1 먡.\n";
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
		cout << "\n¢夨򥠷豫: ";
		cin >> A;
		for (int i = 0; i < N; i++) {
			do {
				cout << "X" << i + 1 << " = ";
				cin >> X[i];
			} while (X[i] == 0);
		}
	}

	//cout << "¢夨򥠷豫 \n";

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += X[i] + A;
		}
		//cout << "SUM " << sum;
		w[i] = sum / (X[i] * X[i]);
	}

	// ⻢젱񨢠
	// ﮬ孿򼠬屲ନ 젪񨬠뼭蠬譨젫�� 筠����float max = -99999, min = 99999;
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
	cout << "\n\n̠񱨢 w: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]\n";

	cout << "\n̠걨젫�� ��孲 ⠬౱袥 w - " << max << ", ﮤ �尮젢 << max_i + 1 << "\n̨�ૼ� ��孲 ⠬౱袥 w - " << min << ", ﮤ �尮젢 << min_i + 1;
	cout << "\n̠걨젫�� 蠬譨젫�� ��孲 殺屲ࢫ孻 �ﮧ趨蠤𳣠䰳㠮\n";
	w[max_i] = min;
	w[min_i] = max;

	//갠񨢻報ꮡ荊	cout << "\n̠񱨢 w ﮱ률砬孻: [";
	for (int i = 0; i < N; i++) {
		cout << w[i] << "(" << i + 1 << ")";
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]";
}