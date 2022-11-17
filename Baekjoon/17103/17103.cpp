#include <iostream>

#define MAX 1000001

using namespace std;

int T;
int N; // 2 <= N <= 1000000

bool eratos[MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	eratos[0] = 1;
	eratos[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (eratos[i] == 0 && i * 2 < MAX) {
			for (int j = 2; i * j < MAX; j++) {
				eratos[i * j] = 1;
			}
		}
	}

	cin >> T;
	while (T--) {
		int gold_cnt = 0;

		cin >> N;

		for (int i = 0; i <= N / 2; i++) {
			if (eratos[i] == 0 && eratos[N - i] == 0) {
				gold_cnt++;
			}
		}

		cout << gold_cnt << "\n";
	}

	return 0;
}