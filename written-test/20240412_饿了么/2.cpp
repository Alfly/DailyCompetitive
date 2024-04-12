#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1e5+10, MAXBIT = 30, MAXV = (1 << 30) - 1;
int a[N], kbit[MAXBIT + 1], pre[N][MAXBIT + 1];
int n, q;

// O(30) >= k
bool checkgreater(int l, int r) {
    for (int i = 0; i <= MAXBIT; i++) {
        if (kbit[i] == 1 && pre[r][i] - pre[l - 1][i] == 0) {
            return false;
        }
    }
    return true;
}

// = k
bool checkequal(int l, int r) {
    for (int i = 0; i <= MAXBIT; i++) {
        if (kbit[i] == 1 && pre[r][i] - pre[l - 1][i] == 0) {
            return false;
        }
        if (kbit[i] == 0 && pre[r][i] - pre[l - 1][i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 按位 前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXBIT; j++) {
            pre[i][j] = pre[i - 1][j] + ((a[i] >> j) & 1);
        }
    }

    int l, r, k;
    for (int t = 0; t < q; t++) {
        cin >> l >> r >> k;

        memset(kbit, 0, sizeof kbit);
        for (int i = 0; i <= MAXBIT; i++) {
            kbit[i] = (k >> i) & 1;
        }

        int i = l, j = r;
        while (i < j) {
            // printf("i: %d, j: %d\n", i, j);
            int mid = (i + j) >> 1;
            if (checkgreater(l, mid)) j = mid;
            else i = mid + 1;
        }
        // printf("l: %d, j: %d\n", l, j);
        if (checkequal(l, j)) cout << j << endl;
        else cout << -1 << endl;
    }

    return 0;
}

/* 
get() 复杂度 O(30) 整体 O(q * 30 * logn)
 */