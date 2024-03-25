#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 5e3+10;
int va[N], vb[N], vbn[N];

bool check(int l, int r) {
    int i = 0, cnt1 = 0;
    for (int t = l; t <= r; t++, i++) {
        // vbn[i] = vb[i] ^ va[t];
        int tmp = vb[i] ^ va[t];
        if (tmp == 1) cnt1++;
    }
    if (cnt1 & 1) return false;
    return true;
}

int main() {
    int m, n; cin >> m >> n;
    string a, b;
    cin >> a >> b;

    // vector<int> va(m), vb(n);
    for (int i = 0; i < m; i++) va[i] = a[i] - '0';
    for (int i = 0; i < n; i++) vb[i] = b[i] - '0';

    set<string> ans;
    for (int i = 0; i <= m - n; i++) {
        int j = i + n - 1;
        if (check(i, j)) ans.insert(a.substr(i, n));
    }
    cout << ans.size();

    return 0;
}
