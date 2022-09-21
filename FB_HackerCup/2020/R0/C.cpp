#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAXN = 800005;
pair<int, int> trees[MAXN];
unordered_map<int, int> right_mp, left_mp;

void run_cases(int test_case) {
    right_mp.clear(), left_mp.clear();
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> trees[i].first >> trees[i].second;
    }
    sort(trees, trees + N);
    for (int i = 0; i < N; i ++) {
        int p = trees[i].first, h = trees[i].second;
        right_mp[p + h] = max(right_mp[p + h], right_mp[p] + h);
    }
    reverse(trees, trees + N);
    for (int i = 0; i < N; i ++) {
        int p = trees[i].first, h = trees[i].second;
        left_mp[p - h] = max(left_mp[p - h], left_mp[p] + h);
    }
    int ans = 0;
    for (auto x: right_mp) {
        int p = x.first, len = x.second;
        ans = max(ans, len + left_mp[p]);
        // cout << "p:" << p << ",right:" << len << ",left:" << left_mp[p] << endl;
    } 

    cout << "Case #" << test_case << ": " << ans << '\n';
}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << flush;
    }
    return 0;
}