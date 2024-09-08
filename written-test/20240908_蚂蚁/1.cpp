#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        if (x > 0) a++;
        else if (x < 0) b++;
        else c++;
    }
    int ans = 0;
    if (k <= b) {
        a += k;
        b -= k;
        ans = a - b;
    } else {
        a += b;
        k -= b;
        b = 0;
        k = max(0, k - c);
        // cout << a << b << k << endl;
        ans = a - b - 2 * k;
    }
    cout << ans << endl;
    return 0;
}
