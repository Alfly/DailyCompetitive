#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10, MAX = N;
PII range[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    sort(range, range + m);

    int left = 0, right = MAX;
    for (int i = 0; i < m; i++) {
        auto [l, r] = range[i];
        if (l > right) {
            cout << 0 << endl;
            return 0;
        }
        left = max(left, l);
        right = min(right, r);
    }
    cout << right - left + 1 << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")