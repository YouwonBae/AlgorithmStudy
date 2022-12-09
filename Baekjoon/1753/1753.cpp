#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX INT_MAX

using namespace std;

int V; // 1 <= V <= 20000
int E; // 1 <= E <= 300000
int K; // 1 <= K <= 20000

typedef struct {
	int node;
	int dist;
}nd;
vector<nd> line[300001];
bool ch[300001];
int arr[20001];

struct pq_compare {
	bool operator()(const nd& a, const nd& b)const {
		return a.dist > b.dist;
	}
};
priority_queue<nd, vector<nd>, pq_compare> Q;

void Dijkstra(int k) {
	arr[k] = 0;
	Q.push({ k, 0 });

	while (!Q.empty()) {
		int u = Q.top().node;
		int now_dist = Q.top().dist;
		Q.pop();

		if (ch[u] == false) {
			ch[u] = true;
		}

		if (arr[u] >= now_dist) {
			for (int i = 0; i < line[u].size(); i++) {
				int v = line[u][i].node;
				int new_dist = now_dist + line[u][i].dist;

				if (new_dist < arr[v]) { // update
					arr[v] = new_dist;

					Q.push({ v, new_dist });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w = 0;

		cin >> u >> v >> w;

		line[u].push_back({ v, w });
	}

	for (int i = 1; i <= V; i++) {
		arr[i] = MAX;
	}
	
	Dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (ch[i] == false) {
			cout << "INF" << '\n';
		}
		else {
			cout << arr[i] << '\n';
		}
	}

	return 0;
}