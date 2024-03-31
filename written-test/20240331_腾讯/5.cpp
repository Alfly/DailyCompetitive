#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int ans = 0;
int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};
string target = "tencent";

void dfs(vector<string> &g, vector<vector<bool>> &st, int i, int j, int idx) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    // if (st[i][j]) return;
    if (g[i][j] != target[idx]) return;
    if (idx == 6) {
        ans++;
        return;
    }
    // printf("%d %d\n", i, j);
    for (int k = 0; k < 4; k++) {
        int x = i + xx[k], y = j + yy[k];
        // st[i][j] = true;
        dfs(g, st, x, y, idx + 1);
        // st[i][j] = false;
    }
}

int main() {
    cin >> n >> m;
    vector<string> g(n);
    vector<vector<bool> > st(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 't') {
                st.clear();
                dfs(g, st, i, j, 0);
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}