#include <iostream>

#define MAX 1001

using namespace std;

int N; // 2 <= N <= 1000
int K;

int erase_cnt;

bool eratos[MAX] = { 0, };

int Eratos() {
	eratos[0] = 1;
	eratos[1] = 1;

	for (int i = 2; i <= N; i++) {
		if (eratos[i] == 0) {
			for (int j = 1; i * j <= N; j++) {
				if (eratos[i * j] == 0) {
					erase_cnt++;
					eratos[i * j] = 1;

					if (erase_cnt == K) {
						return i * j;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	cout << Eratos();

	return 0;
}