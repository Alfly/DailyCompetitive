// 用一个变量 weight 替代 cap 和 flow (w = c - f)；
// incf[j] 不重置，添加 st[] 用于去重

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
int n, m, s, t, maxFlow;
bool st[N];
int f[N], pre[N];   // f[i]: max flow from pre vertex to v_i
                    // pre[i]: pre edge index for v_i

void init() {
    for (int i = 0; i < n; i++) g[i].clear();
    edges.clear();
}

void addEdge(int u, int v, int c) {
    edges.push_back(Edge(u, v, c)); g[u].push_back(edges.size() - 1);
    edges.push_back(Edge(v, u, 0)); g[v].push_back(edges.size() - 1);
}

bool findPath_bfs() {
    memset(st, false, sizeof st);
    queue<int> q; q.push(s); st[s] = true;
    f[s] = INF;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int ei: g[u]) {
            Edge &e = edges[ei];
            int v = e.to;   // e:[u->v]
            if (!st[v] && e.weight) {
                st[v] = true;
                pre[v] = ei;
                f[v] = min(f[u], e.weight);
                q.push(v);
                
                if (v == t) return true;
            }
        }
        // if (f[t]) return true;  // 此写法 f[] 没有重置，不能再这里判断
    }
    return false;   // 汇点没有接受到流，说明源点和汇点不在同一个连通分量上
}

void update() {
     // 通过 u 追寻 BFS 过程中 s -> t 的路径
    for (int u = t; u != s; u = edges[pre[u]].from) {                                
        edges[pre[u]].weight -= f[t];     // - 路径上边的 flow 值
        edges[pre[u] ^ 1].weight += f[t]; // + 反向路径的 flow 值
    }
    maxFlow += f[t];
}

int main()
{
    cin >> m >> n;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    s = 1, t = n;
    maxFlow = 0;
    while (findPath_bfs()) {
        update();
    }
    cout << maxFlow << endl;

    return 0;
}