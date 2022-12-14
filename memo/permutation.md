# permutation


## 순열
```
#include <iostream>

#define MAX 12

using namespace std;

int N; // 2 ≤ N ≤ 11
int R;

int operators[MAX];
int ch[MAX];
int picked_list[MAX];

void Permutation(int depth) {
	if (depth >= R) {
		for (int i = 0; i < R; i++) {
			cout << picked_list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < R; i++) {
			if (ch[i] == 0) {
				ch[i] = 1;
				picked_list[depth] = operators[i];
				Permutation(depth + 1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> R;

	for (int i = 0; i < R; i++) {
		cin >> operators[i];
	}

	Permutation(0);

	return 0;
}
```