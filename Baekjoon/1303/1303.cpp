#include <iostream>
#include <queue>
#include <string>

#define MAX 101

using namespace std;

int M;
int N;

int w_power;
int b_power;

int battlefield[MAX][MAX];
int check[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

int BFS(int team) {
	int crowd_count = 0;

	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N && check[next_y][next_x] == 0 && battlefield[next_y][next_x] == team) {
				check[next_y][next_x] = 1;

				crowd_count++;

				Q.push({ next_x , next_y });
			}
		}
	}

	return crowd_count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	for (int n = 0; n < N; n++) {
		string input;
		cin >> input;
		for (int m = 0; m < M; m++) {
			if (input[m] == 'W') {
				battlefield[n][m] = 1;
			}
			else if (input[m] == 'B') {
				battlefield[n][m] = 2;
			}
			else {
				battlefield[n][m] = 0;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			int P = 0;

			if (check[n][m] == 0) {
				check[n][m] = 1;
				P++;
				Q.push({ m, n });
				P += BFS(battlefield[n][m]);

				if (battlefield[n][m] == 1) {
					w_power += P * P;
				}
				else if (battlefield[n][m] == 2) {
					b_power += P * P;
				}
			}
		}
	}

	cout << w_power << " " << b_power;

	return 0;
}