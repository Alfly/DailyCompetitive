/**
 * 题解：https://mp.weixin.qq.com/s/6thCgBA5mIXIyxnVjrFL2A
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
unordered_map<long long, int> factors;

void prime_factorize(long long n, int c) {
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors[d] += c;
             n /= d;
        }
    }
    if (n > 1) factors[n] += c;
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long b;
        int c;
        cin >> b >> c;
        if (b != 1) {
            prime_factorize(b, c);
        }
    }

    long long result = 1;
    for (const auto& [prime, count] : factors) {
        result = (result * (count + 1)) % MOD;
    }
    cout << result << endl;
    
    return 0;
}