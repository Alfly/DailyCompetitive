#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

const int N = 100010;
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
    freopen("cutvertex_graph.txt", "r", stdin);
    int n, m, u, v;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> u >> m;
        for (int j = 0; j < m; j ++) {
            cin >> v;
            g[u].push_back(v);
        }
    }
    // init
    memset(d, 0, sizeof d);
    memset(low, 0, sizeof low);
    memset(p, -1, sizeof p);
    memset(children, 0, sizeof children);
    // dfs
    dfscv(0, 0);

    // print results
    for (int i: cutVers) cout << i << ' ';
    return 0;
}

/*
https://www.cnblogs.com/nullzx/p/7968110.html
0  :  [0, 5] [0, 1] [0, 2] [0, 6] 
1  :  [1, 0] 
2  :  [2, 0] 
3  :  [3, 4] [3, 5] 
4  :  [4, 3] [4, 6] [4, 5] 
5  :  [5, 0] [5, 4] [5, 3] 
6  :  [6, 4] [6, 7] [6, 9] [6, 0] 
7  :  [7, 8] [7, 6] 
8  :  [8, 7] 
9  :  [9, 12] [9, 10] [9, 11] [9, 6] 
10 :  [10, 9] 
11 :  [11, 12] [11, 9] 
12 :  [12, 9] [12, 11] 

13
0 4 5 1 2 6
1 1 0
2 1 0
3 2 4 5
4 3 3 6 5
5 3 0 4 3
6 4 4 7 9 0
7 2 8 6
8 1 7
9 4 12 10 11 6
10 1 9
11 2 12 9
12 2 9 11

0 6 7 9
*/