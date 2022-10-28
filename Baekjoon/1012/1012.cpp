#include <iostream>
#include <vector>
#include <queue>

#define MAX 50

using namespace std;

int M = 0;
int N = 0;

int group_cnt[10000];

int map[MAX][MAX] = {0, };
int DFS_ch[MAX][MAX] = {0, };

int x_way[4] = { 1, -1, 0, 0 };
int y_way[4] = { 0, 0, 1, -1 };

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int next_x = x + x_way[i];
		int next_y = y + y_way[i];
		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
			if (map[next_y][next_x] == 1 && DFS_ch[next_y][next_x] == 0) {
				DFS_ch[next_y][next_x] = 1;

				DFS(next_y, next_x);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	int K = 0;
	int X = 0;
	int Y = 0;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && DFS_ch[i][j] == 0) {
					DFS(i, j);
					group_cnt[t]++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				DFS_ch[i][j] = 0;
			}
		}
	}

	for (int t = 0; t < T; t++) {
		cout << group_cnt[t] << "\n";
	}

	return 0;
}