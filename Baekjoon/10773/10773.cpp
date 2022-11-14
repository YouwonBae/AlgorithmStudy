#include <iostream>
#include <stack>

using namespace std;

int K;
unsigned int sum;

stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	for (int i = 0; i < K; i++) {
		int num = 0;
		cin >> num;

		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}