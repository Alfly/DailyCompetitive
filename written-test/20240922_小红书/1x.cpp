#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n; 
ll sum = 0;
ll minv = 2e6+10;
vector<int> a;
vector<bool> st;

void dfs(int u, ll cur) {
    if (u == n) return;
    if (abs(sum - 2 * cur) > minv) return;
    minv = min(minv, abs(sum - 2 * cur));

    for (int i = 0; i < n; i++) {
        if (st[i]) continue;
        st[i] = true;
        dfs(u + 1, cur + a[i]);
        st[i] = false;
    }
}

int main() {
    cin >> n;
    a.resize(n), st.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    dfs(0, 0);
    cout << minv << endl;

    return 0;
}
// pass 85%