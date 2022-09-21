#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int R, C;
const int MAXN = 105;
char g[MAXN][MAXN];

void run_cases(int test_case) {
    memset(g, '.', sizeof g);
    cin >> R >> C;

    bool empty = true;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            cin >> g[i][j];
            empty = empty && g[i][j] == '.';
        }
    }
    
    if (!empty && (R == 1 || C == 1)) {
        cout << "Case #" << test_case << ": " << "Impossible\n";
    } else {
        cout << "Case #" << test_case << ": " << "Possible\n";
        for (int i = 0; i < R; i ++) {
            cout << string(C, empty ? '.' : '^') << '\n';
        }
    }
}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << flush;
    }
    return 0;
}