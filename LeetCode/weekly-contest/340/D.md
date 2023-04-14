## [2617. 网格图中最少访问的格子数](https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/)

> Tag: 优先队列，DP 单调栈 二分，线段树

[题解1](https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/solution/dan-diao-zhan-you-hua-dp-by-endlesscheng-mc50/), 
[题解2](https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/solution/m-n-ge-you-xian-dui-lie-by-zerotrac2-d9rg/)


### 方法零：暴力（超时）
* 时间复杂度: $O(mn*(m+n))$
* 空间复杂度: $O(mn)$
* 1050 / 1069 个通过测试用例
```c++
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector f(m, vector(n, inf));
        f[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int minv = inf;
                for (int k = i + 1; k < m && k <= i + grid[i][j]; k ++) minv = min(minv, f[k][j]);
                for (int k = j + 1; k < n && k <= j + grid[i][j]; k ++) minv = min(minv, f[i][k]);
                if (minv != inf) f[i][j] = minv +  1;
            }
        }
        return f[0][0] > m * n ? -1 : f[0][0];
    }
};
```

### 方法一：优先队列
对于每一列都维护一个优先队列。第 j 个优先队列存储的是所有位于第 j 列的位置，优先队列中存储两个值，第一个值为到达 (i, j) 最少的移动次数，作为比较的关键字；第二个值为下标。

每一行也同样处理。

* 时间复杂度: $O(mn*(logm+logn))$
* 空间复杂度: $O(mn)$
```c++
class Solution {
private:
    using PII = pair<int, int>; // [dist, index]
    using MinHeap = priority_queue<PII, vector<PII>, greater<PII>>;   // min heap
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector dist(m, vector(n, -1));
        dist[0][0] = 1;    // 当前走的步数(距离)
        vector<MinHeap> row(m), col(n);

        auto update = [](int& x, int y) {
            if (x == -1 || x > y) {
                x = y;
            }
        };

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                // row
                while (!row[i].empty() && row[i].top().second + grid[i][row[i].top().second] < j) {
                    row[i].pop();
                }
                if (!row[i].empty()) {
                    update(dist[i][j], dist[i][row[i].top().second] + 1);
                }
                // col
                while (!col[j].empty() && col[j].top().second + grid[col[j].top().second][j] < i) {
                    col[j].pop();
                }
                if (!col[j].empty()) {
                    update(dist[i][j], dist[col[j].top().second][j] + 1);
                }

                if (dist[i][j] != -1) {
                    row[i].emplace(dist[i][j], j);
                    col[j].emplace(dist[i][j], i);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```

### 方法二：DP 单调栈 二分
* 时间复杂度: $O(mn*(logm+logn))$
* 空间复杂度: $O(mn)$
- [ ] 优化：取了下标的相反数放入单调栈，所以不需要二分了，直接单调栈就行
```c++
class Solution {
private:
    using PII = pair<int, int>; // [dist, index]
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mn;
        vector<vector<PII>> col_st(n); // 每列的单调栈
        for (int i = m - 1; i >= 0; i --) {
            vector<PII> st;
            for (int j = n - 1; j >= 0; j --) {
                auto &st2 = col_st[j];
                mn = INT_MAX;
                if (i == m - 1 && j == n - 1) mn = 0;   // 终点
                else if (int g = grid[i][j]; g) {
                    // 单调栈上二分
                    auto it = lower_bound(st.begin(), st.end(), j + g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < st.end()) mn = min(mn, it->first);
                    it = lower_bound(st2.begin(), st2.end(), i + g, [](const auto &a, const int b){
                        return a.second > b;
                    });
                    if (it < st2.end()) mn = min(mn, it->first);
                }
                if (mn == INT_MAX) continue;

                mn += 1; // (i, j)
                // insert
                while (!st.empty() && mn <= st.back().first) {
                    st.pop_back();
                }
                st.emplace_back(mn, j);
                while (!st2.empty() && mn <= st2.back().first) {
                    st2.pop_back();
                }
                st2.emplace_back(mn, i);
            }
        }
        return mn < INT_MAX ? mn : -1;
    }
};
```

### 方法三：线段树 todo

有「区间查询」、「单点更新」这两个操作，我们可以用线段树来优化
* 时间复杂度: $O()$
* 空间复杂度: $O()$

H-version
```c++
constexpr int inf = 1000000000;
struct bit {
    int n;
    vector<int> v;
    bit(int n) : n(n), v(n, inf) {}
    void update(int x, int y) {
        x += 1;
        for (; x <= n; x += x & -x) {
            v[x - 1] = min(v[x - 1], y);
        }
    }
    int query(int x) {
        x = min(x, n - 1);
        int y = inf;
        x += 1;
        for (; x; x -= x & -x) {
            y = min(y, v[x - 1]);
        }
        return y;
    }
};
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector dp(n, vector<int>(m, inf));
        vector<bit> r(n, m), c(m, n);
        dp[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = m - 1; j >= 0; j -= 1) {
                if (grid[i][j] > 0) {
                    dp[i][j] = min(r[i].query(j + grid[i][j]), c[j].query(i + grid[i][j])) + 1;
                }
                if (dp[i][j] <= n * m) {
                    r[i].update(j, dp[i][j]);
                    c[j].update(i, dp[i][j]);
                }
            }
        }
        return dp[0][0] > n * m ? -1 : dp[0][0];
    }
};
```