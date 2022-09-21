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

const int MAXN = 3005;
char g[MAXN][MAXN];
bool bad[MAXN][MAXN];
int R, C;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool good(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C && g[x][y] != '#' && !bad[x][y];
}

inline int good_around_num(int x, int y) {
    int sum = 0;
    for (int d = 0; d < 4; d ++) {
        sum += good(x + dir[d][0], y + dir[d][1]);
    }
    return sum;
}

void run_cases(int test_case) {
    memset(g, '.', sizeof g);
    memset(bad, false, sizeof bad);
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
        return;
    } 

    queue<pair<int, int>> q;
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            if (good_around_num(i, j) < 2) q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (good(x, y) && good_around_num(x, y) < 2) {
            if (g[x][y] == '^') {
                cout << "Case #" << test_case << ": " << "Impossible\n";
                return;    
            }
            bad[x][y] = true;
            for (int d = 0; d < 4; d ++) {
               q.push({x + dir[d][0], y + dir[d][1]});
            }
        }
    }

    cout << "Case #" << test_case << ": " << "Possible\n";
    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            if (g[i][j] == '.' && !bad[i][j]) cout << '^';
            else cout << g[i][j];
        }
        cout << '\n';
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