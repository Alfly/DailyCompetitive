#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
ll a[N];
int n, q;

// f(l, r) = a_l | a_l+1 | ... | a_r
map<pair<int, int>, ll> mp;

void preget(int l, int r) {
    for (int i = l; i <= r; i++) {
        ll res = 0;
        for (int j = i; j <= r; j++) {
            res |= a[j];
            mp[{i, j}] = res;
            // printf("[%d, %d]: %lld\n", i, j, mp[{i, j}]);
        }
    }
}

// O(n)
ll get(int l, int r) {
    ll res = 0;
    for (int i = l; i <= r; i++) {
        res |= a[i];
    }
    return res;
    // return mp[{l, r}];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l, r, minidx = 0x3f3f3f3f, maxidx = 0;
    ll k;
    vector<vector<ll>> qs(q);
    for (int t = 0; t < q; t++) {
        cin >> l >> r >> k;
        qs[t] = {l, r, k};
        minidx = min(minidx, l);
        minidx = min(minidx, r);
        maxidx = max(maxidx, l);
        maxidx = max(maxidx, r);
    }

    // preget(minidx, maxidx);

    for (auto &q : qs) {
        int l = q[0], r = q[1], k = q[2];
        int i = l, j = r;
        while (i < j) {
            int mid = (i + j) >> 1;
            // printf("l: %d, mid: %d\n", l, mid);
            if (get(l, mid) >= k) j = mid;
            else i = mid + 1;
        }
        if (get(l, j) == k) cout << j << endl;
        else cout << -1 << endl;
    }

    return 0;
}

/* 
get() 复杂度 O(n) 整体 O(q * nlogn)  超时 通过 66%
 */