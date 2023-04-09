## [6361. 对角线上的质数](https://leetcode.cn/contest/weekly-contest-340/problems/prime-in-diagonal/)

> tag: 质数

```c++
class Solution {
public:
    bool isP(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= n/i; i ++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        // nums[i][i] = val 或者 nums[i][nums.length - i - 1]= val
        vector<int> diag_p;
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (isP(nums[i][i])) diag_p.push_back(nums[i][i]);
            if (isP(nums[i][n-i-1])) diag_p.push_back(nums[i][n-i-1]);
        }
        int maxv = 0;
        for (int x: diag_p) {
            maxv = max(maxv, x);
        }
        return maxv;
    }
};
```

H-version

```c++
class Solution {
public:
    int prime (int u) {
        if (u == 1) {
            return false;
        }
        for (int i = 2; i * i <= u; i += 1) {
            if (u % i == 0) {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i += 1) {
            if (nums[i][i] > ans and prime(nums[i][i])) {
                ans = nums[i][i];
            }
            if (nums[i][n - 1 - i] > ans and prime(nums[i][n - 1 - i])) {
                ans = nums[i][n - 1 - i];
            }
        }
        return ans;
    }
};
```