#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int ds[] = { -1, 1 };

int gear[4][9];
int copy_gear[4][9];
int spin_ch[4];
int K;
int gear_num;
int spin_dir;

int score;

void MakeScore() {
	for (int i = 0; i < 4; i++) {
		if (copy_gear[i][0] == 1) {
			score += pow(2, i);
		}
	}
}

void SpinGear(int num, int dir) {
	int next_dir = 0;

	if (dir == 1) { // clock
		for (int i = 8; i >= 1; i--) {
			copy_gear[num][i] = copy_gear[num][i - 1];
		}
		copy_gear[num][0] = copy_gear[num][8];

		next_dir = -1;
	}
	else {
		copy_gear[num][8] = copy_gear[num][0];

		for (int i = 0; i <= 7; i++) {
			copy_gear[num][i] = copy_gear[num][i + 1];
		}

		next_dir = 1;
	}

	for (int i = 0; i < 2; i++) {
		int next_num = num + ds[i];

		if (next_num >= 0 && next_num <= 3 && spin_ch[next_num] == 0) {
			spin_ch[next_num] = 1;
			if (i == 0) { // left
				if (dir == 1) { // clock
					if (copy_gear[num][7] != copy_gear[next_num][2]) {
						SpinGear(next_num, next_dir);
					}
				}
				else {
					if (copy_gear[num][5] != copy_gear[next_num][2]) {
						SpinGear(next_num, next_dir);
					}
				}
			}
			else {        // right
				if (dir == 1) { // clock
					if (copy_gear[num][3] != copy_gear[next_num][6]) {
						SpinGear(next_num, next_dir);
					}
				}
				else {
					if (copy_gear[num][1] != copy_gear[next_num][6]) {
						SpinGear(next_num, next_dir);
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

	string str_gear[4];

	for (int i = 0; i < 4; i++) {
		cin >> str_gear[i];

		for (int j = 0; j < 8; j++) {
			if (str_gear[i][j] == '0') {
				gear[i][j] = 0;
			}
			else {
				gear[i][j] = 1;
			}
		}
	}
	cin >> K;

	memcpy(copy_gear, gear, sizeof(gear));

	while (K--) {
		cin >> gear_num >> spin_dir;

		gear_num -= 1;

		spin_ch[gear_num] = 1;
		SpinGear(gear_num, spin_dir);

		memset(spin_ch, 0, sizeof(spin_ch));
	}

	MakeScore();

	cout << score;

	return 0;
}