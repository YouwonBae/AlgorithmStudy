#include <iostream>
#include <stack>

#define MAX 1000000

using namespace std;

int N; // 1 <= N <= 1000000
int A[MAX];
int NGE[MAX];

typedef struct {
	int num;
	int index;
}ni;
stack<ni> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	cin >> A[0];
	s.push({ A[0], 0 });
	NGE[0] = -1;

	for (int i = 1; i < N; i++) {
		cin >> A[i];

		if (!s.empty() || s.top().num < A[i]) {
			while (!s.empty() && s.top().num < A[i]) {
				NGE[s.top().index] = A[i];
				s.pop();
			}
		}

		NGE[i] = -1;
			
		s.push({ A[i], i });
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << " ";
	}

	return 0;
}