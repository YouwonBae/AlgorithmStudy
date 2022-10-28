#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 51

int country[MAX][MAX];
int uni[MAX][MAX];
int ch[MAX][MAX];
int N; // 1 ¡Â N ¡Â 50
int L, R; // 1 ¡Â L ¡Â R ¡Â 100

int union_cnt;
int popula_sum;
int migration_cnt;
int break_cnt;

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS() {
	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
				if (ch[next_y][next_x] == 0 && abs(country[next_y][next_x] - country[now_y][now_x]) >= L && abs(country[next_y][next_x] - country[now_y][now_x]) <= R) {
					ch[next_y][next_x] = 1;
					uni[next_y][next_x] = 1;

					popula_sum += country[next_y][next_x];

					Q.push({ next_x , next_y });

					union_cnt++;
					break_cnt++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> L >> R;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> country[y][x];
		}
	}

	while (1) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (ch[y][x] == 0) {
					Q.push({ x , y });
					BFS();

					if (union_cnt > 0) {
						for (int y = 0; y < N; y++) {
							for (int x = 0; x < N; x++) {
								if (uni[y][x] == 1) {
									country[y][x] = popula_sum / union_cnt;
								}
							}
						}
					}

					popula_sum = 0;
					union_cnt = 0;
					memset(uni, 0, sizeof(uni));
				}
			}
		}

		if (break_cnt < 2)		break;

		migration_cnt++;

		break_cnt = 0;
		memset(ch, 0, sizeof(ch));
	}

	cout << migration_cnt;

	return 0;
}