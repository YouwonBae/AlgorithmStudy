#include <iostream>
#include <queue>

using namespace std;

int N;

priority_queue<int> Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for(int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;

		if (num == 0) {
			if (Q.size() == 0) {
				cout << "0" << "\n";
			}
			else {
				cout << abs(Q.top()) << "\n";
				Q.pop();
			}
		}
		else {
			num *= -1;
			Q.push(num);
		}
	}

	return 0;
}