#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 3 <= N <= 50
int M; // 3 <= M <= 50
int R;
int C;
int D;

int map[51][51];
int clean;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int direction(int d, int r) {
	int result = d;

	if (r < 0) {
		int repeat = r * -1;

		while (repeat--) {
			result--;
			if (result < 0) {
				result = 3;
			}
			else if (result > 3) {
				result = 0;
			}
		}
	}
	else {
		int repeat = r;

		while (repeat--) {
			result++;
			if (result < 0) {
				result = 3;
			}
			else if (result > 3) {
				result = 0;
			}
		}
	}

	return result;
}

void DFS(int now_x, int now_y, int now_d) {
	int left_d = direction(now_d, -1);
	int right_d = direction(now_d, 1);
	int back_d = direction(now_d, 2);

	int left_x = now_x + dx[left_d];
	int left_y = now_y + dy[left_d];

	int right_x = now_x + dx[right_d];
	int right_y = now_y + dy[right_d];

	int back_x = now_x + dx[back_d];
	int back_y = now_y + dy[back_d];

	int front_x = now_x + dx[now_d];
	int front_y = now_y + dy[now_d];

	if (map[left_y][left_x] == 0) {
		map[left_y][left_x] = 2;
		clean++;

		DFS(left_x, left_y, left_d);
	}
	else {
		if (map[front_y][front_x] != 0 && map[left_y][left_x] != 0 && map[right_y][right_x] != 0 && map[back_y][back_x] != 0) {
			if (map[back_y][back_x] == 1) { // finish
				cout << clean << "\n";
			}
			else {
				DFS(back_x, back_y, now_d);
			}
		}
		else {
			DFS(now_x, now_y, left_d);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> R >> C >> D;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	map[R][C] = 2;
	clean++;
	DFS(C, R, D);

	return 0;
}
