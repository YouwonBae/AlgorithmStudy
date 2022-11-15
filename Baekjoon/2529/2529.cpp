#include <iostream>

#define MAX 9;

using namespace std;

int K;
char ineq_sign[9];

int right_cnt;
int now_num;

void MaxList() {
	now_num = 9;

	for (int i = 0; i <= K; i++) {
		if (ineq_sign[i] == '<') {
			right_cnt++;
		}
		else {
			for (int j = now_num - right_cnt; j <= now_num; j++) {
				cout << j;
			}

			now_num -= (right_cnt + 1);
			right_cnt = 0;
		}
	}
}

void MinList() {
	now_num = 0;

	for (int i = 0; i <= K; i++) {
		if (ineq_sign[i] == '>') {
			right_cnt++;
		}
		else {
			for (int j = now_num + right_cnt; j >= now_num; j--) {
				cout << j;
			}

			now_num += (right_cnt + 1);
			right_cnt = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> ineq_sign[i];
	}

	MaxList();
	cout << "\n";
	MinList();

	return 0;
}