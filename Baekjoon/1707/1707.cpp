#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T; // 2 <= T <= 5
int V; // 1 <= V <= 20000
int E; // 1 <= E <= 200000

int nobi_flag;
int result;

int check[20001];
int color[20001];
vector<int> line[20001];

queue<int> Q;

void BFS() {
	while (!Q.empty()) {
		int now_v = Q.front();
		Q.pop();

		for (int i = 0; i < line[now_v].size(); i++) {
			int next_v = line[now_v][i];

			if (check[next_v] == 0) {
				check[next_v] = 1;

				if (color[now_v] == 0) {
					color[next_v] = 1;
				}
				else {
					color[next_v] = 0;
				}

				Q.push(next_v);
			}
			else {
				if (color[now_v] == color[next_v]) {
					nobi_flag = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> V >> E;

		for(int i = 0; i < E; i++) {
			int a, b = 0;
			cin >> a >> b;

			line[a].push_back(b);
			line[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				color[i] = 0;
				Q.push(i);
				BFS();
			}
		}

		if (nobi_flag == 1) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}

		nobi_flag = 0;
		memset(color, 0, sizeof(color));
		memset(check, 0, sizeof(check));
		for (int i = 1; i <= V; i++) {
			line[i].clear();
		}
	}

	return 0;
}