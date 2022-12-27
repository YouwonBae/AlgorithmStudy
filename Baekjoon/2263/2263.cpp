#include <iostream>
#include <vector>

using namespace std;

int N; // 1 <= N <= 100000
int root;

int tree[100001];
int inorder[100001];
int postorder[100001];

void Input() {
	cin >> N;
	for (int i = 0; i <= N - 1; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i <= N - 1; i++) {
		cin >> postorder[i];
	}

	root = postorder[N - 1];
}

void SetTree(int n, int instart, int inend, int poststart, int postend) {
	cout << n << " ";

	if (instart == inend || poststart == postend) {
		return;
	}
	else {
		for (int i = instart; i <= inend; i++) {
			if (inorder[i] == n) {
				// left
				int post_end = poststart + (i - instart) - 1;
				if (instart <= i - 1) {
					SetTree(postorder[post_end], instart, i - 1, poststart, post_end);
				}

				// right
				int post_start = poststart + (i - instart);
				if (i + 1 <= inend) {
					SetTree(postorder[postend - 1], i + 1, inend, post_start, postend - 1);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	SetTree(root, 0, N - 1, 0, N - 1);

	return 0;
}