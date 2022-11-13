#include <iostream>
#include <vector>

using namespace std;

int N;
int K;

int iter;

vector<int> numbers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		numbers.push_back(i);
	}

	iter = K - 1;

	cout << "<";

	while (numbers.size()) {
		cout << numbers[iter];

		numbers.erase(numbers.begin() + iter);

		iter += K - 1;

		if (numbers.size()) {
			cout << ", ";
			while (iter >= numbers.size()) {
				iter -= numbers.size();
			}
		}
	}

	cout << ">";

	return 0;
}