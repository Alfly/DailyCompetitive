## [LCP 40. 心算挑战](https://leetcode.cn/problems/uOAnQW/description)

> Tag: 贪心

题意：可被2整除的有限元素最大和

[1262. 可被三整除的最大和](./1262.md)

### 方法一：贪心

选择最大的cnt个数，和为偶数则直接返回，为奇数分两种情况：
1. 去掉最小的奇数，加一个未选择的最大偶数
2. 去掉最小的偶数，加一个未选择的最大奇数

* 时间复杂度: ${O(n^logn)}$ 排序
* 空间复杂度: ${O(1)}$
```cpp
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        ranges::sort(cards, greater()); //cpp20
        int s = reduce(cards.begin(), cards.begin()+cnt, 0);
        if (s % 2 == 0) {
            return s;
        }
        // 找到一个最大的奇偶性和 x 不同的数，返回sum
        function<int(int)> replace = [&](int x) -> int {
            for (int i = cnt; i < cards.size(); i++) {
                if (cards[i] % 2 != x % 2) {
                    return s - x + cards[i];
                }
            }
            return 0;
        };

        int x = cards[cnt - 1];
        int ans = replace(x);
        for (int i = cnt - 2; i >= 0; i--) {
            if (cards[i] % 2 != x % 2) {
                ans = max(ans, replace(cards[i]));
            }
        }
        return ans;
    }
};
```

写法二：不用排序，使用快速选择算法
* 时间复杂度: ${O(n)}$
* 空间复杂度: ${O(1)}$
```cpp
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        // 第cnt大的数,后面的数都更大
        ranges::nth_element(cards, cards.end() - cnt);
        int s = reduce(cards.end() - cnt, cards.end(), 0);
        if (s % 2 == 0) {
            return s;
        }
        int n = cards.size();
        // 要去掉的最小偶数/奇数
        int minv[2] = {INT_MAX/2, INT_MAX/2};
        for (int i = n - cnt; i < n; i++) {
            int v = cards[i];
            minv[v % 2] = min(minv[v % 2], v);
        }
        // 加进来的最大偶数/奇数
        int maxv[2] = {INT_MIN/2, INT_MIN/2};
        for (int i = 0; i < n - cnt; i++) {
            int v = cards[i];
            maxv[v % 2] = max(maxv[v % 2], v);
        }
        return max(0, s + max(maxv[0] - minv[1], maxv[1] - minv[0]));
    }
};
```