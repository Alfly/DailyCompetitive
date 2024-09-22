#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x; cin >> n >> x;
        vector<unordered_set<string>> save(n);
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            string u;
            for (int j = 0; j < m; j++) {
                cin >> u;
                save[i].insert(u);
            }
        }
        bool flag = false;
        for (int i = 0; !flag && i < n; i++) {
            for (int j = i + 1; !flag && j < n; j++) {
                if (save[i].size() > x || save[j].size() > x) continue;
                unordered_set<string> t = save[i];
                for (auto s: save[j]) {
                    t.insert(s);
                    if (t.size() > x) break;
                }
                if (t.size() == x) {
                    flag = true;
                    cout << "YES" << endl;
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
        }
        if (!flag) cout << "NO" << endl;
    }
    
    return 0;
}