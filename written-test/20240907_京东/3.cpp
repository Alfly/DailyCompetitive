/**
 * pass 55%
 * 数组：1 2 3 ... n，每次操作给一个元素-1，最少多少操作次数可以使和 任意 k 个数之和 <= sum
 * 
*/

#include <iostream>
using namespace std;

const int N = 1e6+10;
int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, sum;
        cin >> n >> k >> sum;
        int l = n - k + 1, r = n;
        int curMaxSum = (l + r) * k / 2;
        if (curMaxSum <= sum) {
            cout << 0 << endl;
            continue;
        }
        int low = sum / k, up = low + 1;
        // int up_cnt = sum - low * k;
        // int low_cnt = (sum - up * up_cnt) / low;
        int ans = curMaxSum - sum;
        // cout << low << ' ' << low_cnt << endl;
        // cout << up << ' ' << up_cnt << endl;
        // cout << curMaxSum << ' ' << ans << endl;
        if (n - k > low) {
            l = low + 1, r = n - k;
            // cout << l << "-" << r <<endl;
            ans += (1 + n - k - low) * (n - k - low) / 2;
        }
        cout << ans << endl;
        // cout << endl;
    }
    return 0;
}
