#include <iostream>
#include <queue>

using namespace std;

int F; // 1 <= F <= 1000000
int S; // 1 <= S <= 1000000
int G; // 1 <= G <= 1000000
int U; // 0 <= U <= 1000000
int D; // 0 <= D <= 1000000

typedef struct {
	int s;
	int b;
}sb;

queue<sb> Q;
int check[1000001];

int result;

void BFS(int *ud) {
	while (!Q.empty()) {
		int now_s = Q.front().s;
		int now_b = Q.front().b;
		Q.pop();

		for (int i = 0; i < 2; i++) {
			int next_s = now_s + ud[i];

			if (next_s >= 1 && next_s <= F && check[next_s] == 0) {
				int next_b = now_b + 1;

				check[next_s] = 1;

				if (next_s == G) {
					result = next_b;

					return;
				}

				Q.push({ next_s, next_b });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> F >> S >> G >> U >> D;

	int ud[2] = { U, -1 * D };

	if (S == G) {
		cout << "0";
	}
	else {
		check[S] = 1;
		Q.push({ S, 0 });
		BFS(ud);

		if (result == 0) {
			cout << "use the stairs";
		}
		else {
			cout << result;
		}
	}

	return 0;
}