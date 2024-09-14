#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int x, y, z, k; cin >> x >> y >> z >> k;
        if (x * y * z < k) {
            cout << 0 << endl;
            continue;
        }
        if (x * y * z == k) {
            cout << 1 << endl;
            continue;
        }
        int ans = 0;
        for (int a = 1; a <= k && a <= x; a++) {
            if (k % a != 0) continue;
            for (int b = 1; a * b <= k && b <= y; b++) {
                if (k % b != 0) continue;
                for (int c = 1; a * b * c <= k && c <= z; c++) {
                    if (k % c != 0) continue;
                    if (a * b * c != k) continue;
                    cout << a << ' ' << b << ' ' << c << endl;
                    ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
 * pass 55%
 * /