#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;

stack<char> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	cin.ignore();

	while (T--) {
		string s;

		getline(cin, s);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				while(st.size()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else {
				st.push(s[i]);
			}

			if (i == s.size() - 1) {
				while (st.size()) {
					cout << st.top();
					st.pop();
				}
				cout << "\n";
			}
		}
	}

	return 0;
}