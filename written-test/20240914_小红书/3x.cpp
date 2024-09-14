#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

typedef pair<int, int> PII;

int ans = 0;
map<PII, long long> weight;
vector<vector<int>> g;

void dfs(int u, long long k, long long cur, int parent) {
    for (int v: g[u]) {
        if (v == parent) continue;
        if ((cur ^ weight[{u, v}]) == k) ans++;
        dfs(v, k, cur ^ weight[{u, v}], u);
    }
}

int main() {
    int n, q; cin >> n >> q;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        weight[{u, v}] = w, weight[{v, u}] = w;
    }
    while (q--) {
        int u;
        long long k;
        cin >> u >> k;
        
        ans = 0;
        dfs(u, k, 0, -1);

        if (k == 0) ans++;
        cout << ans << endl;
    }
    return 0;
}
/**
 * pass 20% 暴力
 * /