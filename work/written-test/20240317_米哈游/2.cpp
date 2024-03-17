#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e4+10;
int a[N], b[N];
int aless[N], bless[N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1 && a[i] == a[i + 1]) aless[i] = aless[i + 1];
        else aless[i] = i + 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        if (i < m - 1 && b[i] == b[i + 1]) bless[i] = bless[i + 1];
        else bless[i] = i + 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res += aless[i] * bless[j];
        }
    }
    cout << res << endl;
    
    return 0;
}