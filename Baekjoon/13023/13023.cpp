#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N; // 5 <= N <= 2000
int M; // 1 <= M <= 2000

int correct;

vector<int> people[2001];
int ch[2001];

void DFS(int now_p, int depth) {
	if (depth == 5) {
		correct = 1;
		return;
	}
	else {
		for (int i = 0; i < people[now_p].size(); i++) {
			int next_p = people[now_p][i];

			if (ch[next_p] == 0) {
				ch[next_p] = 1;

				DFS(next_p, depth + 1);
				ch[next_p] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b = 0;
		cin >> a >> b;

		people[a].push_back(b);
		people[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		ch[i] = 1;
		DFS(i, 1);

		if (correct == 1) {
			break;
		}

		memset(ch, 0, sizeof(ch));
	}

	cout << correct;

	return 0;
}