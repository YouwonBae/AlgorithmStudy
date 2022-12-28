#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define C_MAX 1000000000

using namespace std;

int N; // 2 <= N <= 800
int E; // 0 <= E <= 200000
int V_1;
int V_2;

int result_1;
int result_2;

int cost_table[801];

typedef struct {
	int node;
	int cost;
}nc;
vector<nc> line[801];

struct pq_compare {
	bool operator () (const nc &a, const nc &b) const {
		return a.cost > b.cost; // 오름차순
	}
};
priority_queue<nc, vector<nc>, pq_compare> Q;

int SortByCost(nc a, nc b) {
	if (a.cost == b.cost) {
		return a.node < b.node;
	}
	else {
		return a.cost < b.cost;
	}
}

void ResetTable() {
	for (int i = 1; i <= N; i++) {
		cost_table[i] = C_MAX;
	}
}

void Input() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c = 0;
		cin >> a >> b >> c;

		line[a].push_back({ b, c });
		line[b].push_back({ a, c });
	}

	for (int i = 1; i <= N; i++) {
		cost_table[i] = C_MAX;
		sort(line[i].begin(), line[i].end(), SortByCost);
	}

	cin >> V_1 >> V_2;
}

int Dijkstra(int s, int e) {
	cost_table[s] = 0;
	Q.push({ s, 0 });

	while (!Q.empty()) {
		int now_n = Q.top().node;
		int now_c = Q.top().cost;
		Q.pop();

		for (int i = 0; i < line[now_n].size(); i++) {
			int next_n = line[now_n][i].node;
			int next_c = line[now_n][i].cost;

			if (now_c + next_c < cost_table[next_n]) {
				cost_table[next_n] = now_c + next_c;
				Q.push({ next_n, cost_table[next_n] });
			}
		}
	}

	if (cost_table[e] == C_MAX) {
		return -1;
	}
	else {
		return cost_table[e];
	}
}

int R_1() {
	int r = 0;

	r = Dijkstra(1, V_1);
	if (r == -1) {
		return r;
	}
	else {
		result_1 += r;
	}
	ResetTable();

	r = Dijkstra(V_1, V_2);
	if (r == -1) {
		return r;
	}
	else {
		result_1 += r;
	}
	ResetTable();

	r = Dijkstra(V_2, N);
	if (r == -1) {
		return r;
	}
	else {
		result_1 += r;
	}
	ResetTable();

	return 1;
}

int R_2() {
	int r = 0;

	r = Dijkstra(1, V_2);
	if (r == -1) {
		return r;
	}
	else {
		result_2 += r;
	}
	ResetTable();

	r = Dijkstra(V_2, V_1);
	if (r == -1) {
		return r;
	}
	else {
		result_2 += r;
	}
	ResetTable();

	r = Dijkstra(V_1, N);
	if (r == -1) {
		return r;
	}
	else {
		result_2 += r;
	}
	ResetTable();

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	if (R_1() == -1) {
		cout << "-1";
	}
	else {
		if (R_2() == -1) {
			cout << "-1";
		}
		else {
			cout << min(result_1, result_2);
		}
	}

	return 0;
}