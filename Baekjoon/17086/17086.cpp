#include <iostream>
#include <cstring>
#include <queue>

#define MAX 50

using namespace std;

int N; // 2 <= N <= 50
int M; // 2 <= M <= 50

int safe_dist;
int result;

int shark[MAX][MAX];
int check[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int dy[] = { 0, 1, -1, 0, 1, -1, 1, -1 };

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

void BFS() {
	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();

		for (int i = 0; i < 8; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && check[next_y][next_x] == 0) {
				check[next_y][next_x] = 1;
				dist[next_y][next_x] = dist[now_y][now_x] + 1;

				Q.push({ next_x , next_y });
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
			cin >> shark[y][x];
			if (shark[y][x] == 1) {
				check[y][x] = 1;
				Q.push({ x, y });
			}
		}
	}

	BFS();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			result = max(result, dist[y][x]);
		}
	}

	cout << result;

	return 0;
}