#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 105, MAXV = 0x3f3f3f3f;
int n, x;

int DP2dim(vector<int> &t) {
    vector<vector<int>> f(n + 1, vector<int>(x + 1, MAXV));
    for (int i = 0; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j >= t[i - 1]) f[i][j] = min(f[i - 1][j], f[i - 1][j - t[i - 1]] + 1);
            else f[i][j] = f[i - 1][j];
        }
    }
    return f[n][x];
}

int DP(vector<int> &t) {
    vector<int> f(x + 1, MAXV);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= t[i]; j--) {
            f[j] = min(f[j], f[j - t[i]] + 1);
        }
    }
    return f[x];
}

int main() {
    cin >> n >> x;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = MAXV;
    for (int i = 0; i < n; i++) {
        // 处理数组
        for (int j = 0; j < n; j++) t[j] = a[j] / 2;
        t[i] = a[i];
        // 多次 DP
        // ans = min(ans, DP(t));
        ans = min(ans, DP2dim(t));
    }

    if (ans == MAXV) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
