#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define MAX 30

using namespace std;

int L = 0;
int R = 0;
int C = 0;

int way_l[6] = { 1,-1,0,0,0,0 };
int way_r[6] = { 0,0,1,-1,0,0 };
int way_c[6] = { 0,0,0,0,1,-1 };

int map[MAX][MAX][MAX] = {0, };
int BFS_ch[MAX][MAX][MAX] = { 0, };
int dis[MAX][MAX][MAX] = { 0, };

typedef struct {
	int l;
	int r;
	int c;
}lrc;

queue<lrc> Q;
int result_case[1000000];
int minutes[1000000];

void BFS(int t) {
	while (!Q.empty()) {
		int l = Q.front().l;
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();

		for (int i = 0; i < 6; i++) {
			int next_l = l + way_l[i];
			int next_r = r + way_r[i];
			int next_c = c + way_c[i];

			if (next_l >= 0 && next_l < L && next_r >= 0 && next_r < R && next_c >= 0 && next_c < C) {
				if (map[next_l][next_r][next_c] != 0 && BFS_ch[next_l][next_r][next_c] == 0) {
					BFS_ch[next_l][next_r][next_c] = 1;
					Q.push({ next_l, next_r , next_c });

					dis[next_l][next_r][next_c] = dis[l][r][c] + 1;

					if (map[next_l][next_r][next_c] == 3) {
						minutes[t] = dis[next_l][next_r][next_c];
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

	string s;
	int case_cnt = 0;

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		else if ((R < 1 || R > 31) || (L < 1 || L > 31) || (C < 1 || C > 31)) return 0;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> s;
				for (int k = 0; k < C; k++) {
					string map_data = s.substr(k, 1);
					if (map_data == "#") {
						map[i][j][k] = 0;
					}
					else if (map_data == ".") {
						map[i][j][k] = 1;
					}
					else if (map_data == "S") {
						map[i][j][k] = 2;

						BFS_ch[i][j][k] = 1;
						Q.push({ i, j, k });
						dis[i][j][k] = 0;
					}
					else if (map_data == "E") {
						map[i][j][k] = 3;
					}
				}
			}
		}

		BFS(case_cnt);

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (map[i][j][k] == 3) {
						if (BFS_ch[i][j][k] == 0) {
							result_case[case_cnt] = 1;
						}
						else {
							result_case[case_cnt] = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					map[i][j][k] = 0;
					BFS_ch[i][j][k] = 0;
					dis[i][j][k] = 0;
				}
			}
		}

		case_cnt++;
	}

	for (int i = 0; i < case_cnt; i++) {
		if (result_case[i] == 1) {
			cout << "Trapped!" << "\n";
		}
		else if (result_case[i] == 0) {
			cout << "Escaped in " << minutes[i] << " minute(s)." << "\n";
		}
	}

	return 0;
}