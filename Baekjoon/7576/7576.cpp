#include <iostream>

using namespace std;

int N; // 1<= N <= 300

int score;
int one_cnt;
int stairs[301];
int check[301];

void DownStair(int now_s) {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	score += stairs[N];
	DownStair(N);

	return 0;
}