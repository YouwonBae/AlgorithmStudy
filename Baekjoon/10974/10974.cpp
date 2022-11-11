#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> numbers;

int picked_list[9];
int check[9];

void permutation(int depth) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			cout << picked_list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] == 0) {
				check[i] = 1;

				picked_list[depth] = numbers[i];
				permutation(depth + 1);
				check[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		numbers.push_back(i);
	}

	permutation(0);

	return 0;
}