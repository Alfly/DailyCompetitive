#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
bool st[N];
int m, n;

void dfs(int u) {
    st[u] = true;
    for (int v : g[u]) {
        if (st[v] == false) {
            dfs(v);
        }
    }
}

int main() {
    // freopen("group.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(st, 0, sizeof st);
    int ans = 0;
    for (int root = 1; root <= n; root++) {
        if (st[root] == false) {
            dfs(root);
            ans ++;
        }
    }
    cout << ans;
    return 0;
}