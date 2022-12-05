#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N; // 2 <= N <= 10
int H; //1 <= H <= 30
int M;

int match;

int ladder[32][11];

int go_check[32][11];
int original_ch[32][11];
int add_ch[32][11];

int GoLadder(int h, int n) {
	if (h > H) {
		return n;
	}
	else {
		int L = ladder[h][n];

		if (L != 0 && !go_check[h][n + L]) {
			int r = 0;
			go_check[h][n] = 1;

			r = GoLadder(h, n + L);
			go_check[h][n] = 0;
			
			return r;
		}
		else {
			return GoLadder(h + 1, n);
		}
	}
}

bool IoCheck() {
	for (int i = 1; i <= N; i++) {
		if (GoLadder(1, i) != i) {
			return 0;
		}
	}
	return 1;
}

void AddLadder(int pre_h, int pre_n, int length, int depth) {
	if (match) {
		return;
	}
	else {
		if (depth == length) {
			if (IoCheck()) {
				match = 1;
			}
		}
		else {
			for (int h = pre_h; h <= H; h++) {
				if (h == pre_h) {
					for (int n = pre_n; n < N; n++) {
						if (original_ch[h][n] == 0 && add_ch[h][n] == 0) {
							add_ch[h][n] = 1;
							add_ch[h][n + 1] = 1;
							if (n > 1) {
								add_ch[h][n - 1] = 1;
							}

							ladder[h][n] = 1;
							ladder[h][n + 1] = -1;

							AddLadder(h, n, length, depth + 1);
							add_ch[h][n] = 0;
							add_ch[h][n + 1] = 0;
							if (n > 1) {
								add_ch[h][n - 1] = 0;
							}

							ladder[h][n] = 0;
							ladder[h][n + 1] = 0;
						}
					}
				}
				else {
					for (int n = 1; n < N; n++) {
						if (original_ch[h][n] == 0 && add_ch[h][n] == 0) {
							add_ch[h][n] = 1;
							add_ch[h][n + 1] = 1;
							if (n > 1) {
								add_ch[h][n - 1] = 1;
							}

							ladder[h][n] = 1;
							ladder[h][n + 1] = -1;

							AddLadder(h, n, length, depth + 1);
							add_ch[h][n] = 0;
							add_ch[h][n + 1] = 0;
							if (n > 1) {
								add_ch[h][n - 1] = 0;
							}

							ladder[h][n] = 0;
							ladder[h][n + 1] = 0;
						}
					}
				}
			}
		}
	}
}

int Operate() {
	for (int i = 0; i <= 3; i++) {
		AddLadder(1, 1, i, 0);
		if (match) {
			return i;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b = 0;

		cin >> a >> b;

		ladder[a][b] = 1;
		ladder[a][b + 1] = -1;

		original_ch[a][b] = 1;
		original_ch[a][b + 1] = 1;
		if (b > 1) {
			original_ch[a][b - 1] = 1;
		}
	}

	cout << Operate();

	return 0;
}