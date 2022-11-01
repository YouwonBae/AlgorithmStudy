#include <iostream>

#define MAX 12

using namespace std;

int N; // 2 ¡Â N ¡Â 11
int R;

int numbers[MAX];
int calculated[MAX];

int operators[MAX];
int ch[MAX];
int picked_list[MAX];

int plus_cnt;
int minus_cnt;
int multiple_cnt;
int devision_cnt;
int operator_cnt;

int max_result;
int min_result;

void Permutation(int depth) {
	if (depth >= R) {

		for (int i = 0; i < N; i++) {
			calculated[i] = numbers[i];
		}

		for (int i = 0; i < R; i++) {
			if (picked_list[i] == 0) {
				calculated[i + 1] = calculated[i] + calculated[i + 1];
			}
			else if (picked_list[i] == 1) {
				calculated[i + 1] = calculated[i] - calculated[i + 1];
			}
			else if (picked_list[i] == 2) {
				calculated[i + 1] = calculated[i] * calculated[i + 1];
			}
			else if (picked_list[i] == 3) {
				calculated[i + 1] = calculated[i] / calculated[i + 1];
			}
		}

		if (calculated[R] < min_result) {
			min_result = calculated[R];
		}
		if (calculated[R] > max_result) {
			max_result = calculated[R];
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			if (ch[i] == 0) {
				ch[i] = 1;
				picked_list[depth] = operators[i];
				Permutation(depth + 1);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	max_result = -1000000000;
	min_result = 1000000000;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			cin >> plus_cnt;
			for (int j = 0; j < plus_cnt; j++) {
				operators[operator_cnt] = i;
				operator_cnt++;
			}
		} 
		else if (i == 1) {
			cin >> minus_cnt;
			for (int j = 0; j < minus_cnt; j++) {
				operators[operator_cnt] = i;
				operator_cnt++;
			}
		}
		else if (i == 2) {
			cin >> multiple_cnt;
			for (int j = 0; j < multiple_cnt; j++) {
				operators[operator_cnt] = i;
				operator_cnt++;
			}
		}
		else if (i == 3) {
			cin >> devision_cnt;
			for (int j = 0; j < devision_cnt; j++) {
				operators[operator_cnt] = i;
				operator_cnt++;
			}
		}
	}

	R = N - 1;
	
	Permutation(0);

	cout << max_result << "\n" << min_result;

	return 0;
}
