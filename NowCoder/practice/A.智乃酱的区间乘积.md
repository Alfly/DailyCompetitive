## [A.智乃酱的区间乘积](https://ac.nowcoder.com/acm/contest/19483/A)

> Tag: 前缀积 费马小定理 逆元 快速幂 数论

给定一个长度大小为 N 的正整数数组，查询 M 轮，每次问一个区间所有元素的连续乘积。

由于这个答案可能很大，你只用输出结果对 10^9+7 取余数后的结果即可。

### 方法一：前缀积 快速幂
* 时间复杂度: ${O(m * 32)}$ 预处理 ${O(n)}$
* 空间复杂度: ${O(n)}$
```cpp
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e5+10, mod = 1e9+7;
int s[N];

// a^k % p
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 前缀积
    s[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = (LL)s[i - 1] * s[i] % mod;
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        // s[b] / s[a - 1] => s[b] * s[a - 1]^{-1}
        // 费马小定理求 s[a - 1] 关于 mod 的逆元
        int ans = (LL)s[b] * qmi(s[a - 1], mod - 2, mod) % mod;
        cout << ans << endl;
    }
    
    return 0;
}
```
