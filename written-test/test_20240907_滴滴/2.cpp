#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> cost(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> cost[i][j];
        }
    }
    string s; cin >> s;
    vector<vector<int>> f(n, vector<int>(n, -1));
    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            // 拆分两头
            f[i][j] = max(f[i][j], (i + 1 < j - 1 ? f[i + 1][j - 1] : 0) + cost[s[i] - 'a'][s[j] - 'a']);
            // 拆中间
            // for (int t = i; t <= j; t += 2) {
            //     f[i][j] = max(f[i][j], (i < t - 1 ? f[i][t - 1] : 0) + 
            //                            (t + 2 < j ? f[t + 2][j] : 0) + 
            //                             cost[s[t] - 'a'][s[t + 1] - 'a']);
            // }
            for (int t = i + 1; t + 1 < j; t += 2) {
                f[i][j] = max(f[i][j], f[i][t] + f[t + 1][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("[%d][%d]=%d ", i, j, f[i][j]);
        }
        printf("\n");
    }
    cout << f[0][n - 1] << endl;
    return 0;
}