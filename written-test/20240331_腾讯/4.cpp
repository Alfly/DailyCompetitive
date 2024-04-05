/*
数组分段异或和最大
- DP: dfs + 记忆化
    - 类似前缀和求所有段的异或值
    - 记忆化搜索 dp[i][t]是前i个数字分成t份后的最大和
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
using namespace std;

const int N = 410;
int a[N], s[N];
int f[N][N];
int n, k;
int ans = 0;

void dfs(int i, int cnt, int sum, vector<int>& path) {
    if (cnt > k) return;
    if (i == n + 1 && cnt == k) {
        // for (int x: path) cout << x << ' ';
        // cout << endl;
        ans = max(ans, sum);
        return;
    }
    for (int j = i; j <= n; j++) {
        path.push_back(i);
        dfs(j + 1, cnt + 1, sum + (s[j] ^ s[i - 1]), path);
        path.pop_back();
    }
}

int dp(int i, int t) {
    // if (t > i) return -1;
    if (t == 0) return 0;   // f[i][1] = max(f[i][1], f[i][0] + s[i]);
    
    int &v = f[i][t];
    if (v != -1) return v;

    for (int j = t - 1; j < i; j++) {
        // [1, i] -> [1, j][j + 1, i]
        v = max(v, dp(j, t - 1) + (s[i] ^ s[j]));
    }
    return v;
}

int main() {
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            // 前缀和（异或）
            s[i] = s[i - 1] ^ a[i];
        }
        
        // ans = 0;
        // vector<int> path;
        // dfs(1, 0, 0, path);

        memset(f, -1, sizeof f);
        ans = dp(n, k);

        cout << ans << endl;
    }
    return 0;
}
