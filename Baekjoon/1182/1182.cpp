#include <iostream>
#include <vector>

using namespace std;

int N;
int S;

int R;

long long sum;
int correct;

int arr[20];
vector<int> numbers;

void combination(vector<int> number, int *comb, int r, int index, int depth){
	if(r == 0) {
		for (int i = 0; i < R; i++) {
			sum += comb[i];
		}

		if (sum == S) {
			correct++;
		}

		sum = 0;
	}
	else if (depth == number.size()) {
		return;
	}
	else {
		comb[index] = number[depth];
		combination(number, comb, r - 1, index + 1, depth + 1);

		combination(number, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		numbers.push_back(arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		R = i;
		combination(numbers, arr, R, 0, 0);
	}

	cout << correct;

	return 0;
}