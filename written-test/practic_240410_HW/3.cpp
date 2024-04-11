#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 25;
int g[N][N];
bool st[N];
int n;
int maxcnt = 0, minx = -1;
int cnt = 0;

// void dfs(int u, int p) {
//     if (st[u]) return;
//     st[u] = true;
//     cnt++;
//     for (int v = 0; v < n; v++) {
//         if (v == u) continue;
//         if (g[u][v] > p || g[u][v] == 0) continue;
//         dfs(v, g[u][v]);
//     }
// }

int dfs(int u, int p) {
    if (st[u]) return 0;
    st[u] = true;
    int num = 0;
    for (int v = 0; v < n; v++) {
        if (v == u) continue;
        if (g[u][v] > p || g[u][v] == 0) continue;
        num += dfs(v, g[u][v]);
    }
    return num + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> ts;
    int t;
    while (cin >> t) {
        ts.push_back(t);   
    }
    sort(ts.begin(), ts.end());

    for (int x: ts) {
        memset(st, 0, sizeof st);

        // cnt = 0;
        // dfs(x, 10);

        cnt = dfs(x, 10);

        // cout << cnt << endl;

        if (cnt > maxcnt) {
            maxcnt = cnt;
            minx = x;
        }
    }
    cout << minx << endl;

    return 0;
}