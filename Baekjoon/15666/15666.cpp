#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 9

using namespace std;

int N, M; // 1 <= N, M <= 8

vector<int> numbers;
vector<int> list(MAX);
bool ch[MAX][10001];

int SortByNum(int a, int b) {
	return a < b;
}

void Output(vector<int> list, int m) {
	for (int i = 0; i < m; i++) {
		cout << list[i] << " ";
	}
	cout << "\n";
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

void MakeArr(vector<int> list, vector<int> numbers, int index, int depth) {
	if (depth == M) {
		Output(list, M);
	}
	else {
		for (int i = index; i < numbers.size(); i++) {
			int n = numbers[i];

			if (ch[depth][n] == false) {
				ch[depth][n] = true;

				list[depth] = n;

				MakeArr(list, numbers, i,  depth + 1);
				memset(ch[depth + 1], 0, sizeof(ch[depth + 1]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	MakeArr(list, numbers, 0, 0);

	return 0;
}