#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N; // 2 <= N <= 100
int top_height;

int region[101][101];
int copy_region[101][101];
int check[101][101];
int safe_zone;
int result;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

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

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_y >= 0 && next_y <= 100 && next_x >= 0 && next_x <= 100 && check[next_y][next_x] == 0 && copy_region[next_y][next_x] > 0) {
				check[next_y][next_x] = 1;

				Q.push({ next_x , next_y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> region[y][x];
			if (region[y][x] > top_height) {
				top_height = region[y][x];
			}
		}
	}

	for (int h = 0; h < top_height; h++) {
		memcpy(copy_region, region, sizeof(region));

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (copy_region[y][x] <= h) {
					copy_region[y][x] = 0;
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (check[y][x] == 0 && copy_region[y][x] > 0) {
					safe_zone++;

					Q.push({ x, y });
					BFS();
				}
			}
		}

		if (result < safe_zone) {
			result = safe_zone;
		}

		memset(check, 0, sizeof(check));
		safe_zone = 0;
	}

	cout << result;

	return 0;
}