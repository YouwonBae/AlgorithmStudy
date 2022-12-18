#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 10001

using namespace std;

int N, M; // 1 <= N, M <= 10000

vector<int> numbers;
vector<int> list(MAX);
bool ch[MAX];

int SortByNum(int a, int b) {
	return a < b;
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n = 0;
		cin >> n;
		numbers.push_back(n);
	}

	sort(numbers.begin(), numbers.end(), SortByNum);
}

void Output(vector<int> list, int m) {
	for (int i = 0; i < m; i++) {
		cout << list[i] << " ";
	}
	cout << "\n";
}

void Permutation(vector<int> list, vector<int> numbers, int depth, int index) {
	if (depth == M) {
		Output(list, M);
	}
	else {
		for (int i = index; i < numbers.size(); i++) {

			list[depth] = numbers[i];
			Permutation(list, numbers, depth + 1, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	Permutation(list, numbers, 0, 0);

	return 0;
}