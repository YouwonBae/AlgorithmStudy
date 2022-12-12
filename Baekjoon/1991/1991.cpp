#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	char left;
	char right;
}lr;
vector<lr> tree(26);

void Postorder(int m) {
	if (m < 0) {
		return;
	}
	else {
		Postorder(tree[m].left);
		Postorder(tree[m].right);
		cout << (char)(m + 65);
	}
}

void Inorder(int m) {
	if (m < 0) {
		return;
	}
	else {
		Inorder(tree[m].left);
		cout << (char)(m + 65);
		Inorder(tree[m].right);
	}
}

void Preorder(int m) {
	if (m < 0) {
		return;
	}
	else {
		cout << (char)(m + 65);
		Preorder(tree[m].left);
		Preorder(tree[m].right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; // 1 <= N <= 26

	cin >> N;

	for (int i = 1; i <= N; i++) {
		char m, sl, sr;
		cin >> m >> sl >> sr;

		int root = (int)m - 65;

		tree[root].left = (int)sl - 65;
		tree[root].right = (int)sr - 65;
	}

	Preorder(0);
	cout << "\n";
	Inorder(0);
	cout << "\n";
	Postorder(0);
	cout << "\n";

	return 0;
}