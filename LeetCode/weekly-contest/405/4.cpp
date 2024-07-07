class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        const int MAXV = 0x3f3f3f3f;
        int n = target.size();
        vector<vector<int>> f(n, vector<int>(n, MAXV));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                string s = target.substr(i, len);
                for (int k = 0; k < words.size(); k++) {
                    if (s != words[k]) continue;
                    f[i][j] = min(f[i][j], costs[k]);
                }
                for (int t = i; t < j; t++) {
                    f[i][j] = min(f[i][j], f[i][t] + f[t+1][j]);
                }
                printf("[%d][%d]: %d\n", i, j, f[i][j]);
            }
        }
        return f[0][n - 1] == MAXV ? -1 : f[0][n - 1];
    }
};