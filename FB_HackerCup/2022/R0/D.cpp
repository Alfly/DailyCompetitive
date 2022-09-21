#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MAXN = 200000;
int N, M, Q;
unordered_map<int, int> adj[MAXN];
unordered_map<int, long long> big_flow[MAXN];   // 度数 > 边数的根号 的节点，二跳路径信息

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    for (int i = 0; i < MAXN; i ++) {
        adj[i].clear();
        big_flow[i].clear();
    }
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        adj[a][b] = adj[b][a] = c;
    }
    // 预先计算度数高的节点，二跳路径信息 O(M^1.5)
    for (int u = 0; u < N; u ++) { 
        if (adj[u].size() > (int)sqrt(M)) {
            for (auto &[mid, c1] : adj[u]) {
                for (auto &[v, c2] : adj[mid]) {
                    if (u != v) {
                        big_flow[u][v] = min(c1, c2);
                    }
                }
            }
        }
    }

    for (int i = 0, x, y; i < Q; i++) {
        cin >> x >> y;
        x--, y--;
        // 先处理度数大的节点，代码简洁
        if (adj[x].size() < adj[y].size()) swap(x, y);
        long long ans = 0;
        if (adj[x].count(y)) {
            ans += adj[x][y] * 2;
        }
        if (adj[x].size() > (int)sqrt(M)) {
            ans += big_flow[x][y];
        } else {
            for (auto &[mid, c1] : adj[x]) {    // O(sqrt(M))
                if (adj[mid].count(y)) {
                    ans += min(c1, adj[mid][y]);
                }
            }
        }
        cout << " " << ans;
    }
}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        cout << "Case #" << tc << ":";
        run_cases(tc);
        cout << endl;
    }
    return 0;
}