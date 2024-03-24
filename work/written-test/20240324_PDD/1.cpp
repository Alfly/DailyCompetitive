#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 2e5+10;
LL a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        // for (int i = 0; i < n; i++) cout << a[i] << ' ';
        // cout << endl;

        // 滑动窗口？
        LL sum = 0;

        cout << sum << endl;
    }
    return 0;
}