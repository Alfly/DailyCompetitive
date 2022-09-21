#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    int N;
    string I, O;
    cin >> N >> I >> O;
    vector<vector<char>> g(N, vector<char>(N, 'Y'));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i == j) continue;
            int x = i, y = j;
            int dir = x > y ? -1 : 1;
            while (abs(x - y) > 0) {
                int next = x + dir;
                if (O[x] == 'N' || I[next] == 'N') {
                    g[i][j] = 'N';
                    break;
                }
                x = next;
            }
        }
    }
    cout << "Case #" << test_case << ":\n";
    for (int i = 0; i < N; i ++)  {
        for (int j = 0; j < N; j ++) {
            cout << g[i][j];
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