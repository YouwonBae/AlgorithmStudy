#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 101

int map[MAX][MAX];
int ch[MAX][MAX];
int M, N;
int K;

int area_cnt;
int partition_cnt;

int result[10000] = { 0, };

typedef struct{
	int x;
	int y;
}xy;

queue<xy> Q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS() {
	while (!Q.empty()) {

		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (map[next_y][next_x] == 0 && ch[next_y][next_x] == 0) {
					ch[next_y][next_x] = 1;

					area_cnt++;

					Q.push({ next_x, next_y });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int start_x, start_y, finish_x, finish_y;

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> start_x >> start_y >> finish_x >> finish_y;
		
		for (int x = start_x; x < finish_x; x++) {
			for (int y = start_y; y < finish_y; y++) {
				map[y][x] = 1;
			}
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (map[y][x] == 0 && ch[y][x] == 0) {
				Q.push({x, y});
				BFS();
				result[partition_cnt] = area_cnt;
				area_cnt = 0;

				partition_cnt++;
			}
		}
	}

	sort(result, result + partition_cnt);

	cout << partition_cnt << "\n";
	for (int i = 0; i < partition_cnt; i++) {
		if(result[i] == 0)	cout << 1 << " ";
		else				cout << result[i] << " ";
	}

	return 0;
}