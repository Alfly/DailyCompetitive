#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using ll = long long;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        ll sum = 0L;
        unordered_map<ll, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += (ll) a[i];
            cnt[a[i] * n]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x = a[i] * n, y = 2 * sum - x;
            if (cnt.count(y)) {
                ans += cnt[y] - (x == y);
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}