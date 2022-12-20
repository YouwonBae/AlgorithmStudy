#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

int root;

typedef struct {
	int key;
	int left;
	int right;
}lr;
lr tree[MAX];

vector<int> keys;

void Input() {
	int num;
	keys.push_back(1000000);

	while (cin >> num) {
		if (cin.eof()) {
			break;
		}
		else {
			keys.push_back(num);
		}
	}

	root = 1;
}

void SetTree(int depth) {
	tree[depth].key = keys[depth];

	if (depth == keys.size() - 1) {
		return;
	}
	else {

		if (keys[depth] > keys[depth + 1]) {
			tree[depth].left = depth + 1;
		}
		else {
			for (int i = depth; i >= 0; i--) {
				if (keys[depth + 1] < keys[i]) {
					int ch = i + 1;

					while (tree[ch].right != 0) {
						ch = tree[ch].right;
					}

					tree[ch].right = depth + 1;

					break;
				}
			}
		}

		SetTree(depth + 1);
	}
}

void PostOrder(int n) {
	if (n == 0) {
		return;
	}
	else {
		PostOrder(tree[n].left);
		PostOrder(tree[n].right);
		cout << tree[n].key << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	if (keys.size() >= 2) {
		SetTree(root);
		PostOrder(root);
	}

	return 0;
}