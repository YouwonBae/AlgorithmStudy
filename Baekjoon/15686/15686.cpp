#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; // 2 ¡Â N ¡Â 50
int M; // 1 ¡Â M ¡Â 13

int city[50][50];
int test_city[50][50];
int check[50][50];
int dist[50][50];

int kyochon_cnt;

int result;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;

vector<int> kyochon;

void ChickenDist() {
	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && check[next_y][next_x] == 0 && test_city[next_y][next_x] != 2) {

				check[next_y][next_x] = 1;

				dist[next_y][next_x] = dist[now_y][now_x] + 1;

				Q.push({ next_x , next_y });
			}
		}
	}
}

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth) {
	if (r == 0) {
		int chicken_dist = 0;

		for (int i = 0; i < comb.size(); i++) {
			int c = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (city[y][x] == 2) {
						if (comb[i] == c) {
							test_city[y][x] = 2;
							Q.push({ x, y });
						}
						c++;
					}
					else if (city[y][x] == 1) {
						test_city[y][x] = 1;
					}
					else {
						test_city[y][x] = 0;
					}
				}
			}
		}

		ChickenDist();

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (test_city[y][x] == 1) {
					chicken_dist += dist[y][x];
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				test_city[y][x] = 0;
				dist[y][x] = 0;
				check[y][x] = 0;
			}
		}

		if (chicken_dist < result) {
			result = chicken_dist;
		}
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		Combination(arr, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	result = 1000000;

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> city[y][x];
			if (city[y][x] == 2) {
				kyochon.push_back(kyochon_cnt);
				kyochon_cnt++;
			}
		}
	}

	vector<int> comb(M);
	Combination(kyochon, comb, M, 0, 0);

	cout << result << "\n";

	return 0;
}