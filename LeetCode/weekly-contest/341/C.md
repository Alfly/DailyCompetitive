## [2645. 构造有效字符串的最少插入数](https://leetcode.cn/contest/weekly-contest-341/problems/minimum-additions-to-make-valid-string/)

> Tag: 贪心，模拟

### 方法一：模拟
* 时间复杂度: O(n)$
* 空间复杂度: O(1)$
```c++
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i ++) {
            while (cur != word[i] - 'a') {
                ans ++;
                cur ++;
                if (cur == 3) cur = 0;
                // cur = (cur + 1) % 3;
            }
            cur ++;
            if (cur == 3) cur = 0;
        };
        while (cur != 0) {
            ans ++;
            cur ++;
            if (cur == 3) cur = 0;
        }
        return ans;
    }
};
```

```c++
class Solution {
public:
    int dis(char x, char y) {
        int u = x - 'a', v = y - 'a';
        if (v <= u)
            v += 3;
        return v - u - 1;
    }
    int addMinimum(string word) {
        char lw = 'c';
        int ans = 0;
        for (auto x: word)
            ans += dis(lw, x), lw = x;
        ans += dis(lw, 'a');
        return ans;
    }
};
```

### 方法二：整体计算
* 时间复杂度: O(n)$
* 空间复杂度: O(1)$
```c++
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), cnt = 1;
        for (int i = 1; i < n; i ++) {
            if (word[i - 1] >= word[i]) cnt ++;
        }
        return cnt * 3 - n;
    }
};
```