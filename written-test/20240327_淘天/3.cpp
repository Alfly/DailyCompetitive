#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x: nums) cin >> x;

    int maxv = 0, max_cnt = 0;
    for (int x: nums) maxv = max(maxv, x);
    for (int x: nums) {
        if (x == maxv) max_cnt++;
    }

    int zero = n - max_cnt;
    int one = max_cnt;

    // 特殊情况：全选最大值 2^one - 1
    int res = 1;
    for (int i = 0; i < one; i++) {
        res = (res * 2) % mod;
    }
    res -= 1;   // 排除全不选的情况

    int last = res, c = one, c2 = zero;
    int m = min(zero, one - 1);    // 选择 0 的数量 < one
    
    // 每次循环取 i 个 0， [i + 1 ~ m] 个 1
    // 例如第一次循环：取 1 个 0 (c2 种) 取 [2, m] 个 1 (last - c 种)
    for (int i = 1; i <= m; i++) {
        res = (res + c2 * (last - c)) % mod;
        last -= c;
        c = (c * (one - i) / (i + 1));  // C(one, i + 1) = C(one, i) * (one - i) / (i + 1)
        c2 = (c2 * (zero - i) / (i + 1));
    }
    cout << res << endl;

    return 0;
}