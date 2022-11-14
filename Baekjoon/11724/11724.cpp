#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 1 <= N <= 1000
int M; // 0 <= M <= N¡¿(N-1)/2

int cc_cnt;

vector<int> line[1001];
queue<int> Q;
int ch[1001];

void BFS() {
	while(!Q.empty()) {
		int now_v = Q.front();
		Q.pop();

		for (int i = 0; i < line[now_v].size(); i++) {
			int next_v = line[now_v][i];

			if (ch[next_v] == 0) {
				ch[next_v] = 1;

				Q.push(next_v);
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v = 0;
		cin >> u >> v;
		line[u].push_back(v);
		line[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (ch[i] == 0) {
			Q.push(i);
			ch[i] = 1;

			cc_cnt++;

			BFS();
		}
	}

	cout << cc_cnt;

	return 0;
}