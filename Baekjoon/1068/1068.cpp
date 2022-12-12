#include <iostream>
#include <queue>
#include <vector>

#define MAX 61

using namespace std;

int N;
int E;
int leaf_cnt;

queue<int> Q;
vector<int> tree[MAX];
vector<int> blacklist;
int ch[MAX];

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int root = 0;
		cin >> root;

		Q.push(root);
	}

	cin >> E;

	int node_cnt = 0;
	while (!Q.empty()) {
		int root = Q.front();
		Q.pop();

		if (root >= 0) {
			if (node_cnt != E) {
				if (root != E) {
					bool b_list = false;
					for (int i = 0; i < blacklist.size(); i++) {
						if (blacklist[i] == root) {
							b_list = true;
						}
					}

					if (!b_list) {
						tree[root].push_back(node_cnt);
					}
				}
				else {
					blacklist.push_back(node_cnt);
				}
			}
		}
		else {
			tree[60].push_back(node_cnt);
		}

		node_cnt++;
	}
}

void FindLeaf(int m) {
	if (tree[m].empty()) {
		leaf_cnt++;
	}
	else {
		for (int i = 0; i < tree[m].size(); i++) {
			int next_m = tree[m][i];

			if (ch[next_m] == false) {
				ch[next_m] = true;

				FindLeaf(next_m);
			}
		}
	}
}

void CountLeaf() {
	int start_node = tree[60].front();

	if (start_node != E) {
		ch[start_node] = true;
		FindLeaf(start_node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	CountLeaf();

	cout << leaf_cnt;

	return 0;
}