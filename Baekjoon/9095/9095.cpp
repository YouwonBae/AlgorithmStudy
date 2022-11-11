#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N;

int correct;
int dx[] = { 1, 2, 3 };

queue<int> Q;

void BFS() {
	while (!Q.empty()) {
		int now_x = Q.front();
		Q.pop();

		for (int i = 0; i < 3; i++) {
			int next_x = now_x + dx[i];

			if (next_x >= 0 && next_x <= N) {

				if (next_x == N) {
					correct++;
				}

				Q.push(next_x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> N;

		Q.push(0);
		BFS();

		cout << correct << "\n";

		correct = 0;
	}

	return 0;
}