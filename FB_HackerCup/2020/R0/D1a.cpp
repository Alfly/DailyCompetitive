#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAXN = 1000005;
const int INF = 1e9;
int C[MAXN];

void run_cases(int test_case) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> C[i];
    }
    vector<int> F(N, INF);  // Fi：从城市1 到城市i 并加满油的最小花费
    vector<int> G(N, INF);  // Gi：从城市1 到城市i 的最小花费
    F[0] = G[0] = 0;
    for (int i = 1; i < N; i ++) {
        for (int j = max(0, i - M); j < i; j ++) {
            G[i] = min(G[i], F[j]); // O(M)
            if (C[i]) F[i] = G[i] + C[i];
        }
    }
    int ans = G[N - 1] == INF ? -1 : G[N - 1];
    cout << "Case #" << test_case << ": " << ans << '\n';
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