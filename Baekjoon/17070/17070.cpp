#include <iostream>
#include <vector>

#define MAX 16

using namespace std;

int N; // 3 <= N <= 16
int home[MAX][MAX];
int check[MAX][MAX];

int match_cnt;

int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};

vector<int> P[3];

void DFS(int now_x, int now_y, int now_pose) {
	if (now_x == N - 1 && now_y == N - 1) {
		match_cnt++;
	}
	else {
		for (int i = 0; i < P[now_pose].size(); i++) {
			int next_pose = P[now_pose][i];
			int next_x = now_x + dx[next_pose];
			int next_y = now_y + dy[next_pose];

			//P[pose][i] == 0 가로
			//P[pose][i] == 1 대각
			//P[pose][i] == 2 세로
			if (next_pose == 0 || next_pose == 2) {
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N &&
					home[next_y][next_x] != 1 &&
					check[next_y][next_x] == 0) {
					check[next_y][next_x] = 1;

					DFS(next_x, next_y, next_pose);
					check[next_y][next_x] = 0;
				}
			}
			else if (next_pose == 1) {
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N &&
					home[next_y][next_x] != 1 && home[next_y - 1][next_x] != 1 && home[next_y][next_x - 1] != 1 &&
					check[next_y][next_x] == 0) {
					check[next_y][next_x] = 1;

					DFS(next_x, next_y, next_pose);
					check[next_y][next_x] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> home[i][j];
		}
	}

	P[0].push_back(0);
	P[0].push_back(1);

	P[1].push_back(0);
	P[1].push_back(1);
	P[1].push_back(2);

	P[2].push_back(1);
	P[2].push_back(2);

	check[0][0] = 1;
	check[0][1] = 1;
	DFS(1, 0, 0);

	cout << match_cnt;
	
	return 0;
}