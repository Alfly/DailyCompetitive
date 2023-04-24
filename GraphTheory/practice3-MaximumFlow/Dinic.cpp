#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

struct Edge {
    int from, to, weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};

vector<Edge> edges;
vector<int> g[N];
vector<int> cur[N]; // 当前弧优化
int n, m, s, t, maxFlow;
int depth[N];

void init() {
    for (int i = 0; i < n; i++) g[i].clear();
    edges.clear();
}

void addEdge(int u, int v, int c) {
    edges.push_back(Edge(u, v, c)); g[u].push_back(edges.size() - 1);
    edges.push_back(Edge(v, u, 0)); g[v].push_back(edges.size() - 1);
}

bool getDepth_bfs() {
    memset(depth, 0, sizeof depth);
    queue<int> q; q.push(s);
    depth[s] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int ei: g[u]) {
            Edge &e = edges[ei];
            int v = e.to;   // e:[u->v]
            if (!depth[v] && e.weight) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    if (!depth[t]) return false;
    return true;
}

int findPath_dfs(int u, int flow) {
    if (u == t || flow == 0) return flow;
    int rest = flow;
    // for (int ei: g[u]) {
    for (int i = 0; i < cur[u].size(); i ++) {
        int ei = cur[u][i];
        Edge &e = edges[ei];
        int v = e.to;   // e:[u->v]
        if (depth[v] == depth[u] + 1 && e.weight) {
            int k = findPath_dfs(v, min(rest, e.weight));
            if (k > 0) {
                edges[ei].weight -= k;
                edges[ei ^ 1].weight += k;
                rest -= k;
                if (rest == 0) return flow;
            }
        }
        if (i + 1 < cur[u].size()) cur[u][i] = cur[u][i+1]; // 当前弧优化
    }
    return flow - rest;
}

int main() {
    cin >> m >> n;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    s = 1, t = n;
    maxFlow = 0;
    while (getDepth_bfs()) {
        for (int i = 0; i < N; i ++) cur[i] = g[i];
        maxFlow += findPath_dfs(s, INF);
    }
    cout << maxFlow << endl;

    return 0;
}