#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int ans;
int n;

void dfs(int u, int money, int score, vector<int>& p, vector<int>& bonus, vector<bool>& st) {
    if (u == n) {
        ans = min(money, ans);
        return;
    }
    if (score >= 100) {
        score -= 100;
        bonus.push_back(u + 2);
        st.push_back(true);
    }

    dfs(u + 1, money + p[u], score + p[u], p, bonus, st);

    for (int i = 0; i < bonus.size(); i++) {
        if (st[i] && bonus[i] >= u) {
            st[i] = false;
            dfs(u + 1, money, score, p, bonus, st);
            st[i] = true;
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        ans = 50000;
        vector<int> bonus;
        vector<bool> st;
        dfs(0, 0, 0, p, bonus, st);

        cout << ans << endl;
    }
    return 0;
}