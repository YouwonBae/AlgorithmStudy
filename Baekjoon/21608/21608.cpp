#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 21

using namespace std;

int N; // 3 <= N <= 20

int max_chair;
int max_friend;

int put_x;
int put_y;

int school[MAX][MAX];
int check[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;
queue<xy> Q;
vector<int> student[MAX * MAX];

int Satisfaction() {
	int score = 0;

	for (int y = N; y >= 1; y--) {
		for (int x = N; x >= 1; x--) {
			int now_x = x;
			int now_y = y;
			int match = 0;

			check[now_y][now_x] = 1;

			for (int i = 0; i < 4; i++) {
				int next_x = now_x + dx[i];
				int next_y = now_y + dy[i];

				if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
					int num = school[now_y][now_x];
					for (int j = 0; j < student[num].size(); j++) {
						if (student[num][j] == school[next_y][next_x]) {
							match++;
						}
					}
				}
			}

			if (match == 1) {
				score += 1;
			}
			else if (match == 2) {
				score += 10;
			}
			else if (match == 3) {
				score += 100;
			}
			else if (match == 4) {
				score += 1000;
			}
		}
	}

	return score;
}

void ChoiseChair(int num) {
	max_chair = 0;
	max_friend = 0;

	for (int y = N; y >= 1; y--) {
		for (int x = N; x >= 1; x--) {
			int now_x = x;
			int now_y = y;
			int chair_cnt = 0;
			int friend_cnt = 0;

			if (school[now_y][now_x] == 0) {
				for (int i = 0; i < 4; i++) {
					int next_x = now_x + dx[i];
					int next_y = now_y + dy[i];

					if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
						if (school[next_y][next_x] == 0) {
							chair_cnt++;
						}
						else {
							for (int j = 0; j < student[num].size(); j++) {
								if (school[next_y][next_x] == student[num][j]) {
									friend_cnt++;
								}
							}
						}
					}
				}

				if (max_friend < friend_cnt) {
					max_friend = friend_cnt;

					put_x = now_x;
					put_y = now_y;

					max_chair = chair_cnt;
				}
				else if (max_friend == friend_cnt) {
					if (max_chair <= chair_cnt) {
						max_chair = chair_cnt;

						put_x = now_x;
						put_y = now_y;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N * N; i++) {
		int s = 0;
		cin >> s;
		for (int j = 0; j < 4; j++) {
			int m = 0;
			cin >> m;
			student[s].push_back(m);
		}

		Q.push({ 1, 1 });
		ChoiseChair(s);
		school[put_y][put_x] = s;

		memset(check, 0, sizeof(check));
	}

	Q.push({ 1, 1 });
	cout << Satisfaction() << "\n";

	return 0;
}