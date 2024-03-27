#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        ll x, k, idx; char op;
        cin >> x >> op >> k;
        x--;
        k = k % n;
        if (op == 'R') {
            idx = (x + k) % n;
        } else {
            idx = (x + n - k) % n;
        }
        cout << a[idx] << endl;
    }
    return 0;
}