#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 2e5+10;
LL a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n, greater<int>());

        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        
        LL ans;
        if (m == 0) {
            ans = a[n - 1];
        } else {
            ans = a[n - 1] * (-k);  // 初值保证最小
            // [(delete) 0, i - 1][(* -k) i, i + m - 1][i + m, n - 1]
            for (int i = 0; i <= d; i++) {
                LL pre = (i > 0) ? a[i - 1] : 0;
                int j = min(i + m - 1, n - 1);
                ans = max(ans, -k * (a[j] - pre) + a[n - 1] - a[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// https://codefun2000.com/p/P1735