#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;

int map[1000][8];
int ch[1000][8];
int wall_map[1000][8] = {0, };

typedef struct xyz {
	int x;
	int y;
}xy;

queue<xy> Q;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, -1, 1};

vector<int> wall[10000];
int wall_ch[10000];
int wall_cnt = 0;

int no_infected_area[] = {0, 0};
int infected_area = 0;
int nonzero_area = 0;

void BFS() {
	infected_area = 0;
	while (!Q.empty()) {

		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (map[next_x][next_y] == 0 && ch[next_x][next_y] == 0 && wall_map[next_x][next_y] == 0) {
					ch[next_x][next_y] = 1;
					infected_area++;
					Q.push({ next_x, next_y });
				}
			}
		}

	}
}

void DFS(int v) {
	wall_cnt++;

	for (int i = 0; i < wall[v].size(); i++) {
		int x = wall[v][i] / M;
		int y = wall[v][i] % M;
		wall_map[x][y] = 1;

		if (wall_cnt == 2) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] == 1) {
						ch[i][j] = 1;
					}
					else if (map[i][j] == 2) {
						ch[i][j] = 1;
						Q.push({ i, j });
					}
					else {
						ch[i][j] = 0;
					}
				}
			}

			BFS();

			wall_map[x][y] = 0;

			nonzero_area = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 0) {
						nonzero_area++;
					}
				}
			}
			no_infected_area[0] = (N * M) - (infected_area + nonzero_area) - 3;

			if (no_infected_area[0] > no_infected_area[1]) no_infected_area[1] = no_infected_area[0];
		}
		else if (wall_ch[wall[v][i]] == 0) {
			DFS(wall[v][i]);
			wall_cnt--;
			for (int j = wall[v][i] + 1; j < N*M; j++) {
				wall_ch[j] = 0;
			}
			wall_ch[wall[v][i]] = 1;
			wall_map[x][y] = 0;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) {
				for (int k = 0; k < (i * M) + j; k++) {
					if (map[k / M][k % M] == 0) {
						wall[k].push_back((i * M) + j);
					}
				}
			}
		}
	}
	
	for (int i = 0; i < N * M; i++) {
		if (map[i/M][i%M] == 0) {
			wall_map[i / M][i % M] = 1;
			DFS(i);
			wall_cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					wall_map[i][j] = 0;
					wall_ch[(i * M) + j] = 0;
				}
			}
		}
	}

	cout << no_infected_area[1];

	return 0;
}