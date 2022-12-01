#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 50

using namespace std;

int N; // 4 <= N <= 50
int M; // 0 <= M <= 2500
int K; // 1 <= K <= 1000

int result = 0;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

typedef struct {
	int r;
	int c;
	int m; // 질량
	int s; // 속력
	int d; // 방향
}bs;
vector<bs> fireball;
vector<bs> new_fireball;
queue<bs> Q;

int SortByRC(bs a, bs b) {
	if (a.r == b.r) {
		return a.c < b.c;
	}
	else {
		return a.r < b.r;
	}
}

int MakeIndex(int now_x, int next_x, int v) {
	if (next_x >= N) {
		int r = v + now_x;

		r = r % N;

		next_x = r;
	}
	else if (next_x < 0) {
		int r = v;

		r = r % N;

		next_x = now_x + N - r;
		next_x %= N;
	}

	return next_x;
}

void CloneBall() {
	if (Q.size() >= 2) {
		int b_cnt = 0;
		int r = Q.front().r;
		int c = Q.front().c;
		int m = 0;
		int s = 0;
		int odd_flag = 0;
		int even_flag = 0;

		while (!Q.empty()) {
			m += Q.front().m;
			s += Q.front().s;
			b_cnt++;

			if (Q.front().d % 2 == 0) {
				even_flag = 1;
			}
			else {
				odd_flag = 1;
			}

			Q.pop();
		}

		m = m / 5;
		s = s / b_cnt;

		if (m > 0) {
			if (even_flag == 1 && odd_flag == 1) { // 1, 3, 5, 7
				fireball.push_back({ r, c, m, s, 1 });
				fireball.push_back({ r, c, m, s, 3 });
				fireball.push_back({ r, c, m, s, 5 });
				fireball.push_back({ r, c, m, s, 7 });
			}
			else { // 0, 2, 4, 6
				fireball.push_back({ r, c, m, s, 0 });
				fireball.push_back({ r, c, m, s, 2 });
				fireball.push_back({ r, c, m, s, 4 });
				fireball.push_back({ r, c, m, s, 6 });
			}
		}
	}
	else {
		if (!Q.empty()) {
			fireball.push_back({ Q.front().r, Q.front().c, Q.front().m, Q.front().s, Q.front().d });
			Q.pop();
		}
	}
}

void CheckBall() {
	int r = new_fireball.front().r;
	int c = new_fireball.front().c;

	while (!new_fireball.empty()) {
		if (!(new_fireball.front().r == r && new_fireball.front().c == c)) {
			CloneBall();
		}

		Q.push({ new_fireball.front().r, new_fireball.front().c, new_fireball.front().m, new_fireball.front().s, new_fireball.front().d });

		r = new_fireball.front().r;
		c = new_fireball.front().c;

		new_fireball.erase(new_fireball.begin());
	}

	CloneBall();
}

void MoveBall() {
	for (int i = 0; i < fireball.size(); i++) {
		int now_x = fireball[i].c;
		int now_y = fireball[i].r;
		int mass = fireball[i].m;
		int s = fireball[i].s;
		int dir = fireball[i].d;

		int next_x = now_x + dx[dir] * s;
		int next_y = now_y + dy[dir] * s;

		next_x = MakeIndex(now_x, next_x, s);
		next_y = MakeIndex(now_y, next_y, s);

		new_fireball.push_back({ next_y, next_x, mass, s, dir });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;

	if (M != 0) {
		for (int i = 0; i < M; i++) {
			int r, c, m, s, d = 0;
			cin >> r >> c >> m >> s >> d;

			fireball.push_back({ r - 1, c - 1, m, s, d });
		}

		while (K--) {
			MoveBall();

			sort(new_fireball.begin(), new_fireball.end(), SortByRC);

			fireball.clear();
			CheckBall();
		}

		for (int i = 0; i < fireball.size(); i++) {
			result += fireball[i].m;
		}

		cout << result;
	}
	else {
		cout << "0";
	}

	return 0;
}