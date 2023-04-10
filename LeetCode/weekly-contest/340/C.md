## [2616. 最小化数对的最大差值](https://leetcode.cn/contest/weekly-contest-340/problems/minimize-the-maximum-difference-of-pairs/)

> Tag: 二分，TODO

### 方法一：二分

输出`最大差值`的最小值，求解关键在对差值的二分判断，再套二分模版

```c++
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];   // 差值范围: [0, max]
        while (l < r) {
            int m = (l + r) / 2, cnt = 0;
            // 计算大于差值的数对
            for (int i = 0; i + 1 < n; i ++) {
                if (nums[i] + m >= nums[i + 1]) {
                    cnt += 1;
                    i += 1; // 去重
                }
            }
            if (cnt >= p) r = m;
            else l = m + 1;
        }
        return l;
    }
};
```
