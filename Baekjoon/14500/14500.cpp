#include <iostream>
#include <queue>
#include <cstring>

#define MAX 501

using namespace std;

int N; // 4 <= N <= 500
int M; // 4 <= M <= 500

int sum;

int result;

int paper[MAX][MAX];
int check[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void Triangle(int now_x, int now_y) {
	int side_cnt = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = now_x + dx[i];
		int next_y = now_y + dy[i];

		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
			side_cnt++;
			sum += paper[next_y][next_x];
		}
	}

	if (side_cnt == 3) {
		result = max(result, sum);
	}
	else if (side_cnt == 4) {
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			result = max(result, sum - paper[next_y][next_x]);
		}
	}
}

void Others(int now_x, int now_y, int depth) {
	if (depth == 4) {
		result = max(result, sum);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && check[next_y][next_x] == 0) {
				check[next_y][next_x] = 1;

				sum += paper[next_y][next_x];

				Others(next_x, next_y, depth + 1);
				check[next_y][next_x] = 0;
				sum -= paper[next_y][next_x];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> paper[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			// triangle
			sum += paper[y][x];
			Triangle(x, y);

			sum = 0;

			// others
			sum += paper[y][x];
			check[y][x] = 1;
			Others(x, y, 1);
			check[y][x] = 0;

			sum = 0;
		}
	}

	cout << result;

	return 0;
}