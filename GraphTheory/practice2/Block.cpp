#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

using PII = pair<int, int>;

const int N = 10010;
vector<int> g[N];
int d[N], low[N], p[N], children[N];
bool st[N];
stack<PII> stk;
vector< vector<PII>> ans;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void DFSBlk(int u, int time) {
    time += 1;
    d[u] = time;
    low[u] = d[u];
    st[u] = true;
    for (int v : g[u]) {
        if (st[v] == false) {
            stk.push({u, v});
            p[v] = u;
            children[u] += 1;
            DFSBlk(v, time);
            low[u] = min(low[u], low[v]);
            if ((p[u] == -1 && children[u] >= 2) || ((p[u] != -1 && low[v] >= d[u]))) {
                vector<PII> block;
                PII edge;
                do {
                    edge = stk.top(); stk.pop();
                    block.push_back(edge);
                } while (!stk.empty() && edge != make_pair(u, v));
                ans.push_back(block);
            }
        } else if (v != p[u]) {
            if (d[u] > d[v]) {  // only add backward-edge once
                stk.push({u, v});
            }
            low[u] = min(low[u], d[v]);
        }
    }
}

int main() {
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
    for (int root = 0; root < n; root++) {
        if (st[root] == false) {
            DFSBlk(root, 0);
        }
    }

    // After DFS if stk is not empty
    vector<PII> block;
    while (!stk.empty()) {
        PII edge = stk.top(); stk.pop();
        block.push_back(edge);
    }
    ans.push_back(block);

    // print results
    cout << "block num: " << ans.size() << '\n';
    for (auto &block: ans) {
        for (auto &edge: block) {
            if(edge.first > edge.second) swap(edge.first, edge.second);
            cout << edge.first << ' ' << edge.second << " | ";
        }
        cout << endl;
    }
    return 0;
}