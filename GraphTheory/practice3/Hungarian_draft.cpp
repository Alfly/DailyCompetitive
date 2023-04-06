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
int color[N];
vector<int> L, R;
bool st[N], saturated[N];
set<PII> M;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool dye(int u, int c) {
    if (color[u] != 0) return color[u] == c;
    color[u] = c;
    // two parts: L and R
    if (c > 0) L.push_back(u);
    else R.push_back(u);
    // dfs
    for (int v: g[u]) {
        if (!dye(v, -c)) return false;
    }
    return true;
}

bool isBipartite(int n) {    
    // init
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n; i ++) {
        if (!color[i] && !dye(i, 1)) {
            return false;
        }
    }
    return true;
}

set<PII> symmetric_difference(set<PII> A, set<PII> B) {
    set<PII> res, U, I;
    for (auto a: A) {
        U.insert(a);
        if (B.count(a)) I.insert(a);
    }
    for (auto b: B) U.insert(b);
    for (auto x: U) {
        if (I.count(x) == 0) res.insert(x);
    }
    return res;
}

void DFSAP(int u, int root, vector<int>& path) {
    st[u] = true;
    path.push_back(u);
    if (!saturated[u] && u != root) {
        return;
    }
    for (int v: g[u]) {
        // TODO - check alternating path
        if (!st[v] && 1) {
            DFSAP(v, root, path);
            if (!path.empty()) {
                return;
            }
        }
    }
    path.clear();
}

void Hungarian() {
    vector<int> P;
    memset(saturated, 0, sizeof saturated);
    do {
        memset(st, 0, sizeof st);
        for (int i = 0; i < L.size(); i ++) {
            int u = L[i];
            if (!st[u] && !saturated[u]) {
                DFSAP(u, u, P);
                if (!P.empty()) {
                    set<PII> edges;
                    for (int j = 1; j < P.size(); j ++) {
                        edges.insert(make_pair(P[j-1], P[j]));
                    }
                    M = symmetric_difference(edges, M);
                    // saturated vertex
                    memset(saturated, 0, sizeof saturated);
                    for (auto edge: M) {
                        saturated[edge.first] = saturated[edge.second] = 1;
                    }
                    break;
                }
            }
        }
    } while (!P.empty());
    // output M
    for (auto edge: M) {
        cout << edge.first << ' ' << edge.second << '|';
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

    if (!isBipartite(n)) {
        cout << "The given graph is not Bipartite!" << endl;
        return 0;
    }

    Hungarian();

    return 0;
}

/* 
    https://zhuanlan.zhihu.com/p/96229700
 
 */