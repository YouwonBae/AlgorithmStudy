#include <iostream>

using namespace std;

int N, M; // 1 <= N, M <= 1000000000

void Input() {
	cin >> N >> M;
}

void GoBack(int n, int depth) {
	if (n <= N) {
		if (n == N) {
			cout << depth + 1 << "\n";
			return;
		}
		else {
			cout << "-1" << "\n";
			return;
		}
	}
	else {
		int right = n % 10;

		if (right == 1) {
			GoBack(n / 10, depth + 1);
		}
		else {
			int remain = right % 2;

			if (remain == 0) { // even
				GoBack(n / 2, depth + 1);
			}
			else { // odd
				cout << "-1" << "\n";
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	GoBack(M, 0);

	return 0;
}