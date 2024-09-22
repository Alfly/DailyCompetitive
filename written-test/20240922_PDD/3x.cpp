#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using ll = long long;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_set<ll> st;
        bool flag = false;
        for (int t = 0; t < n; t++) {
            if (a[t] == 0) {
                flag = true;
                break;
            }
            st.clear();
            for (int i = 0; i < n; i++) {
                if (i != t) {
                    st.insert(a[i]);
                    st.insert(-a[i]);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (i == t || j == t) continue;
                    st.insert((ll) a[i] - a[j]);
                    st.insert((ll) a[j] - a[i]);
                }
            }
            if (st.count(a[t])) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
//pass 56%