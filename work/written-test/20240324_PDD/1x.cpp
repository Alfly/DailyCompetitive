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

        // 此处贪心不对，还需考虑取负值的左部区间
        
        // int di = n - 1, len_d = 0;
        // while (di > 0 && len_d < d && a[di - 1] + (LL)(-k)*a[di] < (LL)(-k)*a[di - 1]) {
        //     di--;
        //     len_d++;
        // }
        // cout << len_d << endl;
        // int new_n = n - len_d;
        int new_n = n - d;

        LL sum = 0;
        for (int i = new_n - 1; i >= 0; i--) {
            if (m > 0) {
                sum += (LL)a[i] * (-k);
                m--;
            } else {
                sum += a[i];
            }
            // cout << sum << ' ';
        }
        cout << sum << endl;
    }
    return 0;
}