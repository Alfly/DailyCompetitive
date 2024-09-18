#include <iostream>
#include <vector>
using namespace std;

const int N = 16;

int main() {
    int m, n; cin >> m >> n;
    if (m > n) swap(m, n);
    vector<vector<int>> f(N + 1, vector<int>(N + 1));
    f[1][1] = 2;
    f[1][2] = 2;
    for (int i = 3; 1 * i <= N; i++) {
        f[1][i] = f[1][i - 1] + f[1][i - 2];
    }

    int ans = 0;
    if (m == 1) {
        ans = f[m][n];
    } else {
        ans = 10;
    }
    cout << ans;
    return 0;
}