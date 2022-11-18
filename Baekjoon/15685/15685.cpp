#include <iostream>
#include <stack>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int N; // 1 <= N <= 20
int map[MAX][MAX];
int ch[MAX][MAX];

int last_x;
int last_y;
int d_length;

int result;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int c_dx[] = { 1, 0, 1 };
int c_dy[] = { 0, 1, 1 };

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;
vector<int> dir_list;
stack<int> s;

void BFS() {
	while (!Q.empty()) {
		int dragon_edge = 0;
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();

		for (int i = 0; i < 3; i++) {
			int find_x = now_x + c_dx[i];
			int find_y = now_y + c_dy[i];

			if (find_x >= 0 && find_x < MAX && find_y >= 0 && find_y < MAX) {
				if (map[find_y][find_x] == 1 && map[now_y][now_x] == 1) {
					dragon_edge++;
				}

				if (ch[find_y][find_x] == 0) {
					ch[find_y][find_x] = 1;

					Q.push({ find_x , find_y });
				}
			}
		}

		if (dragon_edge == 3) {
			result++;
		}
	}
}

int NextDir() {
	int length = 0;

	for (int i = 0; i < dir_list.size(); i++) {
		s.push(dir_list[i]);
	}

	while (!s.empty()) {
		int n_dir = 0;
		n_dir = s.top() + 1;

		if (n_dir > 3) {
			n_dir = 0;
		}

		dir_list.push_back(n_dir);
		length++;
		s.pop();
	}

	return dir_list.size() - length;
}

void DragonPlus(int now_x, int now_y, int d) {
	int next_x = now_x + dx[d];
	int next_y = now_y + dy[d];

	map[next_y][next_x] = 1;

	last_x = next_x;
	last_y = next_y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		dir_list.push_back(d);

		last_x = x;
		last_y = y;
		map[last_y][last_x] = 1;
		DragonPlus(last_x, last_y, d);
		d_length = NextDir();

		while (g--) {
			for (int j = d_length; j < dir_list.size(); j++) {
				DragonPlus(last_x, last_y, dir_list[j]);
			}

			d_length = NextDir();
		}

		dir_list.clear();
	}

	Q.push({ 0, 0 });
	ch[0][0] = 1;
	BFS();

	cout << result;

	return 0;
}