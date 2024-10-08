// 题解 https://mp.weixin.qq.com/s/EzeJvycttUXDYz3LULcGnw

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 2e5+10;
int a[N];

int main() {
    int n;
    long long k;
    cin >> n >> k;
    unordered_map<int, long long> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        // x^y = k => y = k^x
        int x = a[i], y = k ^ x;
        if (cnt.count(y)) {
            // 当k=0=>x==y满足 要排除掉自己和自己的情况
            ans += (long long) cnt[y] - (x == y);
        }
    }
    cout << ans / 2 << endl;

    return 0;
}
