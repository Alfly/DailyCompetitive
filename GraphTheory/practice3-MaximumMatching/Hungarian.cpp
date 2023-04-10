#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
vector<int> L, R;
int color[N];
bool st[N];
int match[N];

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

bool find(int u) {
    for (int v: g[u]) {
        if (!st[v]) {
            st[v] = true;
            if (match[v] == 0 || find(match[v])) {
                match[v] = u;
                // match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int Hungarian() {
    int res = 0;
    memset(match, 0, sizeof match);
    for (int i = 0; i < L.size(); i ++) {
        // if (match[L[i]] == 0) {}
        memset(st, false, sizeof st);
        int u = L[i];
        if (find(u)) res ++;
    }
    return res;
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

    cout << "Maximum matching count: " << Hungarian() << endl;

    // output match
    for (int i = 0; i < R.size(); i ++) {
        int u = R[i];
        if (match[u]) cout << match[u] << ' ' << u << endl;
    }
    // for (int i = 0; i < L.size(); i ++) {
    //     int u = L[i];
    //     if (match[u]) cout << u << ' ' <<  match[u] << endl;
    // }

    return 0;
}

/* 
    blog:
    https://zhuanlan.zhihu.com/p/96229700
    https://fangkaipeng.com/?p=115
    oj:
    http://poj.org/problem?id=1469
    https://vjudge.net/problem/HDU-2444
    https://www.acwing.com/problem/content/description/863/
 */