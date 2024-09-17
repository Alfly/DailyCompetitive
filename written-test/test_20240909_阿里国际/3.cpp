#include<iostream>
#include<vector>
using namespace std;

using PII = pair<int, int>;
const int N = 1e5+10;
int n, m, k;

// 双指针
int cal(vector<int> &a) {
    int cnt = 0, res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        // 补充间隔
        if (r) cnt += a[r] - a[r - 1] - 1;
        // 补充的数量超额 需要左边界收缩
        while (cnt > k) {
            cnt -= a[l + 1] - a[l] - 1;
            l++;
        }
        res = max(res, a[r] - a[l] + 1 + (k - cnt));
    }
    return min(res, n);
}

int main() {
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<vector<int>> color(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        color[v[i]].push_back(i);
    }
    
    int ans = k;
    for (auto c: color) {
        ans = max(ans, cal(c));
    }
    cout << ans << endl;
    return 0;
}