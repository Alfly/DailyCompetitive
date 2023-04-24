#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
using namespace std;

const int N = 1010;
vector<int> g[N];
int match[N];      // 右集合的匹配
bool st[N];        // 每次搜索右集合的元素不能重复

bool find(int u) {
    for (int v: g[u]) {
        if (!st[v]) {
            st[v] = true;
            if (match[v] == 0 || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    while(m --) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u); // 无向图也适用
    }

    int res = 0;
    // 依次判断左边点能否找到对应匹配
    for (int i = 1; i <= n1; i ++) {
        memset(st, false, sizeof st);
        if (find(i)) res ++;
    }
    cout << res << endl;

    return 0;
}