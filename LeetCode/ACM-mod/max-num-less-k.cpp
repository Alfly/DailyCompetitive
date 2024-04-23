#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int len, target, maxv;
vector<int> nums;

void dfs(int cur, int curLen) {
    maxv = max(maxv, cur);
    if (curLen == len) return;
    for (int i = 0; i < nums.size(); i++) {
        int t = cur * 10 + nums[i];
        if (t >= target) {
            break;
        }
        cur = cur * 10 + nums[i];
        dfs(cur, curLen + 1);
        cur /= 10;
    }
}

int getMax(vector<int>& numbers, int k) {
    sort(numbers.begin(), numbers.end());
    int length = to_string(k).size();

    len = length;
    target = k;
    nums = numbers;

    dfs(0, 0);

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