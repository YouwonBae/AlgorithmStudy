#include <iostream>
#include <vector>

using namespace std;

int N; // 1 <= N <= 8
int M; // 1 <= M <= 8

vector<int> numbers;

int permu_list[8];
int check[8];

void permutation(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << permu_list[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < numbers.size(); i++) {
			if (check[i] == 0) {
				check[i] = 1;
				permu_list[depth] = numbers[i];

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

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		numbers.push_back(i);
	}

	permutation(0);

	return 0;
}