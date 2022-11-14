#include <iostream>

using namespace std;

int N; // 1<= N <= 300
int stairs[301];
int dp[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = max(dp[1] + stairs[3], stairs[2] + stairs[3]);

	if (N >= 4) {
		for (int i = 4; i <= N; i++) {
			dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
		}
	}

	cout << dp[N];

	return 0;
}