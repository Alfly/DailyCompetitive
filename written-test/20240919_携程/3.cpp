#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e9+5;

int main() {
    int n, k, len;
    cin >> n >> k >> len;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int v) -> bool {
        int pre = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= v) continue;
            if (pre == -1 || pre + len - 1 < i) {
                pre = i;
                cnt++;
                if (cnt > k) return false;
            }
        }
        return true;
    };

    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end());
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        // cout << mid << endl;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

    return 0;
}
// 二分 最后的最小值v 判断比v小的数能否被覆盖
/*
8 2 3
7 4 11 2 1 4 7 5

8 2 2
7 4 11 2 1 4 7 5
*/
