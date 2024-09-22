#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll minv = LONG_MAX;
    int minidx = -1;
    for (int i = 0; i < m; i++) {
        ll dist = 0;
        for (int j = 0; j < m; j++) {
            dist += (ll) min(abs(a[i] - a[j]), abs(a[j] + n - a[i]));
            if (dist > minv) break;
        }
        // cout << dist << endl;
        if (dist < minv) {
            minv = dist;
            minidx = a[i];
        }
    }
    cout << minidx << endl;
    return 0;
}
//pass %27 暴力