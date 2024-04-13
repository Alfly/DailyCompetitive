/* 

N * 2 的矩形放入 1 * 2 砖块，砖块 K 个颜色

恰好放入矩形区域并满足相邻砖块颜色不同，求方案数量

 */

#include <iostream>
#include <cstring>
using namespace std;

const int mod = 12345787;

int solution(int n, int k) {

    long long f[n + 1][k + 1];
    memset(f, 0, sizeof f);

    for (int j = 0; j <= k; j++) f[0][j] = 1;
    // for (int j = 0; j <= k; j++) f[1][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= 2) f[i][j] = ((f[i - 1][j - 1] * j) % mod + (f[i - 2][j - 2] * j * (j - 1)) % mod ) % mod;
            else f[i][j] = (f[i - 1][j - 1] * j + 0) % mod;
            printf("f[%d][%d]: %lld\n", i, j, f[i][j]);
        }
    }
    
    return f[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solution(n, k) << endl;
    return 0;
}

/* 

状态转移有问题：

f[3][2] = f[2][1] * 2 + f[1][0] * 2 * 1 = 0

121  212
121  212

 */