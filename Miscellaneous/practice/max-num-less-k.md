## [字节面试题：小于 K 的最大数](https://leetcode.cn/circle/discuss/fbhhev/)

> Tag: 回溯

数组 A 中给定可以使用的 1~9 的数，返回由 A 数组中的元素组成的小于k的最大数。

```
A = {1, 2, 4, 9}，k = 2533
2499
```

单纯使用贪心不适用，有些情况必须要回溯才可解决，如下例中贪心无法处理第 3 位

```
A = {2, 4, 5}, k = 24131
22555
```

### 方法一：回溯

```cpp
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int n, int k, int u, int value);
int maxv;

int getMax(vector<int>& numbers, int k) {
    sort(numbers.begin(), numbers.end());
    int n = to_string(k).size();
    dfs(numbers, n, k, 0, 0);
    return maxv;
}
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

int main() {
    // vector<int> numbers = {1, 2, 4, 9};
    // int k = 2000;
    vector<int> numbers = {2, 4, 5};
    int k = 24131;
    cout << getMax(numbers, k) << endl;
    return 0;
}
```

### 方法二：双指针？

```cpp

```