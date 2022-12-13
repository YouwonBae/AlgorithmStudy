#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int V; // 2 <= V <= 100000

typedef struct {
	int node;
	int cost;
}nc;
vector<nc> tree[100001];
nc max_length;
bool ch[100001];

void Input() {
	cin >> V;

	for (int i = 1; i <= V; i++) {
		int v = 0;
		cin >> v;

		while (1) {
			int next_v = 0;
			int cost = 0;

			cin >> next_v;
			if (next_v == -1) {
				break;
			}

			cin >> cost;
			if (cost == -1) {
				break;
			}

			tree[v].push_back({ next_v , cost });
		}
	}
}

void Output() {
	cout << max_length.cost;
}

void FindLength(int n, int c) {
	bool none_n = true;

	for (int i = 0; i < tree[n].size(); i++) {
		int next_n = tree[n][i].node;
		int next_c = tree[n][i].cost;

		if (ch[next_n] == false) {
			ch[next_n] = true;
			none_n = false;
			FindLength(next_n, c + next_c);
		}
	}

	if (none_n) {
		if (max_length.cost < c) {
			max_length.cost = c;
			max_length.node = n;
		}
	}
}

void Operate() {
	int start_node = 1;
	ch[start_node] = true;
	FindLength(start_node, 0);
	memset(ch, 0, sizeof(ch));

	start_node = max_length.node;
	max_length.node = 0;
	max_length.cost = 0;
	ch[start_node] = true;
	FindLength(start_node, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Operate();
	Output();

	return 0;
}