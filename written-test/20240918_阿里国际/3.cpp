#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        a[i] += a[i + 1];
    }
    a.resize(n - 1);

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        // todo
    }
    cout << ans << endl;

    return 0;
}
// 题解：https://mp.weixin.qq.com/s/NbWgqHc52aNgXmqCPhfksA
// 转换为一个新的数组 b，其中 b[i] = a[i] + a[i+1]
// 这样，我们的问题就转化为在数组 b 中选择若干个元素