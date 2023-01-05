#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int R, C, K, W;
int chocolate;
int check_cnt;

int room[21][21];
int therm[21][21];
int plus_t[21][21];
int ch[21][21];
int wind[21][21];

int dr[] = { 0, -1, 0, 1, -1, 0, 1, -1, -1, -1, 1, 1, 1 };
int dc[] = { 0, 1, 1, 1, -1, -1, -1, -1, 0, 1, -1, 0, 1 };

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

typedef struct {
	int r;
	int c;
	int d;
}rcd;
vector<rcd> machine;
typedef struct {
	int next_r;
	int next_c;
}nn;
vector<nn> wall[21][21];

void Input() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 4) {
				machine.push_back({ i, j, room[i][j] });
			}
			else if (room[i][j] == 5) {
				check_cnt++;
			}
		}
	}

	cin >> W;

	for (int i = 0; i < W; i++) {
		int x, y, t = 0;
		cin >> x >> y >> t;
		if (t == 0) {
			wall[x][y].push_back({ x - 1, y });
			wall[x - 1][y].push_back({ x, y });
		}
		else {
			wall[x][y].push_back({ x, y + 1 });
			wall[x][y + 1].push_back({ x, y });
		}
	}
}

void Heat() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			therm[i][j] += wind[i][j];
			wind[i][j] = 0;
		}
	}
}

int WallCheck(int now_r, int now_c, int next_r, int next_c, int d) {
	if (d == 1 || d == 2) {
		if (!wall[now_r][now_c].empty()) {
			for (int i = 0; i < wall[now_r][now_c].size(); i++) {
				int r = wall[now_r][now_c][i].next_r;
				int c = wall[now_r][now_c][i].next_c;

				if (r == next_r && c == now_c) {
					return 0;
				}
			}
		}

		if (!wall[next_r][now_c].empty()) {
			for (int i = 0; i < wall[next_r][now_c].size(); i++) {
				int r = wall[next_r][now_c][i].next_r;
				int c = wall[next_r][now_c][i].next_c;

				if (r == next_r && c == next_c) {
					return 0;
				}
			}
		}
	}
	else {
		if (!wall[now_r][now_c].empty()) {
			for (int i = 0; i < wall[now_r][now_c].size(); i++) {
				int r = wall[now_r][now_c][i].next_r;
				int c = wall[now_r][now_c][i].next_c;

				if (r == now_r && c == next_c) {
					return 0;
				}
			}
		}

		if (!wall[now_r][next_c].empty()) {
			for (int i = 0; i < wall[now_r][next_c].size(); i++) {
				int r = wall[now_r][next_c][i].next_r;
				int c = wall[now_r][next_c][i].next_c;

				if (r == next_r && c == next_c) {
					return 0;
				}
			}
		}
	}

	return 1;
}

void Spread(int r, int c, int d, int depth) {
	if (depth > 5) {
		return;
	}
	else {
		wind[r][c] = (5 - depth);
		int start = d * 3 - 2;
		for (int i = start; i <= start + 2; i++) {
			int next_r = r + dr[i];
			int next_c = c + dc[i];

			if (next_r >= 1 && next_r <= R && next_c >= 1 && next_c <= C && WallCheck(r, c, next_r, next_c, d)) {

				Spread(next_r, next_c, d, depth + 1);
			}
		}
	}
}

void OneStep() {
	for (int i = 0; i < machine.size(); i++) {
		int r = machine[i].r;
		int c = machine[i].c;
		int d = machine[i].d;

		if (d == 1) {
			c++;
		}
		else if (d == 2) {
			c--;
		}
		else if (d == 3) {
			r--;
		}
		else {
			r++;
		}

		Spread(r, c, d, 0);
		Heat();
	}
}

void TwoStep() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			ch[r][c] = 1;

			for (int i = 0; i < 4; i++) {
				int next_r = r + dx[i];
				int next_c = c + dy[i];
				int wall_flag = 0;

				if (!wall[r][c].empty()) {
					for (int i = 0; i < wall[r][c].size(); i++) {
						if (next_r == wall[r][c][i].next_r && next_c == wall[r][c][i].next_c) {
							wall_flag = 1;
						}
					}
				}

				if (next_r >= 1 && next_r <= R && next_c >= 1 && next_c <= C && wall_flag == 0 && ch[next_r][next_c] == 0) {
					int t = abs(therm[r][c] - therm[next_r][next_c]) / 4;

					if (therm[r][c] - therm[next_r][next_c] > 0) {
						plus_t[r][c] -= t;
						plus_t[next_r][next_c] += t;
					}
					else {
						plus_t[r][c] += t;
						plus_t[next_r][next_c] -= t;
					}
				}
			}
		}
	}

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			therm[r][c] += plus_t[r][c];
			plus_t[r][c] = 0;
			ch[r][c] = 0;
		}
	}
}

void ThreeStep() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == R || i == 1 || j == C || j == 1) {
				if (therm[i][j] >= 1) {
					therm[i][j]--;
				}
			}
		}
	}
}

void EatChoco() {
	chocolate++;
}

int FiveStep() {
	int over_cnt = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (room[i][j] == 5 && therm[i][j] >= K) {
				over_cnt++;
			}
		}
	}

	if (over_cnt == check_cnt) {
		return 0;
	}
	else {
		return 1;
	}
}

void Output() {
	cout << chocolate << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r = 1;

	Input();

	while (r) {
		OneStep();
		TwoStep();
		ThreeStep();
		EatChoco();
		r = FiveStep();

		if (chocolate > 100) {
			chocolate = 101;
			r = 0;
		}
	}

	Output();

	return 0;
}