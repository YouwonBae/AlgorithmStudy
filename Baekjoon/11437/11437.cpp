#include <iostream>
#include <vector>

#define MAX 50001

using namespace std;

int N; // 2 <= N <= 50000
int M; // 1 <= M <= 10000

vector<int> tree[MAX];
int ch[MAX];
int parent[MAX];
int level[MAX];

void MakeTree(int n, int p_n, int depth) {
	if (ch[n] == false) {
		ch[n] = true;

		level[n] = depth;
		parent[n] = p_n;

		for (int i = 0; i < tree[n].size(); i++) {
			int next_n = tree[n][i];
			int next_d = depth + 1;

			MakeTree(next_n, n, next_d);
		}
	}
}

int Lcd(int a, int b) {
	if (level[a] < level[b]) {
		swap(a, b);
	}

	while (level[a] != level[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void Input() {
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int n_1, n_2 = 0;
		cin >> n_1 >> n_2;

		tree[n_1].push_back(n_2);
		tree[n_2].push_back(n_1);
	}

	MakeTree(1, 0, 1);

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