#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f = 0) : from(u), to(v), cap(c), flow(f) {}
};

vector<Edge> edges;
vector<int> g[N];
int n, m, s, t, maxFlow;
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

bool bfs() {
    memset(f, 0, sizeof f);
    queue<int> q; q.push(s);
    f[s] = INF;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int ei: g[u]) {
            Edge &e = edges[ei];
            int v = e.to;   // e:[u->v]
            if (!f[v] && e.cap > e.flow) {
                pre[v] = ei;
                f[v] = min(f[u], e.cap - e.flow);
                q.push(v);
                // if (v == t) return true; // 两种判断方法均可
            }
        }
        if (f[t]) return true;  // 如果汇点接受到了流，就退出 BFS
    }
    return false;   // 汇点没有接受到流，说明源点和汇点不在同一个连通分量上
}

void update() {
     // 通过 u 追寻 BFS 过程中 s -> t 的路径
    for (int u = t; u != s; u = edges[pre[u]].from) {                                
        edges[pre[u]].flow += f[t];     // 增加路径上边的 flow 值
        edges[pre[u] ^ 1].flow -= f[t]; // 减小反向路径的 flow 值
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
    while (bfs()) {
        update();
    }
    cout << maxFlow << endl;

    return 0;
}

/*

最大流（[Acwing412. 排水沟](https://www.acwing.com/problem/content/description/414/)）

 */
