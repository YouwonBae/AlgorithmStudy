#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int N; // 2 <= N <= 100000
int root = 1;

vector<vector<int>> line(MAX);
int parent[MAX];
bool ch[MAX];

void Input() {
	cin >> N;

	for (int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}
}

void Output() {
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}

void SetTree(int n, int pre_n) {
	if (ch[n] == false) {
		ch[n] = true;

		parent[n] = pre_n;

		for (int i = 0; i < line[n].size(); i++) {
			int next_n = line[n][i];

			SetTree(next_n, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	SetTree(root, 0);
	Output();

	return 0;
}