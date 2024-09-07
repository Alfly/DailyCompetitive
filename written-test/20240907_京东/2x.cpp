/**
 * pass 35%
 * 牛牛从 0 到 L，可以走路可以跳，满足刚好跳了 m 次且每次长为 b，是否可能
 * 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, L, m, b;
        cin >> n >> L >> m >> b;
        if (m * b > L || b == 0) {
            cout << "No" << endl;
            continue;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int least_jump_cnt = 0;
        int t = 0, gap = 0;
        for (int x: p) {
            if (x < t) continue;
            gap += (x - t) / b;
            t = x + b;
            least_jump_cnt++;
        }
        // cout << "least_jump_cnt: " << least_jump_cnt << endl;
        if (least_jump_cnt > m || least_jump_cnt + gap < m) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}
