#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 1 <= N <= 10000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	vector<int> numbers(N);

	for (int i = 0; i < N; i++) {
		int index = 0;
		cin >> index;
		numbers[i] = index;
	}

	if (prev_permutation(numbers.begin(), numbers.end())) {
		for (int i = 0; i < N; i++) {
			cout << numbers[i] << " ";
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}