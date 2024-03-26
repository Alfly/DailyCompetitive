#include <iostream>
#include <cstring>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 3e5 + 10;
int cnt[N];
int st[N];
vector<int> child[N];

void dfs(int u, int idx) {
    if (st[u] != idx) {
        st[u] = idx;
        cnt[u]++;
    }
    for (int v : child[u]) {
        dfs(v, idx);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        child[u].push_back(v);
    }

    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    int dfs_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == 0) {
            dfs_cnt++;
            dfs(i, dfs_cnt);
            // // 
            // bool flag = false;
            // for (int i = 1; i <= n; i++) {
            //     if (cnt[i] == dfs_cnt) flag = true;
            // }
            // if (!flag) {
            //     cout << 0;
            //     return 0;
            // }
        }
    }

    // for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == dfs_cnt) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}

/* 
通过 10%，可用基于入度的方法分别统计可访问到 和 可被访问的节点数量，可能需要 bitset 优化
 */