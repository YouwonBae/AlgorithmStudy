#include <iostream>

#define MAX 51

using namespace std;

int N; // 2 <= N <= 50
int M; // 1 <= M <= 100

typedef struct {
	int next;
	int now;
}nn;
nn A[MAX][MAX]; // 0 <= A <= 100
nn C[MAX][MAX]; // 0 <= C <= 100

int d[101];
int s[101];

int result;

int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void MakeCloud() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (C[r][c].next != 1) {
				if (A[r][c].now >= 2) {
					C[r][c].now = 1;
					A[r][c].now -= 2;
				}
			}
			else {
				C[r][c].next = 0;
			}
		}
	}
}

void WaterMagic() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {

			if (C[r][c].next == 1) {
				int bucket_cnt = 0;

				for (int i = 2; i <= 8; i += 2) {
					int next_x = c + dx[i];
					int next_y = r + dy[i];

					if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N && A[next_y][next_x].now >= 1) {
						bucket_cnt++;
					}
				}

				A[r][c].next = A[r][c].now +  bucket_cnt;
			}
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (A[r][c].next != 0) {
				A[r][c].now = A[r][c].next;
				A[r][c].next = 0;
			}
		}
	}
}

void MoveCloud(int m) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (C[r][c].now == 1) {
				int next_x = c + (dx[d[m]] * s[m]);
				int next_y = r + (dy[d[m]] * s[m]);

				if (next_x < 1) {
					next_x = N - (abs(next_x) % N);
				}
				else if (next_x > N) {
					if (next_x % N == 0) {
						next_x = N;
					}
					else {
						next_x = next_x % N;
					}
				}

				if (next_y < 1) {
					next_y = N - (abs(next_y) % N);
				}
				else if (next_y > N) {
					if (next_y % N == 0) {
						next_y = N;
					}
					else {
						next_y = next_y % N;
					}
				}

				C[next_y][next_x].next = 1;
				A[next_y][next_x].now++;

				C[r][c].now = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> A[r][c].now;

			if (c == 1 || c == 2) {
				if (r == N || r == N - 1) {
					C[r][c].now = 1;
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> d[i] >> s[i];
	}

	for (int i = 0; i < M; i++) {
		MoveCloud(i);
		WaterMagic();
		MakeCloud();
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			result += A[r][c].now;
		}
	}

	cout << result;

	return 0;
}