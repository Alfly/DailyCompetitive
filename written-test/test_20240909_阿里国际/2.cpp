#include<iostream>
#include<vector>
using namespace std;

using PII = pair<int, int>;
const int N = 1e5+10;

int main() {
    int n; cin >> n;
    vector<PII> range(n);
    for (int i = 0; i < n; i++) {
        int p, r; cin >> p >> r;
        range[i] = {p + r, p - r};
    }
    sort(range.begin(), range.end());
    int ans = 0;
    int left = INT_MIN;
    for (auto [r, l] : range) {
        // cout << l << ' ' << r << endl;
        if (l > left) {
            ans++;
            left = r;
        }
    }

    cout << ans << endl;
    return 0;
}