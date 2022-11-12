#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
int open_cnt;
stack<char> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		string s;

		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				open_cnt++;
			}
			else {
				open_cnt--;
			}

			if (open_cnt < 0) {
				open_cnt = -1;
				break;
			}
		}

		if (open_cnt == 0) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		open_cnt = 0;
	}

	return 0;
}