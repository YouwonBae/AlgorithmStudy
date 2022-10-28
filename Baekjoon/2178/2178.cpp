#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string numbers;

vector<int> map[1000000];
queue<int> Q; 

int dis[1000000];
int ch[1000000];
int x[1000000] = { 0, };

void BFS(int v) {
	int x = 0;

	Q.push(v);

	while (!Q.empty()) {

		x = Q.front();
		Q.pop();

		for (int i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {

				ch[map[x][i]] = 1;

				Q.push(map[x][i]);

				dis[map[x][i]] = dis[x] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	int a = 0;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		cin >> numbers;

		for (int j = 0; j < M; j++) {

			x[a] = stoi(numbers.substr(j, 1));
			a++;

		}
	}

	for (int i = 0; i < a; i++) {

		if (i - M >= 0 || i + M < N * M) {
			if (i - M < 0) {
				if (x[i + M] == 1) {
					map[i].push_back(i + M);
				}
			}
			else if (i + M > N * M) {
				if (x[i - M] == 1) {
					map[i].push_back(i - M);
				}
			}
			else {
				if (x[i + M] == 1) {
					map[i].push_back(i + M);
				}
				if (x[i - M] == 1) {
					map[i].push_back(i - M);
				}
			}
		}

		if (i % M != 0 || i % M != M - 1) {
			if (i % M == 0) {
				if (x[i + 1] == 1) {
					map[i].push_back(i + 1);
				}
			}
			else if (i % M == M - 1) {
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

	ch[0] = 1;
	dis[0] = 1;
	BFS(0);

	if (N * M - 1 >= 0) {
		cout << dis[N * M - 1];
	}
	cout << "\n";

	return 0;
}