/* 
https://www.yuque.com/taxing-qarr6/hxitgt/ixtmscn0pvb36k2v#bfZvp
贪心 血量少的排前面让触发 R 攻击
 */
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;
const int N = 1e6 + 10;
ll h[N];
int T, n;
ll E, R;

ll min(ll x, ll y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> h[i];
        cin >> E >> R;

        sort(h, h + n);

        ll cntE = 0, cntR = 0;
        for (int i = 0; i < n; i++) {
            ll h_cur = h[i] - E * cntE - R * cntR;
            if (h_cur * 2 <= h[i]) {
                cntR++;
            } else {
                ll need = h_cur - (h[i] >> 1);   // 计算到一半的差值
                cntE += ceil((double)need / E); // 需要多少 E 上取整
                cntR++;
            }
        }

        // 用最后一个血量进行统计，最后的死去前面的也死去
        ll h_end = h[n - 1] - E * cntE;
        if (h_end - R * cntR > 0) { // 最后一个未死，继续使用 E
            cntE += ceil((double)(h_end - R * cntR) / E);
        } else {    // 最后一个已死，更新 R 的数量（E的作用是触发R，E不会多）
            ll cntR_new = ceil(double(h_end) / R);
            cntR = min(cntR, cntR_new);
        }
        cout << cntE << ' ' << cntR << endl;
    }
    return 0;
}
