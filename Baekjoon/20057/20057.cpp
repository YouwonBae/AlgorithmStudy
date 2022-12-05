#include <iostream>

using namespace std;

int N; // 3 <= N <= 499

int result;

int desert[499][499];

int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

int dx[] = { 1, 1, 0, 0, 0, 0, -1, -1, -2, -1 }; // 1 1 2 2 7 7 10 10 5 a
int dy[] = { -1, 1, -2, 2, -1, 1, -1, 1, 0, 0 };
int dp[] = { 1, 1, 2, 2, 7, 7, 10, 10, 5, 0};

void Sand(int now_y, int now_x, int now_s, int dir) {
	int near_s = 0;

	for (int i = 0; i < 10; i++) {
		int next_y = 0;
		int next_x = 0;
		int next_s = ((now_s * dp[i]) / 100);

		if (dir == 1) {
			next_x = now_x + dy[i];
			next_y = now_y + -1 * dx[i];
		}
		else if (dir == 2) {
			next_y = now_y + -1 * dy[i];
			next_x = now_x + -1 * dx[i];
		}
		else if (dir == 3) {
			next_x = now_x + -1 * dy[i];
			next_y = now_y + dx[i];
		}
		else {
			next_y = now_y + dy[i];
			next_x = now_x + dx[i];
		}

		if (i == 9) {
			next_s = now_s - near_s;
		}
		else {
			near_s += next_s;
		}

		if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N) {
			desert[next_y][next_x] += next_s;
		}
		else {
			result += next_s;
		}
	}

	desert[now_y][now_x] = 0;
}

void Spin(int r, int c, int turn, int forward, int length, int dir, int depth) {
	if (depth == N * N) {
		return;
	}
	else {
		forward++;

		int next_r = r + dr[dir];
		int next_c = c + dc[dir];
		int next_dir = dir;
		int next_length = length;

		Sand(next_r, next_c, desert[next_r][next_c], dir);

		if (forward == length) {
			next_dir++;
			if (next_dir > 3) {
				next_dir = 0;
			}

			forward = 0;

			if (turn % 2 != 0) {
				turn++;
				next_length++;
				Spin(next_r, next_c, turn, forward, next_length, next_dir, depth + 1);
			}
			else {
				turn++;
				Spin(next_r, next_c, turn, forward, next_length, next_dir, depth + 1);
			}
		}
		else {
			Spin(next_r, next_c, turn, forward, next_length, next_dir, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> desert[r][c];
		}
	}

	Spin(N / 2, N / 2,0, 0, 1, 0, 1);

	cout << result;

	return 0;
}