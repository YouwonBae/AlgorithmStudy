#include <iostream>

#define MAX 1001

using namespace std;

int N;

long long dp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
			dp[i] = dp[i] % 10007;
		}
	}

	cout << dp[N] % 10007;

	return 0;
}