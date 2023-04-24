#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <climits>

using namespace std;
using LL = long long;

const int N = 210;
const LL INF = LLONG_MAX;

struct Edge {
    int from, to, weight;
    Edge(int u, int v, LL w) : from(u), to(v), weight(w) {}
};

vector<Edge> edges;
vector<int> g[N];
vector<int> cur[N];
int n, m, s, t;
LL maxFlow;
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

                // if (v == t) return true;
            }
        }
    }
    if (!depth[t]) return false;
    return true;
}

LL findPath_dfs(int u, LL flow) {
    if (u == t || flow == 0) return flow;
    LL rest = flow;
    // for (int ei: g[u]) {
    for (int i = 0; i < cur[u].size(); i ++) {
        int ei = cur[u][i];
        Edge &e = edges[ei];
        int v = e.to;   // e:[u->v]
        if (depth[v] == depth[u] + 1 && e.weight) {
            LL minv = rest;
            if (e.weight < minv) minv = e.weight;
            LL k = findPath_dfs(v, minv);
            if (k > 0) {    // 增广成功
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
    cin >> n >> m >> s >> t;
    while (m--) {
        int a, b; LL c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    maxFlow = 0;
    while (getDepth_bfs()) {
        for (int i = 0; i < N; i ++) cur[i] = g[i];
        maxFlow += findPath_dfs(s, INF);
    }
    cout << maxFlow << endl;

    return 0;
}