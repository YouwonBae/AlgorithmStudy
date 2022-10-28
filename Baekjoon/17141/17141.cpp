#include <iostream>
#include <queue>
#include <vector>

#define MAX 51

using namespace std;

int N;
int M;

int case_cnt;

int virus_spot;
int virus_spot_cnt;

int result;

int raw_lab[MAX][MAX];
int test_lab[MAX][MAX];
int check[MAX][MAX];
int spread_time[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;
queue<xy> Q;

vector<int> host_list[100000];

void BFS() {
	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && test_lab[next_y][next_x] != 1 && check[next_y][next_x] == 0) {
				check[next_y][next_x] = 1;
				test_lab[next_y][next_x] = 4;
				spread_time[next_y][next_x] = spread_time[now_y][now_x] + 1;

				Q.push({ next_x, next_y });
			}
		}
	}
}

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
	if (r == 0)
	{
		for (int i = 0; i < comb.size(); i++) {
			host_list[case_cnt].push_back(comb[i]);
		}
		case_cnt++;
	}
	else if (depth == arr.size())
	{
		return;
	}
	else
	{
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		Combination(arr, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int make_result = 0;

	// make raw laboratory map
	cin >> N;
	cin >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> raw_lab[y][x];
			if (raw_lab[y][x] == 2) {
				virus_spot++;
			}
		}
	}

	// virus host spot combination
	vector<int> v;
	for (int i = 0; i < virus_spot; i++) {
		v.push_back(i);
	}
	vector<int> team_comb(M);
	Combination(v, team_comb, M, 0, 0);

	result = N * N;

	for (int i = 0; i < case_cnt; i++) {

		int max_spread_time = 0;
		int no_spread = 0;

		// make test laboratory map
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (raw_lab[y][x] == 2) {
					for (int c = 0; c < host_list[i].size(); c++) {
						if (host_list[i][c] == virus_spot_cnt) {
							test_lab[y][x] = 3;

							check[y][x] = 1;
							Q.push({ x, y });
						}
					}

					virus_spot_cnt++;
				}
				else if (raw_lab[y][x] == 1) {
					test_lab[y][x] = 1;
				}
				else {
					test_lab[y][x] = 0;
				}
			}
		}

		// virus BFS
		BFS();

		// make max spread time
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (test_lab[y][x] == 0) {
					no_spread = 1;
				}

				if (max_spread_time < spread_time[y][x]) {
					max_spread_time = spread_time[y][x];
				}
			}
		}

		// make result
		if (no_spread != 1) {
			if (max_spread_time < result) {
				result = max_spread_time;
			}

			make_result = 1;
		}

		// initialize
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				test_lab[y][x] = 0;
				check[y][x] = 0;
				spread_time[y][x] = 0;
			}
		}
		virus_spot_cnt = 0;
	}

	if (make_result == 1) {
		cout << result;
	}
	else {
		cout << "-1";
	}

	return 0;
}