
## 学习资料
* [OI wiki](https://oi-wiki.org/graph/flow/max-flow/)
* [网络流基础讲解视频jyy](https://www.bilibili.com/video/BV1Q7411R7ie/?spm_id_from=333.999.0.0&vd_source=81814b358a165aeb95d9ec698040350e)
* [Dinic算法-Blog](https://www.cnblogs.com/SYCstudio/p/7260613.html)

## OJ
* 最大流（[Acwing412. 排水沟](https://www.acwing.com/problem/content/description/414/)）
* 最小费用最大流（洛谷P3381）

## 代码模版

### Edmonds-Karp增广路算法 $O(nm^2)$

遍历整个残余网络，找出从1~n的增广路，把最大流更新

```c++
// reference: https://oi-wiki.org/graph/flow/max-flow/

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
            int v = e.to;
            if (!f[v] && e.cap > e.flow) {
                pre[v] = ei;
                f[v] = min(f[u], e.cap - e.flow);
                q.push(v);
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
```
其他参考
```c++
//https://www.acwing.com/solution/content/155585/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 205, INF = 0x3f3f3f3f;

int n, m, h[N], e[N << 1], ne[N << 1], w[N << 1], idx, pre[N], maxflow, incf[N];
bool vis[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ; 
}

bool bfs() {
    memset(vis, false, sizeof vis);
    queue<int> que;
    vis[1] = true; que.push(1);
    incf[1] = INF;

    while (que.size()) {
        int t = que.front();
        que.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];

            if (w[i] && !vis[j]) {
                vis[j] = true;
                incf[j] = min(incf[t], w[i]);
                pre[j] = i;
                que.push(j);

                if (j == n) return 1;
            }
        }
    }

    return 0;
}

void update() { //更新最大流
    int x = n;
    while (x != 1) {
        int i = pre[x];
        w[i] -= incf[n];
        w[i ^ 1] += incf[n]; //成对变换
        x = e[i ^ 1];
    }

    maxflow += incf[n];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d %d", &m, &n);
    for (int i = 1, a, b, c; i <= m; i ++ ) {
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, 0); //建反向边
    }

    while (bfs()) update();

    printf("%d", maxflow);

    return 0;
}
```

### Dinic算法 $O(n^2m)$

在残余网络上建分层图，然后找增广路，更新答案


Dinic （+当前弧优化）
```c++
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
```

其他参考
```c++
// https://www.acwing.com/solution/content/155585/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 205, INF = 0x3f3f3f3f;

int n, m, h[N], e[N << 1], ne[N << 1], w[N << 1], idx, maxflow, dep[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ; 
}

bool bfs() { //构建分层图
    memset(dep, 0, sizeof dep);
    queue<int> que;
    que.push(1);
    dep[1] = 1;

    while (que.size()) {
        int t = que.front();
        que.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];

            if (w[i] && !dep[j]) {
                dep[j] = dep[t] + 1;
                que.push(j);

                if (j == n) return 1;
            }
        }
    }

    return 0;
}

int dinic(int u, int flow) { //Dinic求最大流
    if (u == n) return flow;

    int rest = flow;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];

        if (w[i] && dep[j] == dep[u] + 1) {
            int k = dinic(j, min(rest, w[i]));
            if (!k) dep[j] = 0;

            w[i] -= k;
            w[i ^ 1] += k;
            rest -= k;
        }
    }

    return flow - rest;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d %d", &m, &n);
    for (int i = 1, a, b, c; i <= m; i ++ ) {
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, 0); //建反向边
    }

    int flow;
    while (bfs()) 
        while (flow = dinic(1, INF)) maxflow += flow;

    printf("%d", maxflow);

    return 0;
}
```

## 其他

最小费用最大流（洛谷P3381）

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=50005,M=50000*2+5;

int h[N],e[M],ne[M],flow[M],cost[M],idx;
int n,m,S,T;
int dist[N],pre[N];
bool st[N];

void add(int a,int b,int v,int c)
{
    flow[idx]=v,cost[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool spfa()
{
    for(int i=1;i<=n;i++) dist[i]=2e9,st[i]=false,pre[i]=-1;
    dist[S]=0;
    queue<int> q;
    q.push(S);
    st[S]=true;
    while(q.size())
    {
        int x=q.front();q.pop();
        st[x]=false;
        for(int i=h[x];~i;i=ne[i])
        {
            int j=e[i];
            if(flow[i]&&dist[j]>dist[x]+cost[i])
            {
                dist[j]=dist[x]+cost[i];
                pre[j]=i;
                if(!st[j]) st[j]=true,q.push(j);
            }
        }
    }
    if(pre[T]==-1) return false;
    return true;
}

int maxflow(int &c)
{
    int res=0;
    while(spfa())
    {
        int minv=INT_MAX,cur=pre[T];
        while(cur!=-1) 
            minv=min(minv,flow[cur]),cur=pre[e[cur^1]];
        cur=pre[T];
        while(cur!=-1) 
            flow[cur]-=minv,flow[cur^1]+=minv,c+=cost[cur]*minv,cur=pre[e[cur^1]];
        res+=minv;
    }
    return res;
}

int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m>>S>>T;
    while(m--)
    {
        int x,y,z,c;
        scanf("%d%d%d%d",&x,&y,&z,&c);
        add(x,y,z,c),add(y,x,0,-c);
    }
    int c=0;
    int ans=maxflow(c);
    cout<<ans<<' '<<c<<endl;
    return 0;    
}
```