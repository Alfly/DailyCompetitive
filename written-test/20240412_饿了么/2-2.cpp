#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1e5+10, MAXBIT = 30, MAXV = (1 << 30) - 1;
int a[N], kbit[MAXBIT + 1];
int pre[N][MAXBIT + 1]; // 按位 前缀和数组
int nxt[N][MAXBIT + 1]; // 下一个为 1 的下标（包括当前位置）
int n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 按位 前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXBIT; j++) {
            pre[i][j] = pre[i - 1][j] + ((a[i] >> j) & 1);
        }
    }

    // nxt
    memset(nxt, -1, sizeof nxt);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= MAXBIT; j++) {
            if ((a[i] >> j) & 1) {
                nxt[i][j] = i;
            } else if (i < n) {
                nxt[i][j] = nxt[i + 1][j];
            }
            // if (nxt[i][j] != -1) printf("[%d][%d]: %d\n", i, j, nxt[i][j]);
        }
    }

    int l, r, k;
    for (int t = 0; t < q; t++) {
        cin >> l >> r >> k;

        memset(kbit, 0, sizeof kbit);
        for (int i = 0; i <= MAXBIT; i++) {
            kbit[i] = (k >> i) & 1;
        }

        bool ok = true;
        int pos = l;
        for (int i = 0; i <= MAXBIT; i++) {
            if (kbit[i] == 1) {
                if (nxt[l][i] == -1 || nxt[l][i] > r) {
                    ok = false;
                    break;
                }
                pos = max(pos, nxt[l][i]);
            }
        }
        // printf("pos: %d\n", pos);

        if (ok) {
            int v = 0;
            for (int i = 0; i <= MAXBIT; i++) {
                if (pre[pos][i] - pre[l - 1][i] > 0) {
                    v |= 1 << i;
                }
            }
            // printf("v: %d\n", v);
            if (v != k) {
                ok = false;
            } else {
                cout << pos << endl;
            }
        }

        if (!ok) {
            cout << -1 << endl;
        }
    }

    return 0;
}

/* 
通过 nxt 数组优化掉二分， 整体 O(q * 30)
 */