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
int C[MAXN];
deque<pair<int, long long>> dq;   // (idx, F) Fi = Gi + Ci
                                // Fi：从城市1 到城市i 并加满油的最小花费
                                // Gi：从城市1 到城市i 的最小花费

void run_cases(int test_case) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> C[i];
    }
    dq.clear();
    dq.push_back({0, 0});
    for (int i = 0; i < N; i ++) {
        // 去除范围外的城市
        while (!dq.empty() && dq.front().first < i - M) {
            dq.pop_front();
        }
        if (dq.empty()) {
            cout << "Case #" << test_case << ": -1";
            return;
        }
        if (C[i]) {
            long long Gi = dq.front().second;   // O(1)
            long long Fi = Gi + C[i];
            while (!dq.empty() && Fi <= dq.back().second) {
                dq.pop_back();
            }
            dq.push_back({i, Fi});
        }
    }
    cout << "Case #" << test_case << ": " << dq.front().second;
}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << endl;
    }
    return 0;
}