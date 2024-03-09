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

// 返回 <= target 最右一个数的下标
int binary_search(long long f[], int n, int target) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (f[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
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

    // [l, r]: f[r] - f[l - 1] <= sum - k => f[r] <= f[l - 1] + sum - k
    long long res = 0;
    for (int l = 1; l <= n; l++) {
        int r2 = binary_search(f2, n, f2[l - 1] + sum2 - k);
        int r5 = binary_search(f5, n, f5[l - 1] + sum5 - k);
        res += min(r2, r5) - l + 1;
    }
    cout << res << endl;

    return 0;
}