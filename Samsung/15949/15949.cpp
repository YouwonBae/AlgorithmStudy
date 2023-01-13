#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

string N; // 1 <= N.size() <= 100000
int x; // 0 <= x <= 9
int y; // 0 <= y <= 9 // x < y

int ch[10];
vector<int> number;

void InitData() {
	memset(ch, 0, sizeof(ch));
	number.clear();
}

void Input() {
	cin >> N;
	cin >> x >> y;
}

void Output(int t) {
	cout << "#" << t << " ";

	if (!number.empty()) {
		for (int i = 0; i < number.size(); i++) {
			cout << number[i];
		}
	}
	else {
		cout << "-1";
	}

	cout << "\n";
}

void RemoveZero() {
	while (!number.empty() && (number.front() == 0 || number.front() == -1)) {
		number.erase(number.begin());
	}
}

void MakeCard() {
	int index = 0;
	bool match = true;
	bool dir = true;

	while (index < N.size()) {
		int compare = N[index] - '0';

		if (match) {
			if (compare < x) {
				if (index <= 0) {
					number.push_back(-1);
					index++;
					match = false;
					dir = true;
				}
				else {
					index--;
					match = false;
					dir = false;
				}
			}
			else if (compare > x && compare < y) {
				number.push_back(x);
				if (index > 0) {
					ch[x]++;
				}
				index++;
				match = false;
				dir = true;
			}
			else if (compare > y) {
				number.push_back(y);
				ch[y]++;
				index++;
				match = false;
				dir = true;
			}
			else {
				number.push_back(compare);
				ch[compare]++;
				index++;
				match = true;
				dir = true;
			}
		}
		else {
			if (dir) {
				number.push_back(y);
				ch[y]++;
				index++;
				match = false;
				dir = true;
			}
			else {
				number.pop_back();

				if (compare > x) {
					number.push_back(x);
					ch[x]++;
					index++;
					match = false;
					dir = true;
				}
				else {
					if (index <= 0) {
						number.push_back(-1);
						index++;
						match = false;
						dir = true;
					}
					else {
						index--;
						match = false;
						dir = false;
					}
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		InitData();
		Input();
		MakeCard();
		RemoveZero();
		Output(test_case);
	}
	return 0;
}