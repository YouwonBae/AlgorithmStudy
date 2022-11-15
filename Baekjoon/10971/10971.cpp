#include <iostream>
#include <cstring>
#include <vector>

#define MAX 10

using namespace std;

int N; // 1 <= N <= 10

int start_c;
int visit_cnt;
int result = 10000000;

int check[MAX];
vector<int> t_cost[MAX];

int GoHome(int now_city) {
	if (t_cost[now_city][start_c] == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

void DFS(int now_city, int now_cost) {
	if (visit_cnt == N) {
		if (GoHome(now_city)) {
			result = min(result, now_cost + t_cost[now_city][start_c]);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			int next_city = i;
			int next_cost = t_cost[now_city][i];

			if (check[next_city] == 0 && next_cost != 0) {
				check[next_city] = 1;
				visit_cnt++;

				DFS(next_city, now_cost + next_cost);
				check[next_city] = 0;
				visit_cnt--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int c;
			cin >> c;

			t_cost[i].push_back(c);
		}
	}

	for (int i = 0; i < N; i++) {
		start_c = i;

		check[start_c] = 1;
		visit_cnt++;

		DFS(start_c, 0);

		check[start_c] = 0;
		visit_cnt--;
	}

	cout << result;

	return 0;
}