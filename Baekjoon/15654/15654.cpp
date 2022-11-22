#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 1 <= N <= 8
int M; // 1 <= M <= 8

int ch[9];

vector<int> numbers;

void PickNum(vector<int> arr, vector<int> comb, int depth) {
	if (depth == M) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (ch[i] == 0) {
				ch[i] = 1;

				comb[depth] = arr[i];

				PickNum(arr, comb, depth + 1);
				ch[i] = 0;
			}
		}
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

	vector<int> comb(M);

	sort(numbers.begin(), numbers.end());

	PickNum(numbers, comb, 0);

	return 0;
}