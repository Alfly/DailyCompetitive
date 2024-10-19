#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> f(b + 1, INT_MAX / 2);

    f[a] = 1;
    for (int i = 1; i <= b; i++) {
        f[i] = min(f[i], f[i / 3] + 1);
        if (i >= 10) {
            int n = to_string(i).size();
            int p = pow(10, n - 1);
            int pre = i % p * 10 + i / p;
            f[i] = min(f[i], f[pre] + 1);
        }
    }
    // int nums[]= {3, 9, 27, 72};
    // for (int x: nums) cout << f[x] << " ";
    // cout << endl;

    int ans = f[b] >= INT_MAX / 2 ? -1 : f[b];
    cout << ans << endl;

    return 0;
}
/*
3 621
6
*/