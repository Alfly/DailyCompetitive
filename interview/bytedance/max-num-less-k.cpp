#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int maxv;

void dfs(vector<int>& nums, int n, int k, int u, int value) {
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
        // dfs(nums, n, k, u + 1, value);
        // value /= 10;
        dfs(nums, n, k, u + 1, t);
    }
}

int getMax(vector<int>& numbers, int k) {
    // nums 递增可以剪枝
    sort(numbers.begin(), numbers.end());
    int n = to_string(k).size();
    dfs(numbers, n, k, 0, 0);
    return maxv;
}

int main() {
    // vector<int> numbers = {1, 2, 4, 9};
    // int k = 2000;
    vector<int> numbers = {2, 4, 5};
    int k = 24131;
    cout << getMax(numbers, k) << endl;
    return 0;
}