#include <iostream>
#include <string>
#include <vector>
using namespace std;

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

bool get_around_check(int i, int j, vector<string> matrix, int n, int m) {
    int start_cnt = 0, dot_cnt = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + xx[k], y = j + yy[k];
        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (matrix[x][y] == '*') start_cnt++;
            else {
                dot_cnt++;
                if (dot_cnt > 1) return false;
            }
        }
    }
    return start_cnt == 3;
}

int main() {
    int q; cin >> q;
    while (q--) {
        int m, n;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++) cin >> matrix[i];
        bool isT = false;

        for (int i = 0; i < n && !isT; i++) {
            for (int j = 0; j < m && !isT; j++) {
                if (matrix[i][j] == '*' && get_around_check(i, j, matrix, n, m)) {
                    isT = true;
                }
            }
        }

        if (isT) cout << "T" << endl;
        else cout << "L" << endl;
    }
    return 0;
}
