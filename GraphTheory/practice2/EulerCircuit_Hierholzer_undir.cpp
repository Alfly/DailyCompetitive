#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string.h>
using namespace std;

const int N = 100010;
vector<int> g[N];
bool st[N];
int degree[N];
vector<int> curr_path;
vector<int> ans;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int u) {
    st[u] = true;
    for (int v : g[u]) {
        if (st[v] == false) {
            dfs(v);
        }
    }
}

// check if is connected except zero-degree vertice
bool isConnected(int n) {
    memset(st, 0, sizeof st);
    int root;
    for (root = 0; root < n; root ++) {
        if (g[root].size() != 0) break;
    }
    if (root == n) return true;
    dfs(root);
    for (int i = 0; i < n; i ++) {
        if (st[i] == false && g[i].size() != 0) return false;
    }
    return true;
}

int isEulerianUndirected(int n) {
    if (!isConnected(n)) return false;
    int odd_num = 0;
    for (int i = 0; i < n; i ++) {
        if (g[i].size() & 1) odd_num ++;
    }
    if (odd_num > 2) return 0;
    // odd_num == 0 or 2
    return odd_num == 0 ? 1 : 2;
}

void Hierholzer(int start) {
    curr_path.push_back(start);
    while (!curr_path.empty()) { 
        int u = curr_path.back();
        if (g[u].size() > 0) {
            int v = g[u].back();
            g[u].pop_back();
            // Push the new vertex to the stack
            curr_path.push_back(v);
        } else {
            // back-track to find remaining circuit
            ans.push_back(curr_path.back());
            curr_path.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a] ++, degree[b] ++;
    }
    if (isEulerianUndirected(n) == 0) {
        cout << "No Eulerian Existed!" << endl;
        return 0;
    }

    // sort
    for (int i = 1; i <= n; i ++) {
        if (!g[i].empty()) {
            sort(g[i].begin(), g[i].end());
        }
    }

    // choose start u-v trail
    int start = 0;
    for (int i = 1; i <= n; i ++) {
        if (degree[start] == 0 && degree[i] != 0) {    // 非孤立点
            start = i;
        } else if (!(degree[start] & 1) && (degree[i] & 1)) {  // 度数为奇
            start = i;
        }
    }
    cout << "start at: " << start << endl;

    Hierholzer(start);

    for (int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i];
        if (i) cout << " ";
    }
    cout << endl;
    return 0;
}
/*
https://oi-wiki.org/graph/euler/


*/