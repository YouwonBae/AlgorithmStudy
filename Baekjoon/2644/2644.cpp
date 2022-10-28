#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> map[101];
int ch[101] = {0, };

int n;
int a, b;
int m;

int result;

void DFS(int v, int depth) {

	if (v == b) {
		result = depth;
	}

	ch[v] = 1;

	for (int i = 0; i < map[v].size(); i++) {
		if (ch[map[v][i]] == 0) {
			DFS(map[v][i], depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int mother, son;
		cin >> mother >> son;
		map[mother].push_back(son);
		map[son].push_back(mother);
	}

	DFS(a, 0);

	if (result) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}