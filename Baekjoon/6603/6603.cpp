#include <iostream>
#include <vector>

using namespace std;

int K; // 6 <= K <= 13

vector<int> numbers;
vector<int> combi(6);

void combination(vector<int> arr, vector<int> comb, int r, int index, int depth) {
	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[index] = arr[depth];
		combination(arr, comb, r - 1, index + 1, depth + 1);

		combination(arr, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		cin >> K;

		if (K == 0) {
			break;
		}
		else {
			for (int i = 0; i < K; i++) {
				int number;
				cin >> number;

				numbers.push_back(number);
			}

			combination(numbers, combi, 6, 0, 0);

			cout << "\n";

			numbers.clear();
		}
	}

	return 0;
}