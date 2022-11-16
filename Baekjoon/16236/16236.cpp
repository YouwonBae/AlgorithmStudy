#include <iostream>
#include <cstring>
#include <queue>

#define MAX 20

using namespace std;

int N; // 2 <= N <= 20
int sea[MAX][MAX];
int ch[MAX][MAX];

int shark_x;
int shark_y;
int dist;
int shark_size = 2;
int eat_cnt;

int result;

int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

typedef struct {
	int x;
	int y;
	int d;
}xyd;

queue<xyd> Q;

int FindPath() {
	int preys_flag = 0;
	int max_dist = N * N;
	int eat = 0;

	sea[shark_y][shark_x] = 0;

	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		int now_d = Q.front().d;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && ch[next_y][next_x] == 0 && sea[next_y][next_x] <= shark_size && now_d < max_dist) {
				ch[next_y][next_x] = 1;

				if (sea[next_y][next_x] != 0 && sea[next_y][next_x] < shark_size) {
					eat = 1;

					if (preys_flag == 0) {
						shark_y = next_y;
						shark_x = next_x;
						dist = now_d + 1;
						max_dist = dist;
						preys_flag = 1;
					}
					else {
						if (next_y < shark_y) {
							shark_y = next_y;
							shark_x = next_x;
							dist = now_d + 1;
						}
						else if (shark_y == next_y) {
							if (shark_x > next_x) {
								shark_y = next_y;
								shark_x = next_x;
								dist = now_d + 1;
							}
						}
					}
				}

				Q.push({ next_x, next_y, now_d + 1 });
			}
		}
	}

	return eat;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> sea[y][x];
			if (sea[y][x] == 9) {
				shark_x = x;
				shark_y = y;
				ch[y][x] = 1;
				Q.push({ x, y, 0 });
			}
		}
	}

	while (FindPath()) {
		sea[shark_y][shark_x] = 9;
		ch[shark_y][shark_x] = 1;
		Q.push({ shark_x, shark_y, 0 });

		eat_cnt++;

		if (eat_cnt == shark_size) {
			shark_size++;
			eat_cnt = 0;
		}

		result += dist;

		memset(ch, 0, sizeof(ch));
	}

	cout << result << "\n";
	
	return 0;
}