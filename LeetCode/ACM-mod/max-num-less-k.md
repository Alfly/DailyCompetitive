## [小于 K 的最大数](https://leetcode.cn/circle/discuss/fbhhev/)

> Tag: 回溯

数组 A 中给定可以使用的 1~9 的数，返回由 A 数组中的元素组成的小于n的最大数。

```
A = {1, 2, 4, 9}，x = 2533
2499
```

单纯使用贪心不适用，有些情况必须要回溯才可解决，如下例贪心无法处理第 3 位

```
A = {2, 4, 5}, x = 24131
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

int len, target, maxv;
vector<int> nums;

void dfs(int cur, int curLen) {
    maxv = max(maxv, cur);
    if (curLen == len) return;
    for (int i = 0; i < nums.size(); i++) {
        int t = cur * 10 + nums[i];
        if (t >= target) {
            continue;
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
    vector<int> numbers = {1, 2, 4, 9};
    int k = 2000;
    cout << getMax(numbers, k) << endl;
    return 0;
}
```

### 方法二：双指针？

```cpp

```