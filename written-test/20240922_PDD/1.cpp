#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];        
    }
    sort(a.begin(), a.end());
    // for (auto x: a) cout << x << endl;

    vector<string> res(m);
    int idx = 0;
    for (string x: a) {
        if (x.find("PDD") != -1) res[idx++] = x;
        if (m == idx) {
            for (string o: res) cout << o << endl;
            return 0;
        }
    }
    for (string x: a) {
        if (x.find("PDD") == -1) res[idx++] = x;
        if (m == idx) {
            for (string o: res) cout << o << endl;
            return 0;
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")