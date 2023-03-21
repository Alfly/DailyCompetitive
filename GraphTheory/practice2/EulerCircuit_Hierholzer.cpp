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
int indegree[N], outdegree[N];
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

int isEulerianDirected(int n) {
    if (!isConnected(n)) return false;
    int startNodes = 0, endNodes = 0;
    for (int i = 0; i < n; i ++) {
        int delta = outdegree[i] - indegree[i];
        if (delta > 1 || delta < -1) return 0;
        else if (delta == 1) startNodes ++;
        else if (delta == -1) endNodes ++;
    }
    if (startNodes == 0 && endNodes == 0) return 1;
    if (startNodes == 1 && endNodes == 1) return 2;
    return 0;
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
        outdegree[a] ++, indegree[b] ++;
    }
    if (isEulerianDirected(n) == 0) {
        cout << "No Eulerian Existed!" << endl;
        return 0;
    }

    // sort 
    // TODO reverse??? 
    for (int i = 0; i < n; i ++) {
        if (!g[i].empty()) {
            sort(g[i].begin(), g[i].end());
        }
    }

    // choose start u-v trail
    int start = 0;
    for (int i = n - 1; i >= 0; i --) {
        if (outdegree[i] - indegree[i] == 1) {
            start = i;
            break;
        } else if (outdegree[i] > 0) {  // Start at a node with an outgoing edge.
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