#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int> > scale(n + 1, vector<int>(10));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int k = 0; k <= 9; k++) {
            scale[i][k] = a[i] * k % 10;
        }
    }

    //presum
    vector<vector<vector<int> > > cnt(n + 1, vector<vector<int>>(10, vector<int>(10)));
    for (int k = 0; k < 10; k++) {
        for (int mod = 0; mod < 10; mod++) {
            for (int i = 1; i <= n; i++) {
                cnt[i][k][mod] += cnt[i - 1][k][mod] + (scale[i][k] == mod);
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        k = k % 10;
        // vector<int> cnt(10);
        // for (int i = l; i <= r; i++) {
        //     int x = scale[i][k];
        //     cnt[x]++;
        // }
        for (int i = 0; i < 10; i++) {
            cout << cnt[r][k][i] - cnt[l - 1][k][i] << ' ';
            // cout << cnt[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}