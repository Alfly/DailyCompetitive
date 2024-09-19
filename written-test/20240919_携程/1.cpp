#include <iostream>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        long long n, m, k;
        cin >> n >> m >> k;
        long long ans = 0;
        if (k <= n - 1) {
            ans += m * (1 + k) * k / 2;
        } else if (k <= n - 1 + m - 1) {
            ans += m * n * (n - 1) / 2;
            k -= n - 1;
            ans += (n - 1) * m * k + (1 + k) * k / 2;
        } else {
            ans += m * n * (n - 1) / 2;
            k -= n - 1;
            ans += (n - 1) * m * (m - 1) + m * (m - 1) / 2;
            k -= m - 1;
            long long a = n * m - 1, b = a - 1;
            long long cnt = k / 2, last = k % 2;
            ans += (a + b) * cnt;
            if (last) ans += b;
        }
        cout << ans << endl;
    }
    return 0;
}