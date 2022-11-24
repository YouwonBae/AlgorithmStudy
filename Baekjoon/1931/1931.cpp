#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

typedef struct {
	int start;
	int end;
}se;
vector<se> meet;

int SortByStart(se a, se b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e = 0;
		cin >> s >> e;

		meet.push_back({ s, e });
	}

	sort(meet.begin(), meet.end(), SortByStart);

	int time = 0;
	int result = 0;
	for (int i = 0; i < meet.size(); i++) {
		if (meet[i].start >= time) {
			result++;
			time = meet[i].end;
		}
	}

	cout << result << "\n";

	return 0;
}