#include <iostream>
#include <queue>
#include <vector>

#define MAX 8

using namespace std;

int N; // 1 <= N <= 8
int M; // 1 <= M <= 8

int wall_cnt;
int cam_num;
int result;

int office[MAX][MAX];
int cctv_sight[MAX][MAX];

vector<int> dir_list[13];
vector<int> dir_vector;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void BigBro(int x, int y, int direction) {
	int next_x = x + dx[direction];
	int next_y = y + dy[direction];

	if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && office[next_y][next_x] != 6) {
		cctv_sight[next_y][next_x] = 7;

		BigBro(next_x, next_y, direction);
	}
}

void MakeSight() {
	int cam_cnt = 0;
	int blind_spot = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (office[y][x] == 1) {
				cctv_sight[y][x] = 1;
				BigBro(x, y, dir_vector[cam_cnt]);
				cam_cnt++;
			}
			else if (office[y][x] == 2) {
				cctv_sight[y][x] = 2;
				if (dir_vector[cam_cnt] == 0) {
					BigBro(x, y, 0);
					BigBro(x, y, 2);
				}
				else {
					BigBro(x, y, 1);
					BigBro(x, y, 3);
				}
				cam_cnt++;
			}
			else if (office[y][x] == 3) {
				cctv_sight[y][x] = 3;
				if (dir_vector[cam_cnt] == 0) {
					BigBro(x, y, 0);
					BigBro(x, y, 3);
				}
				else if (dir_vector[cam_cnt] == 1) {
					BigBro(x, y, 1);
					BigBro(x, y, 0);
				}
				else if (dir_vector[cam_cnt] == 2) {
					BigBro(x, y, 2);
					BigBro(x, y, 1);
				}
				else if (dir_vector[cam_cnt] == 3) {
					BigBro(x, y, 3);
					BigBro(x, y, 2);
				}
				cam_cnt++;
			}
			else if (office[y][x] == 4) {
				cctv_sight[y][x] = 4;
				if (dir_vector[cam_cnt] == 0) {
					BigBro(x, y, 1);
					BigBro(x, y, 0);
					BigBro(x, y, 3);
				}
				else if (dir_vector[cam_cnt] == 1) {
					BigBro(x, y, 2);
					BigBro(x, y, 1);
					BigBro(x, y, 0);
				}
				else if (dir_vector[cam_cnt] == 2) {
					BigBro(x, y, 3);
					BigBro(x, y, 2);
					BigBro(x, y, 1);
				}
				else if (dir_vector[cam_cnt] == 3) {
					BigBro(x, y, 0);
					BigBro(x, y, 3);
					BigBro(x, y, 2);
				}
				cam_cnt++;
			}
			else if (office[y][x] == 5) {
				cctv_sight[y][x] = 5;
				BigBro(x, y, 0);
				BigBro(x, y, 1);
				BigBro(x, y, 2);
				BigBro(x, y, 3);
				cam_cnt++;
			}
			else if (office[y][x] == 6) {
				cctv_sight[y][x] = 6;
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (cctv_sight[y][x] == 0) {
				blind_spot++;
			}
			cctv_sight[y][x] = 0;
		}
	}

	if (blind_spot < result) {
		result = blind_spot;
	}

	dir_vector.pop_back();
}

void MakeDir(int cam) {
	for (int i = 0; i < dir_list[cam].size(); i++) {
		dir_vector.push_back(dir_list[cam][i]);

		if (cam + 1 < cam_num) {
			MakeDir(cam + 1);
			dir_vector.pop_back();
		}
		else {
			MakeSight();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	result = N * M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> office[y][x];

			if (office[y][x] == 1 || office[y][x] == 3 || office[y][x] == 4) {
				for (int i = 0; i < 4; i++) {
					dir_list[cam_num].push_back(i);
				}
				cam_num++;
			}
			else if (office[y][x] == 2) {
				for (int i = 0; i < 2; i++) {
					dir_list[cam_num].push_back(i);
				}
				cam_num++;
			}
			else if (office[y][x] == 5) {
				dir_list[cam_num].push_back(0);
				cam_num++;
			}
			else if (office[y][x] == 6) {
				wall_cnt++;
			}
		}
	}

	if (cam_num == 0) {
		result = (N * M) - wall_cnt;

	}
	else {
		MakeDir(0);
	}

	cout << result << "\n";

	return 0;
}
