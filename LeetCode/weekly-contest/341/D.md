## [2646. 最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/)

> Tag: 树形DP, Tarjan 离线 LCA 树上差分, TODO

[solution](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/solution/lei-si-da-jia-jie-she-iii-pythonjavacgo-4k3wq/)

### 方法一：暴力 DFS
* 时间复杂度: $O(nm)$ ，其中 m 为 trips 的长度
* 空间复杂度: $O(n)$
```c++
class Solution {
public:
    using PII = pair<int, int>;
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> cnt(n, 0);
        for (auto &t: trips) {
            int start = t[0], end = t[1];
            function <bool (int, int)> dfs = [&](int u, int father) -> bool {
                if (u == end) {
                    cnt[u] ++;
                    return true;
                }
                for (int v: g[u]) {
                    if (v != father && dfs(v, u)) {
                        cnt[u] ++;
                        return true;
                    }
                }
                return false;
            };
            dfs(start, -1);
        }

        function<PII (int, int)> dfs = [&](int u, int father) -> PII {
            int not_halve = price[u] * cnt[u];
            int halve = not_halve / 2;
            for (int v: g[u]) {
                if (v == father) continue;
                auto [nh, h] = dfs(v, u);
                not_halve += min(nh, h);
                halve += nh;
            }
            return {not_halve, halve};
        };

        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};
```

### 方法二：Tarjan 离线 LCA + 树上差分
* 时间复杂度: $O(n+m*a)$, 其中 m 为 trips 的长度, a 为并查集常数[可视作O(1)]
* 空间复杂度: $O(n+m)$
```c++
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<vector<int>> qs(n);
        for (auto &t: trips) {
            int a = t[0], b = t[1];
            qs[a].push_back(b);
            if (a != b) qs[b].push_back(a);
        }

        // union-find
        int pa[n];
        for (int i = 0; i < n; i ++) pa[i] = i;
        function<int (int)> find = [&] (int x) -> int {
            return pa[x] == x ? x : pa[x] = find(pa[x]);
        };

        int diff[n], father[n], st[n];
        memset(diff, 0, sizeof diff);
        memset(st, 0, sizeof st);
        function<void (int, int)> tarjan = [&](int u, int fa) {
            father[u] = fa;
            st[u] = 1;
            for (int v: g[u]) {
                if (st[v] == 0) {
                    tarjan(v, u);
                    pa[v] = u;  // 相当于把 v 的子树节点全部 merge 到 u
                }
            }
            for (int v: qs[u]) {
                // st[v] == 2 意味着 v 所在子树已经遍历完
                // 也就意味着 v 已经 merge 到它和 u 的 lca 上了
                if (v == u || st[v] == 2) {
                    diff[u] ++, diff[v] ++;
                    int lca = find(v);
                    diff[lca] --;
                    int f = father[lca];
                    if (f >= 0) diff[f] --;
                }
            }
            st[u] = 2;
        };
        tarjan(0, -1);

        function<tuple<int, int, int> (int, int)> dfs = [&](int u, int father) -> tuple<int, int, int> {
            int not_halve = 0, halve = 0, cnt = diff[u];
            for (int v: g[u]) {
                if (v == father) continue;
                auto [nh, h, c] = dfs(v, u);
                not_halve += min(nh, h);
                halve += nh;
                cnt += c;
            }
            not_halve += price[u] * cnt;
            halve += price[u] * cnt / 2;
            return {not_halve, halve, cnt};
        };

        auto [nh, h, _] = dfs(0, -1);
        return min(nh, h);
    }
};
```