#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
int p[N];

int Find(int x) {
    if (p[x] != x) {
        p[x] = Find(p[x]);
    }
    return p[x];
}

int main() {
    int n, m;
    ll total = 0;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        total += w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    int block = n;
    for (auto &edge: edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        int a = Find(u), b = Find(v);
        if (a == b) continue;
        p[a] = b;
        total -= w;
        block--;
        if (block == 2) break;
    }
    if (block >= 3) total = -1;
    cout << total << endl;

    return 0;
}