#include <iostream>
using namespace std;

const int N = 1e5+10;
long long f2[N], f5[N];

void show(int n) {
    for (int i = 1; i <= n; i++) cout << f2[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++) cout << f5[i] << ' ';
    cout << endl;
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (x % 2 == 0) {
            f2[i]++;
            x /= 2;
        }
        while (x % 5 == 0) {
            f5[i]++;
            x /= 5;
        }
    }

    // show(n);
    int sum2 = 0, sum5 = 0;
    for (int i = 1; i <= n; i++) {
        sum2 += f2[i];
        sum5 += f5[i];
        f2[i] += f2[i - 1];
        f5[i] += f5[i - 1];
    }
    // show(n);

    // [l, r]: f[r] - f[l - 1] <= sum - k
    long long res = 0;
    for (int l = 1, r = l; l <= n; l++) {
        while (r <= n) {
            int t2 = f2[r] - f2[l - 1];
            int t5 = f5[r] - f5[l - 1];
            if (min(sum2 - t2, sum5 - t5) < k) break;
            // remain 2, 5 >= k
            r++;
        }
        res += max(r - l, 0);
    }
    cout << res << endl;

    return 0;
}