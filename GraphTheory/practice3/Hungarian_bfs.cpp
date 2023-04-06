#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

const int N = 510;
vector<int> g[N];
bool st[N];
int matchLeft[N], matchRight[N]; // 左集合点的匹配点  右集合点的匹配点 可以合成一个
int pre[N]; // 存储路径，更改匹配边时要用到
int n1, n2, m;

bool bfs(int i) {
    if (matchLeft[i] != -1) return false;
    queue<int> Q;
    Q.push(i);
    pre[i] = -1;        // start from i
    bool flag = false;  // 是否找到增广路
    while (!Q.empty() && !flag) {
        int u = Q.front(); Q.pop();
        for (int v: g[u]) {
            if (!st[v]) {
                st[v] = true;
                if (matchRight[v] >= 0) {   // match point
                    Q.push(matchRight[v]);
                    pre[matchRight[v]] = u;
                } else {                    // 找到未匹配点，增广路
                    flag = true;
                    int d = u, e = v;
                    while (d != -1) {       // 更改路径
                        int tmp = matchLeft[d];
                        matchLeft[d] = e;
                        matchRight[e] = d;
                        d = pre[d];
                        e = tmp;
                    }
                    break;
                }
            }
        }
    }
    return flag;
}

int main() {
    cin >> n1 >> n2 >> m;
    set<int> R;
    while(m --) {
        int u, v;
        cin >> u >> v;
        R.insert(v);
        g[u].push_back(v);
        // g[v].push_back(u); // 只能有向图，无向图此解法会多解
    }

    int res = 0;
    memset(matchLeft, -1, sizeof matchLeft);
    memset(matchRight, -1, sizeof matchRight);
    for (int i = 1; i <= n1; i ++) {
        memset(st, false, sizeof st);
        if (bfs(i)) {
            res ++;
            cout << "ok at: " << i << endl;
        }
    }
    cout << res << endl;

    // output match
    for (int u: R) {
        if (matchRight[u]) cout << matchRight[u] << ' ' << u << endl;
    }

    return 0;
}

/* 
    Hungarian in BFS
    https://blog.csdn.net/zyy_1998/article/details/77652029
    https://www.renfei.org/blog/bipartite-matching.html
 */