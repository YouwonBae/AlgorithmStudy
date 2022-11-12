#include <iostream>
#include <string>

using namespace std;

int T;
int A;
int B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		A = s[0] - '0';
		B = s[2] - '0';

		cout << A + B << "\n";
	}

	return 0;
}