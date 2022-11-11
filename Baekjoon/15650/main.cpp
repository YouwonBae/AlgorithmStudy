#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> numbers;

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

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		numbers.push_back(i);
	}

	vector<int> combi(M);

	combination(numbers, combi, M, 0, 0);

	return 0;
}