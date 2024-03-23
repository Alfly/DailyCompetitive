#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;
// const int mod = 998244353;
const int N = 1e6+10;
int a[N], n;
int even_cnt = 0, idx = 0;
LL prime[N], sum_copy, sum = 0;

// 符合 sum 是 i 的倍数，i 不为 2，且 i * (n + even_cnt) <= sum
bool check(int i) {
    return sum % i == 0 && i != 2 && i * (n + even_cnt) <= sum_copy;
}

int main() {
    cin >> n;
    // 统计偶数个数
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 0) even_cnt++;
    }
    // 特殊情况
    if (even_cnt == n) {
        cout << "YES" << endl;
        cout << "2";
        return 0;
    }

    sum_copy = sum;
    // 寻找 sum 因子，i 为素数
    for (LL i = 2; i <= sum / i; i++) {
        if (check(i)) {
            prime[idx++] = i;
        }
        while (sum % i == 0) {
            sum /= i;
        }
    }
    // 处理剩余因子 最后一个 > sqrt(x) 的质因数
    if (sum != 1 && sum * (n + even_cnt) <= sum_copy) {
        prime[idx++] = sum;
    }

    // 输出结果
    if (idx == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < idx; i++) {
            cout << prime[i] << ' ';
        }
    }
    return 0;
}