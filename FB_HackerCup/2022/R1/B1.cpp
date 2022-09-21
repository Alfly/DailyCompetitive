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

const int MAXN = 500000;
const int MOD = 1000000007;
void run_cases(int test_case) {
    int N, Q;
    cin >> N;
    vector<pair<int, int>> trees(N);
    for (int i = 0; i < N; i ++) cin >> trees[i].first >> trees[i].second;
    cin >> Q;
    vector<pair<int, int>> well(Q);
    for (int i = 0; i < Q; i ++) cin >> well[i].first >> well[i].second;
    long long ans = 0;
    for (int i = 0; i < Q; i ++) {
        int x = well[i].first, y = well[i].second;
        for (int j = 0; j < N; j ++) {
            int a = trees[j].first, b = trees[j].second;
            ans = (ans + (a - x)*(a - x) + (b - y)*(b - y)) % MOD;
        }
    }
    cout << "Case #" << test_case << ": " << ans << '\n';
}

int main() {
    quick_read();
    freopen("watering_well_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << flush;
    }
    return 0;
}