#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }
    vector<int> cap(n);
    for (int i = 0; i < n; i++) {
        cin >> cap[i];
    }
    int x, p;
    cin >> x >> p;

    vector<int> d(n, INF);
    d[x] = 0;

    // 优先队列
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, x);

    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (du > d[u]) {
            continue;
        }
        for (int v = 0; v < n; v++) {
            if (d[u] + dist[u][v] < d[v]) {
                d[v] = d[u] + dist[u][v];
                q.emplace(d[v], v);
            }
        }
    }

    // dist cap index 三层排序 (cap 没有必要)
    vector<tuple<int, int, int>> regions;
    for (int i = 0; i < n; i++) {
        if (i != x) {
            regions.emplace_back(d[i], cap[i], i);
        }
    }
    sort(regions.begin(), regions.end());

    vector<int> ans;
    int total_cap = 0;
    for (auto [di, ci, i] : regions) {
        if (total_cap >= p) {
            break;
        }
        ans.push_back(i);
        total_cap += ci;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

/* 

堆优化：https://mp.weixin.qq.com/s/eikGC_XdEh9HCBbaqaW5Iw
 
 */