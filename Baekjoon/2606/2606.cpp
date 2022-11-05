#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int M;

int result;

int ch[101];
queue<int> Q;
vector<int> network[101];

void Virus() {
	while (!Q.empty()) {
		int now_c = Q.front();
		Q.pop();

		for (int i = 0; i < network[now_c].size(); i++) {
			int next_c = network[now_c][i];
			
			if (ch[next_c] == 0) {
				ch[next_c] = 1;

				Q.push(next_c);
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
		int c1 = 0;
		int c2 = 0;
		cin >> c1 >> c2;

		network[c1].push_back(c2);
		network[c2].push_back(c1);
	}

	ch[1] = 1;
	Q.push(1);
	Virus();

	for (int i = 2; i <= N; i++) {
		if (ch[i] == 1) {
			result++;
		}
	}

	cout << result;

	return 0;
}