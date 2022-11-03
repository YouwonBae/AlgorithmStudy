#include <iostream>

using namespace std;

int N; // 1 ¡Â N ¡Â 1000000
int A[1000000]; // 1 ¡Â A ¡Â 1000000
int B, C; // 1 ¡Â B, C ¡Â 1000000

long main_monitor;
long sub_monitor;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		int remain = 0;

		main_monitor++;

		remain = A[i] - B;

		if (remain > 0) {
			sub_monitor += (remain / C);

			if (remain % C > 0) {
				sub_monitor++;
			}
		}
	}

	cout << main_monitor + sub_monitor;

	return 0;
}