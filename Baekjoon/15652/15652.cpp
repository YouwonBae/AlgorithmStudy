#include <iostream>
#include <vector>

using namespace std;

int N; // 1 <= N <= 8
int M; // 1 <= N <= 8

vector<int> numbers;

void PickNum(vector<int> comb, int pre_num, int depth) {
	if (depth == M) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] >= pre_num) {
				comb[depth] = numbers[i];
				PickNum(comb, numbers[i], depth + 1);
			}
		}
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

	vector<int> comb(M);

	PickNum(comb, 0,  0);

	return 0;
}