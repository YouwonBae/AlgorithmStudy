#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int max_L;
int start_x, start_y;
int finish_x, finish_y;
int cnt = 0;

int ch[301][301];

typedef struct xyz {
	int x;
	int y;
}xy;

queue<xy> Q;

int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { -2, 2, -1, 1, -2, 2, -1, 1 };

void BFS() {

	while (!Q.empty()) {

		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 8; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < max_L && next_y >= 0 && next_y < max_L) {
				if (!ch[next_y][next_x]) {
					Q.push({ next_x, next_y });

					ch[next_y][next_x] = ch[now_y][now_x] + 1;

					if (next_x == finish_x && next_y == finish_y) {
						cout << ch[next_y][next_x] << "\n";
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> max_L >> start_x >> start_y >> finish_x >> finish_y;

		Q.push({ start_x, start_y });

		if (start_x == finish_x && start_y == finish_y)
			cout << 0 << "\n";
		else
			BFS();

		memset(ch, 0, sizeof(ch));
	}

	return 0;
}