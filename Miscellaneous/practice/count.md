## [统计元素出现次数]()

> Tag: 思维 inplace 字节面试题

一个长度大小为N的数组，数组中的每个元素的取值范围在[1，N]，且为正整数。

问：如何在时间复杂度为 `O(N)`，空间复杂度为 `O(1)` 的条件下，统计数组中不同元素出现的次数。

相关链接：[link](https://github.com/cherryljr/NowCoder/blob/master/%E6%95%B0%E7%BB%84%E4%B8%AD%E5%90%84%E4%B8%AA%E5%85%83%E7%B4%A0%E5%87%BA%E7%8E%B0%E7%9A%84%E6%AC%A1%E6%95%B0.java)

相似题目：[LCR 120. 寻找文件副本](../../LeetCode/practice/LCR120.md)


### 方法一：inplace hash

把数组本身作为 hashmap 记录数据，具体操作：

1. 若当前元素小于0，则跳过
2. 若当前元素大于0，则判断其作为下标对应的元素是否大于0。
   1. 若大于0，则把对应的元素赋值给当前元素，并把它的值设置为-1；
   2. 若小于0，则把对应的元素自减1，当前元素置为0；

* 时间复杂度: ${O(n)}$
* 空间复杂度: ${O(1)}$
```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;
int arr[N];
int n;

void show() {
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    //count
    int i = 1;
    while (i <= n) {
        show();
        if (arr[i] <= 0) {
            i++;
            continue; 
        }
        int t = arr[i];
        if (arr[t] > 0) {
            arr[i] = arr[t];
            arr[t] = -1;
        } else {
            arr[i] = 0;
            arr[t] -= 1;
        }
    }
    show();

    //output
    for (int i = 1; i <= n; i++) {
        if (arr[i] < 0) {
            cout << i << " -> " << -arr[i] << endl;
        }
    }

    return 0;
}
// 5 5 4 3 2 1
// 5 4 4 4 2 1
// 13 3 4 4 1 2 1 3 7 1 6 5 6 4
```

下标从 0 开始的写法

```cpp
    int i = 0;
    while (i < n) {
        show();
        int t = arr[i] - 1; // 下标对应
        if (t < 0) {
            i++;
            continue; 
        }
        if (arr[t] > 0) {
            arr[i] = arr[t];
            arr[t] = -1;
        } else {
            arr[i] = 0;
            arr[t] -= 1;
        }
    }
```
