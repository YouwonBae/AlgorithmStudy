#include <iostream>

using namespace std;

int T;

typedef struct {
    int z;
    int o;
}zo;

zo save_fibo[41];
int ch[41];

void FastFibo(int n) {

    ch[n] = 1;

    if (n == 0) {
        save_fibo[0] = { 1, 0 };
    }
    else if (n == 1) {
        save_fibo[1] = { 0, 1 };
    }
    else {
        if (ch[n - 1] == 0) {
            FastFibo(n - 1);
        }
        
        save_fibo[n].z += save_fibo[n - 1].z;
        save_fibo[n].o += save_fibo[n - 1].o;

        if (ch[n - 2] == 0) {
            FastFibo(n - 2);
        }
        
        save_fibo[n].z += save_fibo[n - 2].z;
        save_fibo[n].o += save_fibo[n - 2].o;
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    cin >> T;

    while (T--)
    {
        int c = 0;
        cin >> c;

        FastFibo(c);

        cout << save_fibo[c].z << " " << save_fibo[c].o << "\n";

        for (int i = 0; i <= c; i++) {
            save_fibo[i] = { 0, 0 };
            ch[i] = 0;
        }
    }

	return 0;
}