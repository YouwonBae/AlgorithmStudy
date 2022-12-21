#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int result;
int eat_fish;

int map[4][4];
int dir[4][4];

int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };

typedef struct {
	int y;
	int x;
	int d;
}fs;
vector<fs> F[17];

typedef struct {
	int y;
	int x;
	int d;
}sh;
sh shark;

void Input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b = 0;
			cin >> a >> b;

			F[a].push_back({ i, j, b });
			map[i][j] = a;
			dir[i][j] = b;
		}
	}
}

void Output() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << dir[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void MoveShark(int y, int x, int d) {
	int move_cnt = 0;

	for (int i = 1; i < 4; i++) {
		int next_y = y + dy[d] * i;
		int next_x = x + dx[d] * i;

		if (next_y >= 0 && next_x >= 0 && next_y < 4 && next_x < 4 && map[next_y][next_x] != 0) {
			int next_d = dir[next_y][next_x];

			move_cnt++;

			eat_fish += map[next_y][next_x];

			MoveShark(next_y, next_x, next_d);
		}
	}

	if (move_cnt == 0) {
		result = max(result, eat_fish);
		return;
	}
}

int RotateDir(int d) {
	d++;

	if (d > 8) {
		d = 1;
	}

	return d;
}

void MoveFish() {
	for (int i = 1; i <= 3; i++) {
		int d = F[i][0].d;
		int rotate_cnt = 0;

		while (1) {
			int next_y = F[i][0].y + dy[d];
			int next_x = F[i][0].x + dx[d];
			int next_i = map[next_y][next_x];
			int next_d = dir[next_y][next_x];

			if (next_y >= 0 && next_x >= 0 && next_y < 4 && next_x < 4 && map[next_y][next_x] != 0) {
				F[i][0].d = d;

				swap(F[i][0].y, next_y);
				swap(F[i][0].x, next_x);
				swap(F[i][0].d, next_d);

				map[next_y][next_x] = next_i;
				dir[next_y][next_x] = F[i][0].d;

				map[F[i][0].y][F[i][0].x] = i;
				dir[F[i][0].y][F[i][0].x] = next_d;

				F[next_i][0].y = next_y;
				F[next_i][0].x = next_x;
				
				break;
			}
			else {
				d = RotateDir(d);
				rotate_cnt++;

				if (rotate_cnt >= 8) {
					break;
				}
			}

			cout << F[3][0].y << ", " << F[3][0].x << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	shark.y = 0;
	shark.x = 0;
	shark.d = dir[shark.y][shark.x];

	map[shark.y][shark.x] = 0;
	dir[shark.y][shark.x] = 0;

	eat_fish += map[0][0];

	MoveFish();
	Output();

	return 0;
}