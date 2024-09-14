/**
 * u到v路径的异或和 = u到root路径的异或和 xor v到root路径的异或和
*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

typedef pair<int, long long> PILL;
typedef long long LL;

const int N = 1e5+10;
vector<PILL> g[N];
LL d[N];
unordered_map<LL, int> cnt;

void dfs(int u) {
    for (auto [v, w]: g[u]) {
        if (d[v] != -1) continue;
        d[v] = d[u] ^ w;
        cnt[d[v]]++;
        dfs(v);
    }
}

int main() {
    int n, q; cin >> n >> q;
    int root = 1;
    d[root] = 0;
    for (int i = 2; i <= n; i++) d[i] = -1;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(root);
    cnt[0]++;

    while (q--) {
        int u;
        long long k;
        cin >> u >> k;
        cout << cnt[d[u] ^ k] << endl;
    }
    return 0;
}