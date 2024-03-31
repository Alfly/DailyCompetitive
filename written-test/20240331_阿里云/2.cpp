#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
ll num[N];
int n;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            /* 暴力模拟 15% */
            // if (num[j] >= num[i] && num[j] - num[i] == lcm(num[i], num[j]) - gcd(num[i], num[j])) { 
            //     ans++;
            // }
            /* 公式推导 ?% */
            // 令 gcd(b, a) = x, b = i*x, a = j*x;
            // b - a = a * b / gcd - gcd => i*x - j*x = i*j*x - x => i*j - i + j - 1 = 0;
            // (i + 1) * (j - 1) = 0 => j = 1;
            if (num[j] % num[i] == 0) { 
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

