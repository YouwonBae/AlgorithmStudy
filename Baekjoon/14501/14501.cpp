#include <iostream>

using namespace std;

int N; // 1 ¡Â N ¡Â 15
int T[16]; // 1 ¡Â T ¡Â 5
int P[16]; // 1 ¡Â P ¡Â 1000
int ch[16];

int day;
int pay;

int result;

void MakePay() {
	for (int i = 1; i <= N; i++) {
		if (ch[i] == 1) {
			pay += P[i];
		}
	}
	if (result < pay) {
		result = pay;
	}

	pay = 0;
}

void MakeSchedule(int day) {
	if (day > N) {
		MakePay();
	}
	else {
		for (int i = day; i <= N; i++) {
			if (i + T[i] - 1 <= N) {
				ch[i] = 1;

				MakeSchedule(i + T[i]);
				ch[i] = 0;
			}
			else {
				MakePay();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	MakeSchedule(1);

	cout << result << "\n";

	return 0;
}