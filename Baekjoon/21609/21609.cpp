#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 20

using namespace std;

int N; // 1 <= N <= 20
int M; // 1 <= M <= 5

int result;

int block[MAX][MAX];
int c_block[MAX][MAX];
int check[MAX][MAX];

int dx[] = { 0, 0 , 1, -1 };
int dy[] = { 1, -1 , 0, 0 };

typedef struct {
	int x;
	int y;
	int c;
	int s;
	int rb;
}block_spec;
vector<block_spec> B;

typedef struct {
	int x;
	int y;
}xy;
queue<xy> Q;

int SortBySize(block_spec a, block_spec b) {
	return a.s > b.s;
}

int SortByRb(block_spec a, block_spec b) {
	return a.rb > b.rb;
}

int SortByY(block_spec a, block_spec b) {
	return a.y > b.y;
}

int SortByX(block_spec a, block_spec b) {
	return a.x > b.x;
}

void RotateBlocks() {
	memcpy(c_block, block, sizeof(c_block));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			block[N - j - 1][i] = c_block[i][j];
		}
	}
}

void WorkGravity() {
	for (int r = 1; r < N; r++) {
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (block[i][j] >= 0 && block[i + 1][j] == -2) {
					block[i + 1][j] = block[i][j];
					block[i][j] = -2;
				}
			}
		}
	}
}

void RemoveBlock(int x, int y, int block_color, int block_size) {
	Q.push({ x, y });

	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && check[next_y][next_x] == 0
				&& (block[next_y][next_x] == 0 || block[next_y][next_x] == block_color)) {
				check[next_y][next_x] = 1;

				block[next_y][next_x] = -2;

				Q.push({ next_x , next_y });
			}
		}
	}

	result += (block_size * block_size);
	memset(check, 0, sizeof(check));
	B.clear();
}

void FindBlock(int x, int y, int block_color) {
	int size_cnt = 0;
	int rainbow_cnt = 0;

	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		Q.pop();
		size_cnt++;

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && check[next_y][next_x] == 0
				&& (block[next_y][next_x] == 0 || block[next_y][next_x] == block_color)) {

				check[next_y][next_x] = 1;

				if (block[next_y][next_x] == 0) {
					rainbow_cnt++;
				}

				Q.push({ next_x , next_y });
			}
		}
	}

	if (size_cnt >= 2) {
		B.push_back({ x , y, block_color, size_cnt, rainbow_cnt });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> block[i][j];
		}
	}

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0 && block[i][j] > 0) {
					check[i][j] = 1;
					Q.push({ j, i });
					FindBlock(j, i, block[i][j]);

					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							if (block[i][j] == 0) {
								check[i][j] = 0;
							}
						}
					}
				}
			}
		}

		if (B.size() == 0) {
			break;
		}

		memset(check, 0, sizeof(check));

		sort(B.begin(), B.end(), SortBySize);
		while (B.back().s != B.front().s) {
			B.pop_back();
		}
		sort(B.begin(), B.end(), SortByRb);
		while (B.back().rb != B.front().rb) {
			B.pop_back();
		}
		sort(B.begin(), B.end(), SortByY);
		while (B.back().y != B.front().y) {
			B.pop_back();
		}
		sort(B.begin(), B.end(), SortByX);
		while (B.back().x != B.front().x) {
			B.pop_back();
		}

		RemoveBlock(B.front().x, B.front().y, B.front().c, B.front().s);
		WorkGravity();
		RotateBlocks();
		WorkGravity();
	}

	cout << result;

	return 0;
}