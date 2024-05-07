#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

const int mod = 6;
int m, n;

// a^k % mod
int qmi(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m;
    vector<int> a(n + 1), pcnt(mod);
    vector<vector<int>> p(mod, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod;
        if (a[i] == 0) pcnt[0]++;
        // else if (a[i] == 1) continue;
        else if (a[i] == 2) pcnt[2]++;
        else if (a[i] == 3) pcnt[3]++;
        else if (a[i] == 4) pcnt[2] += 2;   // 2 * 2
        else if (a[i] == 5) pcnt[5]++;
        p[i][0] = pcnt[0]; p[i][2] = pcnt[2]; p[i][3] = pcnt[3]; p[i][5] = pcnt[5];
    }

    // for (int k = 0; k < mod; k++) {
    //     if (k == 1 || k == 4) continue;
    //     printf("%d: ", k);
    //     for (int i = 1; i <= n; i++) {
    //         printf("%d ", p[i][k]);
    //     }
    //     printf("\n");
    // }

    int x0, x2, x3, x5;
    while (m--) {
        int l, r;
        cin >> l >> r;
        x0 = p[r][0] - p[l - 1][0];
        x2 = p[r][2] - p[l - 1][2];
        x3 = p[r][3] - p[l - 1][3];
        x5 = p[r][5] - p[l - 1][5];
        // printf("x0: %d, x2: %d, x3: %d, x5: %d\n", x0, x2, x3, x5);
        if (x0) {
            cout << 0 << endl;
        } else {
            int ans = qmi(2, x2) * qmi(3, x3) * qmi(5, x5) % mod;
            cout << ans << endl;
        }
    }

    return 0;
}

/* 
5 3
1 2 3 4 5
2 4
4 5
1 2
 */