#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 40001
#define LMAX 17 // 16 + 1

using namespace std;

int N; //2 <= N <= 40000
int M; //1 <= M <= 10000
int root = 1;

typedef struct {
	int node;
	int cost;
}nc;
vector<vector<nc>> tree(MAX);
bool ch[MAX];
int ancestor[MAX][LMAX];
int level[MAX];
int length[MAX];

int  MakeLength(int a, int b, int m) {
	return length[a] + length[b] - (2 * length[m]);
}

int Lca(int a, int b) {
	if (level[a] < level[b]) {
		swap(a, b);
	}

	if (level[a] != level[b]) {
		for (int i = LMAX - 1; i >= 0; i--) {
			int m = ancestor[a][i];

			if (level[m] >= level[b]) {
				a = m;
			}
		}
	}

	int r = a;

	if (a != b) {
		for (int i = LMAX - 1; i >= 0; i--) {
			if (ancestor[a][i] != ancestor[b][i]) {
				a = ancestor[a][i];
				b = ancestor[b][i];
			}

			r = ancestor[a][i];
		}
	}

	return r;
}

void SetTree(int v, int pre_v, int c, int depth) {
	if (ch[v] == false) {
		ch[v] = true;

		length[v] = c;
		level[v] = depth;
		ancestor[v][0] = pre_v;
		for (int i = 1; i < LMAX; i++) {
			ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
		}

		for (int i = 0; i < tree[v].size(); i++) {
			int next_v = tree[v][i].node;
			int next_c = c + tree[v][i].cost;

			SetTree(next_v, v, next_c, depth + 1);
		}
	}
}

void Input() {
	cin >> N;

	for (int i = 1; i < N; i++) {
		int m, s, c = 0;
		cin >> m >> s >> c;

		tree[m].push_back({ s, c });
		tree[s].push_back({ m, c });
	}

	SetTree(root, 0, 0, 1);

	cin >> M;

	for (int i = 1; i <= M; i++) {
		int a, b = 0;
		cin >> a >> b;

		cout << MakeLength(a, b, Lca(a, b)) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	return 0;
}