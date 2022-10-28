#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 51

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

int island[MAX][MAX];
int ch[MAX][MAX];
int w, h;
int island_cnt;

void BFS() {
	while (!Q.empty()) {

		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 8; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < w && next_y >= 0 && next_y < h) {
				if (island[next_y][next_x] == 1 && ch[next_y][next_x] == 0) {
					ch[next_y][next_x] = 1;
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

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int b = 0; b < h; b++) {
			for (int a = 0; a < w; a++) {
				int land;
				cin >> land;
				island[b][a] = land;
			}
		}

		for (int b = 0; b < h; b++) {
			for (int a = 0; a < w; a++) {
				if (island[b][a] == 1 && ch[b][a] == 0) {
					Q.push({ a, b });
					BFS();

					island_cnt++;
				}
			}
		}

		cout << island_cnt << "\n";
		island_cnt = 0;

		memset(ch, 0, sizeof(ch));
	}

	return 0;
}