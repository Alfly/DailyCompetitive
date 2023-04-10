#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

const int N = 10010;
vector<int> g[N];
int color[N];

bool dye(int u, int c) {
    if (color[u] != 0) return color[u] == c;
    color[u] = c;
    // dfs
    for (int v: g[u]) {
        if (!dye(v, -c)) return false;
    }
    return true;
}

bool isBipartite(int n) {
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n; i ++) {
        if (!color[i] && !dye(i, 1)) {
            return false;
        }
    }
    return true;
}

bool dye2(int u, int c) {
    color[u] = c;
    for (int v: g[u]) {
        if (!color[v]) {
            // dye2(v, 3-c); // wrong
            if (!dye2(v, 3-c)) return false;
        } else {
            if (color[u] == color[v]) return false;
        }
    }
    return true;
}

bool isBipartite2(int n) {
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n; i ++) {
        if (!color[i]) {
            if (!dye2(i, 1)) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m --) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (isBipartite(n)) puts("1:Yes");
    else puts("1:No");

    if (isBipartite2(n)) puts("2:Yes");
    else puts("2:No");

    return 0;
}

/* 
https://www.acwing.com/file_system/file/content/whole/index/content/55755/
 */
