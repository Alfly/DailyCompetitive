#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 105, MAXV = 0x3f3f3f3f;
int n, x;
int ans = MAXV;
int a[N], b[N], st[N];
unordered_map<int, bool> mp;

void dfs(int u, int k, int cnt) {
    if (k < 0) return;
    if (cnt > ans) return;
    if (k == 0 || (mp.count(k) && st[mp[k]])) {
        ans = min(ans, cnt);
    }
    for (int v = u + 1; v <= n; v++) {
        st[v] = 1;
        dfs(v, k - a[v] / 2, cnt + 1);
        st[v] = 0;
    }
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i] / 2;
        mp[b[i]] = i;
    }
    
    dfs(0, x, 0);

    if (ans == MAXV) cout << -1 << "\n";
    else cout << ans << "\n";
    
    return 0;
}
/* 回溯 超时 通过 20% */