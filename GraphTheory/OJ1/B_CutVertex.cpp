#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
int d[N], low[N], p[N], children[N];
bool st[N];
set<int> cutVers;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfscv(int u, int time) {
    time += 1;
    d[u] = time;
    low[u] = d[u];
    st[u] = true;
    for (int v : g[u]) {
        if (st[v] == false) {
            p[v] = u;
            children[u] += 1;
            dfscv(v, time);
            low[u] = min(low[u], low[v]);
            if (p[u] == -1 && children[u] >= 2) {
                cutVers.insert(u);
            } else if (p[u] != -1 && low[v] >= d[u]) {
                cutVers.insert(u);
            }
        } else if (v != p[u]) {
            low[u] = min(low[u], d[v]);
        }
    }
}

int main() {
    // build graph
    // freopen("graph2.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // init
    memset(d, 0, sizeof d);
    memset(low, 0, sizeof low);
    memset(p, -1, sizeof p);
    memset(children, 0, sizeof children);
    // dfs
    for (int root = 1; root <= n; root++) {
        if (st[root] == false) {
            dfscv(root, 0);
        }
    }

    // print results
    vector<int> ans;
    for (int x: cutVers) ans.push_back(x);
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << '\n';
    return 0;
}