#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using PII = pair<int, int>;
const int MAXV = 1e9+5;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n);
    vector<bool> st(n, false);
    priority_queue<PII, vector<PII>, greater<PII> > q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.push({a[i], i});
    }

    while (q.size() && k) {
        auto t = q.top(); q.pop();
        int v = t.first, idx = t.second;
        if (st[idx]) continue;
        int len = l;
        // for (int i = idx; i < n && len > 0; i++, len--) {
        //     st[idx] = true;
        // }
        // if (len) {
        //     for (int i = idx; i > 0 && len > 0; i--, len--) {
        //         st[idx] = true;
        //     }
        // }
        st[idx] = true; len--;
        int left_idx = idx, right_idx = idx;
        while (len) {
            if (right_idx + 1 >= n || (left_idx - 1 >= 0 && a[left_idx - 1] < a[right_idx + 1]) || st[right_idx + 1]) {
                st[left_idx - 1] = true;
                left_idx--;
            } else {
                st[right_idx + 1] = true;
                right_idx++;
            }
            len--;
            // printf("%d %d %d \n", idx, left_idx, right_idx);
        }
        k--;
    }
    // sort(a.begin(), a.end());
    // int cnt = k * l;
    // int rand
    // cout << a[cnt - 1] << endl;
    // cout << q.size() << endl;
    // for (int x: st) cout << x;

    while (q.size()) {
        auto t = q.top(); q.pop();
        if (!st[t.second]) {
            cout << t.first << endl;
            return 0;
        }
    }

    return 0;
}
// pass 20%
