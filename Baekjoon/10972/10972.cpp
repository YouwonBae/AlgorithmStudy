#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	vector<int> numbers(N);

	for (int i = 0; i < numbers.size(); i++) {
		int data = 0;
		cin >> data;
		numbers[i] = data;
	}

	if (next_permutation(numbers.begin(), numbers.end())) {
		for (int i = 0; i < numbers.size(); i++) {
			cout << numbers[i] << " ";
		}
	}
	else {
		cout << "-1";
	}

	return 0;
}