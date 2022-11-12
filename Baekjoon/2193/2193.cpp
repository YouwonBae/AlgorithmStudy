#include <iostream>

using namespace std;

int N; // 1 <= N <= 90
long long pinary[91];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	pinary[0] = 0;
	pinary[1] = 1;
	pinary[2] = 1;

	cin >> N;

	if (N > 2) {
		for (int i = 3; i <= N; i++) {
			pinary[i] = pinary[i - 1] + pinary[i - 2];
		}
	}

	cout << pinary[N];

	return 0;
}