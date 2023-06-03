#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

const int N = 110;
vector<int> g[N];
bool st[N], get_cycle;
int n, m;
vector<int> cycle_path;     // algo starts from a cycle


inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void show_cycle_path() {
    cout << "\ncycle path: ";
    for (int x: cycle_path) cout << x << " ";
    cout << '\n';
}

// find a cycle path
bool find_cycle(int u, int p) {
    cout << "\np: " << p << " u: " << u;
    if (st[u]) {
        cycle_path.push_back(u);
        return true;
    }
    st[u] = true;
    cycle_path.push_back(u);
    for (int v: g[u]) {
        if (v != p && find_cycle(v, u)) {
            return true;
        }
    }
    cycle_path.pop_back();
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    memset(st, false, sizeof st);
    int start = 3;
    cout << "find cycle start from: " << start;
    find_cycle(start, 0);
    show_cycle_path();

    cout << endl;
    return 0;
}