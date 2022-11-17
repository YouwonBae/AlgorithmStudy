#include <iostream>
#include <vector>

using namespace std;

int N; // 2 <= N <=100
int K; // 0 <= K <=100
int L; // 1 <= L <= 100

int map[100][100];
int dir[10001];
int time_cnt = 0;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

typedef struct {
	int x;
	int y;
}xy;
vector<xy> snake;

int MakeDir(int time, int now_d) {
	int next_d = 0;

	if (dir[time] == 1) {
		next_d = now_d + 1;
	}
	else if (dir[time] == 2) {
		next_d = now_d - 1;
	}
	else {
		next_d = now_d;
	}

	if (next_d > 3) {
		next_d = 0;
	}
	else if (next_d < 0) {
		next_d = 3;
	}

	return next_d;
}

void MoveSnake(int now_x, int now_y, int now_d) {
	int next_d = MakeDir(time_cnt, now_d);
	int next_x = now_x + dx[next_d];
	int next_y = now_y + dy[next_d];

	time_cnt++;

	if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N && map[next_y][next_x] != 3) {
		snake.push_back({ next_x, next_y });

		if (map[next_y][next_x] != 1) {
			int tail_x = snake.front().x;
			int tail_y = snake.front().y;
			snake.erase(snake.begin());

			map[tail_y][tail_x] = 0;
		}

		map[next_y][next_x] = 3;

		MoveSnake(next_x, next_y, next_d);
	}
	else {
		cout << time_cnt << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int y, x = 0;
		cin >> y >> x;

		map[y - 1][x - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char d;
		cin >> t >> d;

		if (d == 'L') {
			dir[t] = 1; // left
		}
		else {
			dir[t] = 2;; // right
		}
	}

	snake.push_back({ 0, 0 });
	map[0][0] = 3;
	MoveSnake(0, 0, 0);

	return 0;
}