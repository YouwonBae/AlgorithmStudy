#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N; // 3 <= N <= 300
int M; // 3 <= M <= 300

int arctic[301][301];
int next_arctic[301][301];
int check[301][301];

int iceberg;
int year_cnt = -1;
int melt;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;
queue<xy> Q;

void GlobalWarming() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arctic[y][x] != 0) {
				for (int i = 0; i < 4; i++) {
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if (next_x >= 0 && next_x <= 300 && next_y >= 0 && next_y <= 300 && arctic[next_y][next_x] == 0) {
						
					}
				}
			}
		}
	}
}

void BFS() {
	while (!Q.empty()) {
		int sea_cnt = 0;
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x <= 300 && next_y >= 0 && next_y <= 300) {
				if (arctic[next_y][next_x] == 0) {
					sea_cnt++;
				}
				else {
					if (check[next_y][next_x] == 0) {
						check[next_y][next_x] = 1;

						Q.push({ next_x , next_y });
					}
				}
			}
		}

		next_arctic[now_y][now_x] = arctic[now_y][now_x] - sea_cnt;
		if (next_arctic[now_y][now_x] < 0) {
			next_arctic[now_y][now_x] = 0;
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
			cin >> arctic[y][x];
		}
	}

	while (iceberg < 2) {
		int melt_out = 1;

		year_cnt++;

		iceberg = 0;

		memcpy(next_arctic, arctic, sizeof(arctic));

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (arctic[y][x] != 0) {
					melt_out = 0;

					if (check[y][x] == 0) {
						iceberg++;
						check[y][x] = 1;
						Q.push({ x, y });
						BFS();
					}
				}
			}
		}

		if (melt_out == 1) {
			melt = 1;
			break;
		}

		memcpy(arctic, next_arctic, sizeof(next_arctic));
		memset(check, 0, sizeof(check));
	}

	if (melt == 0) {
		cout << year_cnt;
	}
	else {
		cout << "0";
	}

	return 0;
}