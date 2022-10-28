#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[1000000];
vector<int> BFS_map[1000000];
queue<int> Q;

int N = 0;
int ch[1000000];
int BFS_ch[1000000];

bool cmp(int a, int b)
{
	return a < b;
}

void DFS(int v){

	if (ch[v] == 1) {
		cout << v;
	}

	for (int i = 0; i < map[v].size(); i++) {
		if (ch[map[v][i]] == 0) {
			ch[map[v][i]] = 1;
			cout << " ";
			DFS(map[v][i]);
		}
	}
}

void BFS(int v) {
	int x = 0;

	Q.push(v);

	while (!Q.empty()) {
		x = Q.front();
		cout << x;
		cout << " ";
		Q.pop();

		for (int i = 0; i < BFS_map[x].size(); i++) {
			if (BFS_ch[BFS_map[x][i]] == 0) {

				BFS_ch[BFS_map[x][i]] = 1;

				Q.push(BFS_map[x][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int M = 0, V = 0;
	int a = 0;
	int b = 0;

	cin >> N;
	cin >> M;
	cin >> V;

	for (int i = 1; i <= M; i++) {
		cin >> a;
		cin >> b;
		map[a].push_back(b);
		map[b].push_back(a);
		BFS_map[a].push_back(b);
		BFS_map[b].push_back(a);
	}


	for (int i = 0; i < M; i++) {
		sort(map[i].begin(), map[i].end(), cmp);
		sort(BFS_map[i].begin(), BFS_map[i].end(), cmp);
	}

	ch[V] = 1;
	DFS(V);
	cout << "\n";

	BFS_ch[V] = 1;
	BFS(V);
	cout << "\n";

	return 0;
} 