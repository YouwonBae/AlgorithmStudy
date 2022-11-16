#include <iostream>
#include <stack>

#define MAX 1000001
using namespace std;

int N; // 1 <= A <= 1000000
int A[MAX];
int F[MAX];

int NFG[MAX];

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

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		F[A[i]]++;
	}

	s.push({ A[0], 0 });
	NFG[0] = -1;

	for (int i = 1; i < N; i++) {
		if (F[s.top().num] < F[A[i]]) {
			while (!s.empty() && F[s.top().num] < F[A[i]]) {
				NFG[s.top().index] = A[i];

				s.pop();
			}
		}

		NFG[i] = -1;

		s.push({ A[i], i });
	}

	for (int i = 0; i < N; i++) {
		cout << NFG[i] << " ";
	}

	return 0;
}