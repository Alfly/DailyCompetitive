#include<bits/stdc++.h>
using namespace std;

const int N = 3;
int ans = 0;

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

bool check(vector<int>& board, int k, int i) {
    int x = k / N, y = k % N;
    for (int d = 0; d < 4; d++) {
        int a = x + xx[d], b = y + yy[d];
        if (a < 0 || a >= N || b < 0 || b >= N) continue;
        int t = a * N + b;
        if (abs(board[t] - i) == 1) return false;
    }
    return true;
}

void dfs(vector<int>& board, unordered_set<int>& st, int k) {
    cout << "k: " << k << "|";
    for (int x: board) cout << x << ' ';
    cout << endl;
    
    if (k == N * N) {
        ans++;
        return;
    }

    if (board[k] != 0) {
        dfs(board, st, k + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (st.count(i)) continue;
        if (!check(board, k, i)) continue;

        board[k] = i;
        st.insert(i);
        dfs(board, st, k + 1);
        board[k] = 0;
        st.erase(i);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int start = -1;
        vector<int> board(N * N);
        unordered_set<int> st;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int k = i * N + j;
                cin >> board[k];
                st.insert(board[k]);
                if (start == -1 && board[k] == 0) start = k;
            }
        }
        // for (int x: board) cout << x << ' ';
        // cout << endl;
        
        ans = 0;
        dfs(board, st, start);
        cout << ans << endl;
    }
    return 0;
}
/*
2
1 8 5
4 6 3
0 2 0
1 3 5
4 6 8
2 7 0
*/