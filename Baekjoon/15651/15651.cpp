#include <iostream>
#include <vector>

using namespace std;

int N; // 1 <= N <= 7
int M; // 1 <= N <= 7

vector<int> numbers;

void PickNum(vector<int> comb, int depth) {
	if (depth == M) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			comb[depth] = numbers[i];
			PickNum(comb, depth + 1);
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

	PickNum(comb, 0);

	return 0;
}