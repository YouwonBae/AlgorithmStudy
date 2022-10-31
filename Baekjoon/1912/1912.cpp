#include <iostream>
#include <queue>

using namespace std;

int N;
int sum;
int result;

int list[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int result = -100000000;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 1; i <= N; i++) {
		if (list[i - 1] > 0 && list[i - 1] + list[i] > 0) {
			list[i] += list[i - 1];
		}

		if (result < list[i - 1]) {
			result = list[i - 1];
		}
	}

	cout << result;

	return 0;
}