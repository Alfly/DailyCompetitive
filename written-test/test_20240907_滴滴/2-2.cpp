#include<iostream>
#include<vector>
using namespace std;

string s;

int dfs(int i, int j, vector<vector<int>>& cost, vector<vector<int>>& memo) {
    int &v = memo[i][j];
    if (v != -1) return v;
    if (i >= j) return v = 0;
    // 拆分两头
    int res = dfs(i + 1, j - 1, cost, memo) + cost[s[i] - 'a'][s[j] - 'a'];
    // 拆中间
    for (int t = i + 1; t + 1 < j; t += 2) {
        res = max(res, dfs(i, t, cost, memo) + dfs(t + 1, j, cost, memo));
    }
    return v = res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> cost(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> cost[i][j];
        }
    }
    cin >> s;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    cout << dfs(0, n - 1, cost, memo) << endl;
    return 0;
}