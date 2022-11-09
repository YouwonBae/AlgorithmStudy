#include <iostream>
#include <queue>
#include <cstring>

#define MAX 65536

using namespace std;

int t; // t <= 50
int n; // 0 <= n <= 100

int home_x;
int home_y;

int dest_x;
int dest_y;

int result;

typedef struct {
	int x;
	int y;
}xy;

queue<xy> Q;
xy convenience[101];
int check[101];

void BFS() {
	while (!Q.empty()) {
		int now_x = Q.front().x;
		int now_y = Q.front().y;
		int dest_dist = abs(dest_x - now_x) + abs(dest_y - now_y);
		Q.pop();

		if (n > 0) {
			for (int i = 0; i < n; i++) {
				int con_dist = abs(convenience[i].x - now_x) + abs(convenience[i].y - now_y);

				if (dest_dist <= 1000) {
					result = 1;
				}
				else {
					if (con_dist <= 1000 && check[i] == 0) {
						check[i] = 1;

						Q.push({ convenience[i].x, convenience[i].y });
					}
				}
			}
		}
		else {
			if (dest_dist <= 1000) {
				result = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;

	while (t--) {
		int x = 0;
		int y = 0;

		cin >> n;
		cin >> x >> y;
		home_x = x;
		home_y = y;

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			convenience[i].x = x;
			convenience[i].y = y;
		}

		cin >> x >> y;
		dest_x = x;
		dest_y = y;

		Q.push({ home_x , home_y });
		BFS();

		if (result == 1) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}

		memset(check, 0, sizeof(check));
		result = 0;
	}

	return 0;
}