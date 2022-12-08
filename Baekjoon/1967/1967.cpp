#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

typedef struct {
	int next;
	int cost;
}nc;
vector<nc> line[10001];
vector<nc> length;
bool ch[10001];

int SortByLength(nc a, nc b) {
	return a.cost > b.cost;
}

void DFS(int p, int c) {
	int next_cnt = 0;

	for (int i = 0; i < line[p].size(); i++) {
		int next_p = line[p][i].next;
		int weight = line[p][i].cost;

		if (ch[next_p] == false) {
			next_cnt++;
			ch[next_p] = true;

			DFS(next_p, c + weight);
			ch[next_p] = false;
		}
	}

	if (next_cnt == 0) {
		length.push_back({ p, c });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int p, s, c = 0;

		cin >> p >> s >> c;

		line[p].push_back({ s, c });
		line[s].push_back({ p, c });
	}

	ch[1] = true;
	DFS(1, 0);
	ch[1] = false;

	sort(length.begin(), length.end(), SortByLength);

	int start = length.front().next;
	ch[start] = true;
	length.clear();
	DFS(start, 0);
	ch[start] = false;

	sort(length.begin(), length.end(), SortByLength);

	cout << length.front().cost;

	return 0;
}