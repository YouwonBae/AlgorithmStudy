#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> map[1000000];
string tomato_data;

int ch[1000000];
int x[1000000];

void DFS(int v) {
	for (int i = 0; i < map[v].size(); i++) {
		if (x[map[v][i]] == 0) {

			x[map[v][i]] = 1;

			DFS(map[v][i]);
		}
	}
}

int main() {
	int M = 0;
	int N = 0;
	int H = 0;
	int a = 0;
	int check_end = 1;
	int year_cnt = 0;
	int no_ripe_flag = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> H;

	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato_data;
			x[a] = stoi(tomato_data);
			a++;
		}
	}

	while (check_end) {

		check_end = 0;

		for (int i = 0; i < a; i++) {
			if (x[i] == 1) {
				if (i % M != 0 || i % M != M - 1) {
					if (i % M == 0) {
						if (x[i + 1] == 0) {
							map[i].push_back(i + 1);
							check_end = 1;
						}
					}
					else if (i % M == M - 1) {
						if (x[i - 1] == 0) {
							map[i].push_back(i - 1);
							check_end = 1;
						}
					}
					else {
						if (x[i + 1] == 0) {
							map[i].push_back(i + 1);
							check_end = 1;
						}
						if (x[i - 1] == 0) {
							map[i].push_back(i - 1);
							check_end = 1;
						}
					}
				}
				if ((i % (M * N)) - M >= 0 || (i % (M * N)) + M < M * N) {
					if ((i % (M * N)) - M < 0) {
						if (x[i + M] == 0) {
							map[i].push_back(i + M);
							check_end = 1;
						}
					}
					else if ((i % (M * N)) + M >= M * N) {
						if (x[i - M] == 0) {
							map[i].push_back(i - M);
							check_end = 1;
						}
					}
					else {
						if (x[i + M] == 0) {
							map[i].push_back(i + M);
							check_end = 1;
						}
						if (x[i - M] == 0) {
							map[i].push_back(i - M);
							check_end = 1;
						}
					}
				}
				if (i - (M * N) >= 0 || i + (M * N) < M * N * H) {
					if (i - (M * N) < 0) {
						if (x[i + (M * N)] == 0) {
							map[i].push_back(i + (M * N));
							check_end = 1;
						}
					}
					else if (i + (M * N) >= M * N * H) {
						if (x[i - (M * N)] == 0) {
							map[i].push_back(i - (M * N));
							check_end = 1;
						}
					}
					else {
						if (x[i + (M * N)] == 0) {
							map[i].push_back(i + (M * N));
							check_end = 1;
						}
						if (x[i - (M * N)] == 0) {
							map[i].push_back(i - (M * N));
							check_end = 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < M * N * H; i++) {
			if (x[i] == 1) {
				DFS(i);
				map[i].clear();
			}
		}

		if (check_end == 1) year_cnt++;
	}

	for (int i = 0; i < M * N * H; i++) {
		if (x[i] == 0) {
			no_ripe_flag = -1;
		}
	}

	if (no_ripe_flag == -1)		cout << no_ripe_flag << "\n";
	else						cout << year_cnt << "\n";

	return 0;
}