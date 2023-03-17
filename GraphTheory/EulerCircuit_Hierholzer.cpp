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
int degree[N];
stack<int> ans;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void Hierholzer(int start) {

}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a] ++, degree[b] ++;
    }
    // sort
    for (int i = 1; i <= n; i ++) {
        if (!g[i].empty()) {
            sort(g[i].begin(), g[i].end());
        }
    }

    // ????
    for (int i = 1; i <= n; i ++) {
        
    }

    // choose start u-v trail
    int start = 0;
    for (int i = 1; i <= n; i ++) {
        if (degree[start] == 0 && degree[i] != 0) {    // 非孤立点
            start = i;
        } else if (!(degree[start] & 1) && (degree[i] & 1)) {  // 度数为奇
            start = i;
        }
    }

    Hierholzer(start);

    while (!ans.empty()) {
        cout << ans.top() << ' '; ans.pop();
    }
    return 0;
}
/*
https://oi-wiki.org/graph/euler/


*/