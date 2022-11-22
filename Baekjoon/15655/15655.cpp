#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 1 <= N <= 8
int M; // 1 <= M <= 8

int ch[9];

vector<int> numbers;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth) {
	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else if(depth == arr.size()) {
		return;
	}
	else {
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		Combination(arr, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());
	
	vector<int> comb(M);

	Combination(numbers, comb, M, 0, 0);

	return 0;
}