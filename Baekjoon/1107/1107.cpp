#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N; // 0 <= N <= 500000
int M; // 0 <= M <= 10

int start_channel = 100;
int match_num;

int result;

int B[10];
vector<int> buttons;
vector<int> goal;

int CheckLength(int num) {
	int devide_cnt = 0;
	while (num) {
		num /= 10;
		devide_cnt++;
	}

	return devide_cnt;
}

void IndexingNum(int num) {
	int l = CheckLength(N);
	string s_num = to_string(num);

	for (int i = 0; i < s_num.size(); i++) {
		goal.push_back(s_num[i] - '0');
	}
}

int LowNum() {
	int max_num = buttons.back();
	int head_num = buttons.front();
	int result_num = 0;

	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i] != 0) {
			head_num = max(head_num, buttons[i]);
		}
	}

	for (int i = 2; i <= goal.size(); i++) {
		if (i == 0) {
			result_num = head_num * pow(10, goal.size() - i);
		}
		else {
			result_num += max_num * pow(10, goal.size() - i);
		}
	}

	return result_num;
}

int HighNum() {
	int min_num = buttons.front();
	int head_num = buttons.back();
	int result_num = 0;

	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i] != 0) {
			head_num = min(head_num, buttons[i]);
		}
	}

	for (int i = 0; i <= goal.size(); i++) {
		if (i == 0) {
			result_num = head_num * pow(10, goal.size() - i);
		}
		else {
			result_num += min_num * pow(10, goal.size() - i);
		}
	}

	return result_num;
}

int NearNum() {
	int high_num = 0;
	int low_num = 0;

	int up_num = buttons.back();
	int down_num = buttons.front();

	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i] < goal[0]) {
			down_num = max(down_num, buttons[i]);
		}
		else if (buttons[i] > goal[0]) {
			up_num = min(up_num, buttons[i]);
		}
	}

	for (int i = 1; i <= goal.size(); i++) {
		if (i == 1) {
			low_num = down_num * pow(10, goal.size() - i);
		}
		else {
			low_num += buttons.back() * pow(10, goal.size() - i);
		}
	}

	for (int i = 1; i <= goal.size(); i++) {
		if (i == 1) {
			high_num = up_num * pow(10, goal.size() - i);
		}
		else {
			high_num += buttons.front() * pow(10, goal.size() - i);
		}
	}

	//cout << "/''" << low_num << "\n";
	//cout << "/''" << high_num << "\n";

	if (abs(N - low_num) < abs(N - high_num)) {
		return low_num;
	}
	else {
		return high_num;
	}
}

int MatchNum(int depth) {
	int high_num = 0;
	int low_num = 0;

	if (depth == goal.size()) {
		//cout << match_num << "\n";
		return match_num;
	}
	else {
		int up_num = buttons.back();
		int down_num = buttons.front();

		for (int i = 0; i < buttons.size(); i++) {
			if (goal[depth] == buttons[i]) {
				match_num += goal[depth] * pow(10, goal.size() - 1 - depth);

				return MatchNum(depth + 1);
			}
			else if (buttons[i] < goal[depth]) {
				down_num = max(down_num, buttons[i]);
			}
			else {
				up_num = min(up_num, buttons[i]);
			}
		}

		low_num = match_num + down_num * pow(10, goal.size() - 1 - depth);
		high_num = match_num + up_num * pow(10, goal.size() - 1 - depth);

		for (int i = depth + 1; i < goal.size(); i++) {
			low_num += buttons.back() * pow(10, goal.size() - 1 - i);
		}

		for (int i = depth + 1; i < goal.size(); i++) {
			high_num += buttons.front() * pow(10, goal.size() - 1 - i);
		}

		//cout << "/''" << low_num << "\n";
		//cout << "/''" << high_num << "\n";

		if (abs(N - low_num) < abs(N - high_num)) {
			return low_num;
		}
		else {
			return high_num;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num = 0;
		cin >> num;
		B[num] = 1;
	}

	for (int i = 0; i < 10; i++) {
		if (B[i] == 0) {
			buttons.push_back(i);
		}
	}

	IndexingNum(N);

	result = abs(N - start_channel);

	if (buttons.size() > 0) {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				int num = MatchNum(0);
				int click = CheckLength(num);
				if (click == 0) {
					click++;
				}
				result = min(result, click + abs(num - N));
			}
			else if (i == 1) {
				int num = NearNum();
				int click = CheckLength(num);
				if (click == 0) {
					click++;
				}
				result = min(result, click + abs(num - N));
			}
			else if (i == 2) {
				int num = HighNum();
				int click = CheckLength(num);
				if (click == 0) {
					click++;
				}
				result = min(result, click + abs(num - N));
			}
			else {
				if (goal.size() > 1) {
					int num = LowNum();
					int click = CheckLength(num);
					if (click == 0) {
						click++;
					}
					result = min(result, click + abs(num - N));
				}
			}
		}
	}

	cout << result;

	return 0;
}