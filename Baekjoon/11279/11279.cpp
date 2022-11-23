#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> Q;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while(N--) {
		int num = 0;
		cin >> num;

		if (num == 0) {
			if (!Q.empty()) {
				cout << Q.top() << "\n";
				Q.pop();
			}
			else {
				cout << "0" << "\n";
			}
		}
		else {
			Q.push(num);
		}
	}

	return 0;
}