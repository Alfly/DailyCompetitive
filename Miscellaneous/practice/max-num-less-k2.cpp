#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int getMax(vector<int>& nums, int k) {
    // nums 递增可以剪枝
    sort(nums.begin(), nums.end());
    int n = to_string(k).size();

    int maxv = 0;
    function<void(int, int)> dfs = [&](int u, int value) {
        maxv = max(maxv, value);
        if (u == n) {
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int t = value * 10 + nums[i];
            // nums 递增 可以剪枝
            if (t >= k) {
                break;
            }
            // value = value * 10 + nums[i];
            // dfs(u + 1, value);
            // value /= 10;
            dfs(u + 1, t);
        }
    };

    dfs(0, 0);

    return maxv;
}

int main() {
    int T = 100;
    while (T--) {
        int k, n;
        cin >> k >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        int res = getMax(nums, k);
        cout << res << "\n\n";
    }
    return 0;
}
/*
23121 3
2 4 9

2000 4
1 2 4 9

24131 3
2 4 5
*/