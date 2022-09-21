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

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    for (int i = 0; i < MAXN; i ++) {
        adj[i].clear();
    }
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        adj[a][b] = adj[b][a] = c;
    }

    unordered_map<long long, long long> mem;
    for (int i = 0, x, y; i < Q; i++) {
        cin >> x >> y;
        x--, y--;
        // 选择度数小的节点开始遍历，复杂度低
        if (adj[x].size() > adj[y].size()) swap(x, y);

        // 判断是否计算过
        long long id = (long long)x * N + y;
        if (mem.find(id) != mem.end()) {
            cout << " " << mem[id];
            continue;
        }

        long long ans = 0;
        if (adj[x].count(y)) {
            ans += adj[x][y] * 2;
        }
        for (auto &[mid, c1] : adj[x]) {
            if (adj[mid].count(y)) {
                ans += min(c1, adj[mid][y]);
            }
        }
        
        mem[id] = ans;
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