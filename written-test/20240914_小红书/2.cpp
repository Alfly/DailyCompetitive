#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int x, y, z, k;

int w(int a, int b, int c) {
    if (a > x || b > y || c > z) return 0;
    return (x - a + 1) * (y - b + 1) * (z - c + 1);
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> x >> y >> z >> k;
        // 排序 x < y < z
        if (x > y) swap(x, y);
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);

        long long ans = 0;
        for (int a = 1; a <= x; a++) {
            for (int b = a; b <= y; b++) {
                int c = k / a / b;
                if (c < b) break;
                if (a * b * c != k) continue;
                int s1 = max(w(a, b, c), w(a, c, b));
                int s2 = max(w(b, a, c), w(b, c, a));
                int s3 = max(w(c, a, b), w(c, b, a));
                ans += max(s1, max(s2, s3));
            }
        }
        cout << ans << endl;
    }
    return 0;
}