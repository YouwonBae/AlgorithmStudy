#include <iostream>
#include <queue>

using namespace std;

int N; // 0 <= N <= 100000
int K; // 0 <= K <= 100000

int ch[1000000];

int result;

typedef struct {
	int n;
	int t;
}nt;

queue<nt> Q;

void BFS() {
	while (!Q.empty()) {
		int now_n = Q.front().n;
		int now_t = Q.front().t;
		Q.pop();

		int next_t = now_t + 1;

		for (int i = 0; i < 3; i++) {
			int next_n = -1;

			if (i == 0) {
				next_n = now_n + 1;
			}
			else if (i == 1) {
				next_n = now_n - 1;
			}
			else {
				if (now_n < K) {
					next_n = now_n * 2;
				}
			}

			if (ch[next_n] == 0 && next_n >= 0 && next_n <= 100000) {
				ch[next_n] = 1;

				if (next_n == K) {
					result += next_t;

					return;
				}

				Q.push({ next_n, next_t });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	if (N == K) {
		cout << '0';
	}
	else {
		Q.push({ N, 0 });
		BFS();
		cout << result;
	}

	return 0;

}