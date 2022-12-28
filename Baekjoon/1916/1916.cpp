#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1001
#define C_MAX 100000000

using namespace std;

int N; // 1 <= N <= 1000
int M; // 1 <= M <= 100000

int cost_table[MAX];

typedef struct {
	int city;
	int cost;
}cc;
vector<cc> road[MAX];

struct pq_compare{
	bool operator () (const cc& a, const cc& b) const {
		return a.cost > b.cost; // 오름차순
	}
};
priority_queue<cc, vector<cc>, pq_compare> Q;

int SortByCost(cc a, cc b) {
	if (a.cost == b.cost) {
		return a.city < b.city;
	}
	else {
		return a.cost < b.cost;
	}
}

void Dijkstra() {
	while (!Q.empty()) {
		int now_city = Q.top().city;
		int now_cost = Q.top().cost;
		Q.pop();

		for (int i = 0; i < road[now_city].size(); i++) {
			int next_city = road[now_city][i].city;
			int next_cost = road[now_city][i].cost;

			if (now_cost + next_cost < cost_table[next_city]) {
				cost_table[next_city] = now_cost + next_cost;

				Q.push({ next_city, cost_table[next_city] });
			}
		}
	}
}

void Output(int s, int e) {
	Q.push({ s, 0 });
	Dijkstra();

	cout << cost_table[e];
}

void Input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int c_1, c_2, cost;
		cin >> c_1 >> c_2 >> cost;

		road[c_1].push_back({ c_2, cost });
	}

	for (int i = 1; i <= N; i++) {
		cost_table[i] = C_MAX;
		sort(road[i].begin(), road[i].end(), SortByCost);
	}

	int s, e;
	cin >> s >> e;

	Output(s, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	return 0;
}