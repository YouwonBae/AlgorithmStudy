#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define LMAX 18 //(int)floor(log2(100000)) + 2;

using namespace std;

int N; // 2 <= N <= 100000
int M; // 1 <= M <= 100000
int root = 1;
int max_level = LMAX - 1;

vector<int> tree[MAX];
int ch[MAX];
int parent[MAX][LMAX];
int level[MAX];

void MakeTree(int n, int p_n, int depth) {
	if (ch[n] == false) {
		ch[n] = true;

		level[n] = depth;
		parent[n][0] = p_n;

		for (int i = 1; i <= max_level; i++) {
			parent[n][i] = parent[parent[n][i - 1]][i - 1];
		}

		for (int i = 0; i < tree[n].size(); i++) {
			int next_n = tree[n][i];
			int next_d = depth + 1;

			MakeTree(next_n, n, next_d);
		}
	}
}

int Lcd(int a, int b) {
	int r = 0;

	if (level[a] < level[b]){
		swap(a, b);
	}

	if (level[a] != level[b]) {
		for (int i = max_level; i >= 0; i--) {
			int p = parent[a][i];
			if (level[p] >= level[b]) {
				a = p;
			}
		}
	}

	if (a != b) {
		for (int i = max_level; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			r = parent[a][i];
		}
	}
	else {
		r = a;
	}

	return r;
}

void Input() {
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int n_1, n_2 = 0;
		cin >> n_1 >> n_2;

		tree[n_1].push_back(n_2);
		tree[n_2].push_back(n_1);
	}

	MakeTree(root, 0, 1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b = 0;
		cin >> a >> b;

		cout << Lcd(a, b) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	return 0;
}
