#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N; // 1 <= N <= 15
int R; // 0 <= R <= 2^N
int C; // 0 <= C <= 2^N

int now_r;
int now_c;


int arr_x[32768];
int depth_x[32768];

typedef struct {
    int x;
    int y;
}xy;
vector<xy> V;

void MakeIndex() {
    int depth = 1;

    while (1) {
        int length = V.size();

        if (length > pow(2, N)) {
            return;
        }

        for (int i = 0; i < length; i++) {
            int now_x = V[i].x;
            int now_y = V[i].y;

            int next_x = now_x + pow(4, depth - 1);
            int next_y = now_y + pow(2, 2 * (depth - 1) + 1);

            V.push_back({ next_x, next_y });
        }

        depth++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R >> C;

    V.push_back({0, 0});

    MakeIndex();

    cout << V[C].x + V[R].y;

    return 0;
}