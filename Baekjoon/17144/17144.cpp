#include <iostream>
#include <queue>

using namespace std;

#define MAX 50

int R; // R >= 6
int C; // C <= 50
int T; // 1 <= T <= 1000

int sec;

int up_r;
int down_r;

int result;

int room[MAX][MAX];
int dust[MAX][MAX][1000];
int add_dust[MAX][MAX][1000];

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS() {
	while (!Q.empty()) {
		int spread = 0;
		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		if (dust[now_y][now_x][sec] >= 5) {
			for (int i = 0; i < 4; i++) {
				int next_x = now_x + dx[i];
				int next_y = now_y + dy[i];

				if (next_x >= 0 && next_x < C && next_y >= 0 && next_y < R && room[next_y][next_x] >= 0) {

					add_dust[next_y][next_x][sec] += (dust[now_y][now_x][sec] / 5);

					spread++;
				}
			}

			dust[now_y][now_x][sec + 1] = dust[now_y][now_x][sec] - ((dust[now_y][now_x][sec] / 5) * spread);
		}
		else {
			dust[now_y][now_x][sec + 1] = dust[now_y][now_x][sec];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int purifier_cnt = 0;

	cin >> R >> C >> T;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> room[r][c];
			if (room[r][c] == -1)	dust[r][c][0] = 0;
			else					dust[r][c][0] = room[r][c];
			
			if (room[r][c] == -1) {
				if(purifier_cnt == 0)	up_r = r;
				else					down_r = r;

				dust[r][c][0] = 0;

				purifier_cnt++;
			}
		}
	}

	while (T--) {
		// room data
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				Q.push({ c, r });
			}
		}

		// dust spreading
		BFS();

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				dust[r][c][sec + 1] = dust[r][c][sec + 1] + add_dust[r][c][sec];
			}
		}

		// Air purifying
		if (up_r > 0) {
			for (int r = up_r - 1; r > 0; r--) {
				dust[r][0][sec + 1] = dust[r - 1][0][sec + 1];
			}
			for (int c = 0; c < C - 1; c++) {
				dust[0][c][sec + 1] = dust[0][c + 1][sec + 1];
			}
			for (int r = 0; r < up_r; r++) {
				dust[r][C - 1][sec + 1] = dust[r + 1][C - 1][sec + 1];
			}
			for (int c = C - 1; c > 0; c--) {
				dust[up_r][c][sec + 1] = dust[up_r][c - 1][sec + 1];
			}
		}

		if (down_r < R - 1) {
			for (int r = down_r + 1; r < R - 1; r++) {
				dust[r][0][sec + 1] = dust[r + 1][0][sec + 1];
			}
			for (int c = 0; c < C - 1; c++) {
				dust[R - 1][c][sec + 1] = dust[R - 1][c + 1][sec + 1];
			}
			for (int r = R - 1; r > down_r; r--) {
				dust[r][C - 1][sec + 1] = dust[r - 1][C - 1][sec + 1];
			}
			for (int c = C - 1; c > 0; c--) {
				dust[down_r][c][sec + 1] = dust[down_r][c - 1][sec + 1];
			}
		}

		sec++;
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			result += dust[r][c][sec];
		}
	}

	cout << result;

	return 0;
}
