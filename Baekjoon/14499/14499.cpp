#include <iostream>

#define MAX 20

using namespace std;

int N, M; // 1 ¡Â N, M ¡Â 20
int X, Y;
int K; // 1 ¡Â K ¡Â 1000
int C;

int top;

int map[MAX][MAX];
int dice[6];
int dice_safebox;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X >> Y >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	while (K--) {
		cin >> C;

		if (C == 1) {
			if (Y + 1 >= 0 && Y + 1 < M) {
				Y++;
				dice_safebox = dice[5];
				dice[5] = dice[2];
				dice[2] = dice[0];
				dice[0] = dice[3];
				dice[3] = dice_safebox;

				if (map[X][Y] == 0) {
					map[X][Y] = dice[5];
				}
				else {
					dice[5] = map[X][Y];
					map[X][Y] = 0;
				}

				cout << dice[0] << "\n";
			}
		}
		else if (C == 2) {
			if (Y - 1 >= 0 && Y - 1 < M) {
				Y--;
				dice_safebox = dice[5];
				dice[5] = dice[3];
				dice[3] = dice[0];
				dice[0] = dice[2];
				dice[2] = dice_safebox;

				if (map[X][Y] == 0) {
					map[X][Y] = dice[5];
				}
				else {
					dice[5] = map[X][Y];
					map[X][Y] = 0;
				}

				cout << dice[0] << "\n";
			}
		}
		else if (C == 3) {
			if (X - 1 >= 0 && X - 1 < N) {
				X--;
				dice_safebox = dice[5];
				dice[5] = dice[1];
				dice[1] = dice[0];
				dice[0] = dice[4];
				dice[4] = dice_safebox;

				if (map[X][Y] == 0) {
					map[X][Y] = dice[5];
				}
				else {
					dice[5] = map[X][Y];
					map[X][Y] = 0;
				}

				cout << dice[0] << "\n";
			}
		}
		else if (C == 4) {
			if (X + 1 >= 0 && X + 1 < N) {
				X++;
				dice_safebox = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[0];
				dice[0] = dice[1];
				dice[1] = dice_safebox;

				if (map[X][Y] == 0) {
					map[X][Y] = dice[5];
				}
				else {
					dice[5] = map[X][Y];
					map[X][Y] = 0;
				}

				cout << dice[0] << "\n";
			}
		}
	}

	return 0;
}