#include <iostream>
#include <vector>
using namespace std;

const int N = 16;
int m, n;
vector<vector<int>> board;
vector<vector<int>> st;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int i, int j, int &cnt) {
    st[i][j] = true;
    cnt++;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        if (!st[x][y] && board[x][y] == board[i][j]) {
            dfs(x, y, cnt);
        }
    }
}

bool valid() {
    st.assign(m, vector<int>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (st[i][j]) continue;
            int cnt = 0;
            dfs(i, j, cnt);
            if (cnt % 2 == 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> m >> n;
    int ans = 0;
    for (int state = 0; state < 1 << (m * n); state++) {
        board.assign(m, vector<int>(n));
        for (int i = 0; i < m * n; i++) {
            int x = i / n, y = i % n;
            board[x][y] = (state >> i) & 1;
        }
        if (valid()) ans++;
    }
    cout << ans << endl;
    return 0;
}
// 题解：https://mp.weixin.qq.com/s/NbWgqHc52aNgXmqCPhfksA
// 1 1 -> 2
// 1 2 -> 2
// 1 3 -> 4
// 2 2 -> 10