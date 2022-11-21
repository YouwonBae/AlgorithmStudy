#include <iostream>
#include <cstring>

#define MAX 101

using namespace std;

int N; // 2 <= N <= 100
int L; // 1 <= L <= N

int pass;

int result;

int map[MAX][MAX];
int slope[MAX][MAX];

void Y_Slope(int now_y, int now_x) {
	if (now_x == N - 1) {
		pass = 1;
		return;
	}
	else {
		int next_x = now_x + 1;

		if (map[now_y][next_x] > map[now_y][now_x]) {
			for (int i = 0; i < L; i++) {
				if (now_x - i >= 0 && map[now_y][now_x - i] == map[now_y][next_x] - 1 && slope[now_y][now_x - i] == 0) {
					slope[now_y][now_x - i] = 1;
				}
				else {
					pass = 0;
					return;
				}
			}

			Y_Slope(now_y, next_x);
		}
		else if (map[now_y][next_x] < map[now_y][now_x]) {
			for (int i = 0; i < L; i++) {
				if (next_x + i < N && map[now_y][next_x + i] == map[now_y][now_x] - 1 && slope[now_y][next_x + i] == 0) {
					slope[now_y][next_x + i] = 1;
				}
				else {
					pass = 0;
					return;
				}
			}

			Y_Slope(now_y, now_x + L);
		}
		else {
			Y_Slope(now_y, next_x);
		}
	}
}

void X_Slope(int now_y, int now_x) {
	if (now_y == N - 1) {
		pass = 1;
		return;
	}
	else {
		int next_y = now_y + 1;

		if (map[next_y][now_x] > map[now_y][now_x]) {
			for (int i = 0; i < L; i++) {
				if (now_y - i >= 0 && map[now_y - i][now_x] == map[next_y][now_x] - 1 && slope[now_y - i][now_x] == 0) {
					slope[now_y - i][now_x] = 1;
				}
				else {
					pass = 0;
					return;
				}
			}

			X_Slope(next_y, now_x);
		}
		else if (map[next_y][now_x] < map[now_y][now_x]) {
			for (int i = 0; i < L; i++) {
				if (next_y + i < N && map[next_y + i][now_x] == map[now_y][now_x] - 1 && slope[next_y + i][now_x] == 0) {
					slope[next_y + i][now_x] = 1;
				}
				else {
					pass = 0;
					return;
				}
			}

			X_Slope(now_y + L, now_x);
		}
		else {
			X_Slope(next_y, now_x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> L;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		Y_Slope(y, 0);
		if (pass == 1) {
			result++;
		}

		memset(slope, 0, sizeof(slope));
	}

	for (int x = 0; x < N; x++) {
		X_Slope(0, x);

		if (pass == 1) {
			result++;
		}

		memset(slope, 0, sizeof(slope));
	}

	cout << result;

	return 0;
}