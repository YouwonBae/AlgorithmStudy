# combination


## 조합
```
#include <iostream>
#include <vector>

using namespace std;

int N; // N >= 1
int R; // M <= 8

int comb_case;

vector<int> team_list[100000];

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for (int i = 0; i < comb.size(); i++) {
            team_list[comb_case].push_back(comb[i]);
        }

        comb_case++;
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

    // input office data
    cin >> N >> R;
    cout << "\n";

    comb_case = 0;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        v.push_back(i);
    }

    vector<int> comb(R);
    Combination(v, comb, R, 0, 0);

    for (int i = 0; i < comb_case; i++) {
        for (int a = 0; a < team_list[i].size(); a++) {
            cout << team_list[i][a] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
```