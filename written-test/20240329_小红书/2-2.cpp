#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 105;
int n, x;
int MAXV = 0x3f3f3f3f;
int a[N], b[N];
int f[N][N][2];    // f[i][j][k] 前 i 个数 和 恰好为 j 时选择的数量, k=1 使用了多余 k=0 没使用

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] / 2;
    }
    // init
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            f[i][j][0] = MAXV;
            f[i][j][1] = MAXV;
        }
    }
    for (int i = 0; i <= n; i++) {
        f[i][0][1] = 0;
        f[i][0][0] = 0;
    }
    
    // dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j >= b[i]) {
                f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j - b[i]][0] + 1);
                f[i][j][1] = min(f[i - 1][j][1], f[i - 1][j - b[i]][1] + 1);
                if (j >= a[i]) {
                    f[i][j][1] = min(f[i - 1][j][1], f[i - 1][j - a[i]][0] + 1);
                }
            } else {
                f[i][j][0] = f[i - 1][j][0];
                f[i][j][1] = f[i - 1][j][1];
            }
            printf("f[%d][%d][0]: %d, f[%d][%d][1]: %d\n", i, j, f[i][j][0], i, j, f[i][j][1]);
        }
    }

    int ans = min(f[n][x][1], f[n][x][0]);
    
    if (ans == MAXV) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
