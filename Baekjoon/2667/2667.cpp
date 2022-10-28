#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string numbers;

vector<int> map[1000];

int ch[1000];
int x[1000];
int home_cnt[1000] = {0, };

bool cmp(int a, int b)
{
	return a < b;
}

void DFS(int v, int cnt) {
	if (ch[v] == 1) {
		home_cnt[cnt]++;
	}
	for (int i = 0; i < map[v].size(); i++) {
		if (ch[map[v][i]] == 0) {
			ch[map[v][i]] = 1;
			DFS(map[v][i], cnt);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int a = 0;
	int village_cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numbers;
		for (int j = 0; j < N; j++) {
			x[a] = stoi(numbers.substr(j, 1));
			a++;
		}
	}

	for (int i = 0; i < N*N; i++) {

		if (i - N >= 0 || i + N < N * N) {
			if (i - N < 0) {
				if (x[i + N] == 1) {
					map[i].push_back(i + N);
				}
			}
			else if (i + N > N * N) {
				if (x[i - N] == 1) {
					map[i].push_back(i - N);
				}
			}
			else {
				if (x[i + N] == 1) {
					map[i].push_back(i + N);
				}
				if (x[i - N] == 1) {
					map[i].push_back(i - N);
				}
			}
		}

		if (i % N != 0 || i % N != N - 1) {
			if (i % N == 0) {
				if (x[i + 1] == 1) {
					map[i].push_back(i + 1);
				}
			}
			else if (i % N == N - 1) {
				if (x[i - 1] == 1) {
					map[i].push_back(i - 1);
				}
			}
			else {
				if (x[i - 1] == 1) {
					map[i].push_back(i - 1);
				}
				if (x[i + 1] == 1) {
					map[i].push_back(i + 1);
				}
			}
		}
	}

	for (int i = 0; i < N * N; i++) {
		if (x[i] == 1 && ch[i] == 0) {
			village_cnt ++;
			ch[i] = 1;
			DFS(i, village_cnt - 1);
		}
	}

	sort(home_cnt, home_cnt + village_cnt, cmp);

	cout << village_cnt << "\n";
	for (int i = 0; i < village_cnt; i++) {
		cout << home_cnt[i] << "\n";
	}

	return 0;
}