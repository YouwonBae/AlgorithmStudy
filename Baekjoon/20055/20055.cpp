#include <iostream>
#include <vector>

using namespace std;

int N; // 2 ¡Â N ¡Â 100
int F;
int K; // 1 ¡Â K ¡Â 2N

int con_hp;
int step;

int A[201]; // 1 ¡Â A ¡Â 1000
int robot[201];

void MoveBot() {
	for (int i = N - 1; i >= 1; i--) {
		if (robot[i - 1] == 1 && A[i] > 0 && robot[i] == 0) {
			robot[i] = 1;
			robot[i - 1] = 0;
			A[i] -= 1;
		}
	}

	if (robot[N - 1] == 1) {
		robot[N - 1] = 0;
	}

	if (A[0] > 0) {
		robot[0] = 1;
		A[0] -= 1;
	}
}

void MoveCon() {
	for (int i = F; i >= 1; i--) {
		A[i] = A[i - 1];
		if (i <= N - 1) {
			robot[i] = robot[i - 1];
		}
	}

	if (robot[N - 1] == 1) {
		robot[N - 1] = 0;
	}

	A[0] = A[F];
	robot[0] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	F = 2 * N;

	for (int i = 0; i < F; i++) {
		cin >> A[i];
	}

	while(1) {
		MoveCon();
		MoveBot();
		step++;

		for (int i = 0; i < F; i++) {
			if (A[i] == 0) {
				con_hp++;
			}
		}

		if (con_hp >= K) {
			break;
		}

		con_hp = 0;
	}

	cout << step << "\n";

	return 0;
}