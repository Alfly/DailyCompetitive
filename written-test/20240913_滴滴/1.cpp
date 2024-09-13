#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int ans = 0, sum = 0;
    for (int l = 0, r = 0; r < n; r++) {
        sum += nums[r];
        while (l < r && sum > m) {
            l++;
            sum -= nums[l];
        }
        if (sum <= m) ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}