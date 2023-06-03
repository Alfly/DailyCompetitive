#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// void Assert(bool condition, const string& msg) {
//   if (!condition) {
//     cout << msg << endl;
//     exit(EXIT_FAILURE);
//   }
// }

void show_cycle(vector<int> cycle) {
    cout << "\ncycle path: ";
    for (int x: cycle) cout << x << " ";
    cout << '\n';
}

// find a cycle path (from any one vertex and the res path has a tail)
vector<int> find_cycle(vector<vector<int>> g, int start) {
    int n = g.size() - 1;
    vector<bool> st(n + 1, false);
    vector<int> cycle;

    function<bool(int, int)> dfs = [&](int u, int p) {
        if (st[u]) {
            cycle.push_back(u);
            return true;
        }
        st[u] = true;
        cycle.push_back(u);
        for (int v: g[u]) {
            if (v != p && dfs(v, u)) {
                return true;
            }
        }
        cycle.pop_back();
        return false;
    };
    dfs(start, -1);
    return cycle;
}

// find a cycle path
vector<int> find_cycle_v2(vector<vector<int>> g) {
    int n = g.size() - 1;
    vector<bool> st(n + 1, false);
    vector<int> parent(n + 1, -1);  // record path
    vector<int> cycle;

    function<bool(int, int)> dfs = [&](int u, int p) {
        st[u] = true;
        parent[u] = p;
        for (int v: g[u]) {
            if (!st[v]) {
                if (dfs(v, u)) return true;
            } else if (v != p) {
                // add cycle
                cycle.push_back(v);
                for (int x = u; x != v; x = parent[x]) {
                    cycle.push_back(x);
                }
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!st[i] && dfs(i, -1)) break;
    }
    if (!cycle.empty()) cycle.push_back(cycle.front());
    return cycle;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int start = 1;
    cout << "algo 1: ";
    cout << "\nfind cycle start from: " << start;
    vector<int> cycle = find_cycle(g, start);
    if (!cycle.empty()) {
        show_cycle(cycle);
    } else {
        puts("0");
    }
    
    cout << '\n';
    cout << "algo 2: ";
    vector<int> cycle2 = find_cycle_v2(g);
    if (!cycle2.empty()) {
        show_cycle(cycle2);
    } else {
        puts("0");
    }
    return 0;
}