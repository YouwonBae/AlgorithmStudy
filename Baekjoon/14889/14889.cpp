#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 20

int N; // 4 ¡Â N ¡Â 20, NÀº Â¦¼ö
int mate_flag = 0;

int a_ability;
int b_ability;
int result;

int S[MAX][MAX];
vector<int> team_list;
vector<int> mate_list;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for (int i = 0; i < comb.size(); i++) {
            if (mate_flag == 1) {
                mate_list.push_back(comb[i]);
            }
            else {
                team_list.push_back(comb[i]);
            }
        }
    }
    else if (depth == arr.size())
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        Combination(arr, comb, r, index, depth + 1);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    // input data
    cin >> N;
    int r = N / 2;

	for ( int i = 0; i < N;i++ ) {
		for ( int j = 0; j < N; j++ ) {
			cin >> S[i][j];
            result += S[i][j];
		}
	}

    // team combination
    vector<int> v;
    for (int i = 0; i < N; i++) {
        v.push_back(i);
    }

    vector<int> team_comb(r);
    Combination(v, team_comb, r, 0, 0);

    // calculate team ability
    mate_flag = 1;

    vector<int> a_mate;
    vector<int> b_mate;

    vector<int> mate_comb(2);
    for (int i = 0; i < team_list.size()/2; i++) {
        int first_mate = 0;
        int second_mate = 0;

        a_mate.push_back(team_list[i]);

        if ((i + 1) % r == 0) {

            for (int i = 0; i < N; i++) {
                int flag = 0;

                for (int j = 0; j < a_mate.size(); j++) {
                    if (i == a_mate[j]) {
                        flag = 1;
                    }
                }

                if (flag == 0) {
                    b_mate.push_back(i);
                }
            }

            Combination(a_mate, mate_comb, 2, 0, 0);
            a_mate.clear();

            for (int i = 0; i < mate_list.size(); i++) {
                if ((i + 1) % 2 == 0) {
                    second_mate = mate_list[i];

                    a_ability += S[first_mate][second_mate];
                    a_ability += S[second_mate][first_mate];
                }
                else {
                    first_mate = mate_list[i];
                }
            }
            mate_list.clear();

            Combination(b_mate, mate_comb, 2, 0, 0);
            b_mate.clear();

            for (int i = 0; i < mate_list.size(); i++) {
                if ((i + 1) % 2 == 0) {
                    second_mate = mate_list[i];

                    b_ability += S[first_mate][second_mate];
                    b_ability += S[second_mate][first_mate];
                }
                else {
                    first_mate = mate_list[i];
                }
            }
            mate_list.clear();

            if (abs(a_ability - b_ability) < result) {
                result = abs(a_ability - b_ability);
            }

            a_ability = 0;
            b_ability = 0;
        }
    }

    cout << result << "\n";

	return 0;
}