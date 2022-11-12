#include <iostream>

using namespace std;

int A;
int B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		cin >> A >> B;

		if (A == 0 && B == 0) {
			break;
		}

		cout << A + B << "\n";
	}

	return 0;
}