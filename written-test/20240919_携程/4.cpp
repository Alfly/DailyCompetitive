#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 1e18;
    for (int s = 0; s + n - 1 < k; s++) {
        ll cur = 0;
        for (int i = 0, j = s; i < n; i++, j++) {
            int person = a[i], card = b[j];
            cur = max(cur, 0LL + abs(person - card) + abs(card - p));
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
// https://mp.weixin.qq.com/s/g1sE0BjWbpibm-i8NZ5CNQ
// n个员工拿的n个通行证一定是连续的，否则答案会变差(可能不变)，因此，对员工和通行证排序，然后双重遍历
/*
2 4 50
20 100
60 10 40 80
*/