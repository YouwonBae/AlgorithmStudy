#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

string tomato_data;

vector<int> map[1000000];
queue<int> Q;

int M = 0;
int N = 0;
int H = 0;

int ch[1000000];
int x[1000000];

int day_cnt = -1;
int push_cnt = 0;
int pop_cnt = 0;
int century_cnt = 0;

void BFS(int a) {
	int n = 0;

	for (int i = 0; i < a; i++) {
		if (x[i] != -1) {
			if (i % M != 0 || i % M != M - 1) {
				if (i % M == 0) {
					if (x[i + 1] == 0) {
						map[i].push_back(i + 1);
					}
				}
				else if (i % M == M - 1) {
					if (x[i - 1] == 0) {
						map[i].push_back(i - 1);
					}
				}
				else {
					if (x[i + 1] == 0) {
						map[i].push_back(i + 1);
					}
					if (x[i - 1] == 0) {
						map[i].push_back(i - 1);
					}
				}
			}
			if ((i % (M * N)) - M >= 0 || (i % (M * N)) + M < M * N) {
				if ((i % (M * N)) - M < 0) {
					if (x[i + M] == 0) {
						map[i].push_back(i + M);
					}
				}
				else if ((i % (M * N)) + M >= M * N) {
					if (x[i - M] == 0) {
						map[i].push_back(i - M);
					}
				}
				else {
					if (x[i + M] == 0) {
						map[i].push_back(i + M);
					}
					if (x[i - M] == 0) {
						map[i].push_back(i - M);
					}
				}
			}
			if (i - (M * N) >= 0 || i + (M * N) < M * N * H) {
				if (i - (M * N) < 0) {
					if (x[i + (M * N)] == 0) {
						map[i].push_back(i + (M * N));
					}
				}
				else if (i + (M * N) >= M * N * H) {
					if (x[i - (M * N)] == 0) {
						map[i].push_back(i - (M * N));
					}
				}
				else {
					if (x[i + (M * N)] == 0) {
						map[i].push_back(i + (M * N));
					}
					if (x[i - (M * N)] == 0) {
						map[i].push_back(i - (M * N));
					}
				}
			}

			if (x[i] == 1) {
				Q.push(i);
				century_cnt++;
			}
		}
	}

	while (!Q.empty()) {

		n = Q.front();
		Q.pop();
		pop_cnt++;

		for (int i = 0; i < map[n].size(); i++) {
			if (x[map[n][i]] == 0) {
				x[map[n][i]] = 1;
				Q.push(map[n][i]);
				push_cnt++;
			}
		}

		if (pop_cnt == century_cnt) {
			day_cnt++;
			century_cnt = push_cnt;
			push_cnt = 0;
			pop_cnt = 0;
		}
	}
}

int main() {
	int a = 0;
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

	BFS(a);

	for (int i = 0; i < a; i++) {
		if (x[i] == 0) no_ripe_flag = -1;
	}

	if (no_ripe_flag == -1)	cout << no_ripe_flag;
	else					cout << day_cnt;


	return 0;
}