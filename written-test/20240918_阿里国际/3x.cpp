#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<long long, int> sum_cnt;
    int max_cnt = 0;
    long long max_cnt_sum = 0;
    for (int i = 2; i <= n; i++) {
        // long long sum = a[i - 1] + a[i]; // 这里的问题？
        long long sum = (long long) a[i - 1] + a[i];
        sum_cnt[sum]++;
        if (max_cnt < sum_cnt[sum]) {
            max_cnt = sum_cnt[sum];
            max_cnt_sum = sum;
        }
    }

    int ans = 0;
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if ((long long) a[i - 1] + a[i] != max_cnt_sum) continue;
        f[i] = 1;
        for (int j = 2; j <= i - 2; j++) {
            f[i] = (f[i] + f[j] % MOD) % MOD;
        }
        ans = (ans + f[i]) % MOD;
    }
    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    cout << endl;
    cout << ans << endl;

    return 0;
}
// 直接选取最大值假设不成立