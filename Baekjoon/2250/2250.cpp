#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 10001

using namespace std;

int N; // 1 <= N <= 10000
int root_node;
int push_cnt;
int max_depth;

bool ch[MAX];

typedef struct {
	int left;
	int right;
}lr;
vector<lr> tree[MAX];

typedef struct {
	int node;
	int x;
}nx;
vector<nx> map[MAX];

typedef struct {
	int depth;
	int width;
}dw;
struct prepare {
	bool operator () (const dw& a, const dw& b) const {
		if (a.width == b.width) {
			return a.depth > b.depth;
		}
		else {
			return a.width < b.width;
		}
	}
};
priority_queue<dw, vector<dw>, prepare> Q;

int SortByX(nx a, nx b) {
	return a.x < b.x;
}

void Input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int m, s_l, s_r = 0;
		cin >> m >> s_l >> s_r;
		if (s_l > 0) {
			ch[s_l] = true;
		}
		if (s_r > 0) {
			ch[s_r] = true;
		}
		tree[m].push_back({ s_l, s_r });
	}

	for (int i = 1; i <= N; i++) {
		if (ch[i] == false) {
			root_node = i;
		}
	}

	push_cnt = 1;
}

void Output() {
	cout << Q.top().depth << " " << Q.top().width;
}

void InOrder(int n, int depth) {
	if (n < 0) {
		return;
	}
	else {
		InOrder(tree[n][0].left, depth + 1);
		map[depth].push_back({ n, push_cnt });
		max_depth = max(max_depth, depth);
		push_cnt++;
		InOrder(tree[n][0].right, depth + 1);
	}
}

void FindWidth() {
	for (int i = 1; i <= max_depth; i++) {
		if (!map[i].empty()) {
			sort(map[i].begin(), map[i].end(), SortByX);

			int width = map[i].back().x - map[i].front().x + 1;
			Q.push({ i, width });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	InOrder(root_node, 1);
	FindWidth();
	Output();

	return 0;
}