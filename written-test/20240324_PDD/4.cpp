#include <iostream>
#include <cstring>
using namespace std;

const int N = 505;
char str[505];
int f[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(f, 0x3f, sizeof f);
        cin >> (str + 1);
        int n = strlen(str + 1);

        for (int i = 1; i <= n; i++) {
            f[i][i] = 0;
            f[i + 1][i] = 0;    // 长度为 2 的回文串
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (str[l] == str[r]) {
                    f[l][r] = f[l + 1][r - 1];
                } else {
                    for (int k = l; k < r; k++) {
                        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + 1);
                    }
                }
                // printf("f[%d][%d] = %d\n", l, r, f[l][r]);
            }
        }
        cout << f[1][n] + 1 << endl;
    }
    return 0;
}