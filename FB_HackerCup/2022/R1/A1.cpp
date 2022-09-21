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

const int MAXN = 500005;
int A[MAXN], B[MAXN];
void run_cases(int test_case) {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i ++) cin >> A[i];
    for (int i = 0; i < N; i ++) cin >> B[i];
    // check
    int start = 0;
    for (int i = 0; i < N; i ++) {
        if (B[i] == A[0]) start = i;
    }
    for (int i = 1; i < N; i ++) {
        if (B[(start + i) % N] != A[i]) {
            cout << "Case #" << test_case << ": NO\n";
            return;
        }
    }
    int minv = K, maxv = K * (N - 1);
    int dist = (N - start) % N;
    while(dist < minv) {
        dist += N;
    }
    if (dist <= maxv) cout << "Case #" << test_case << ": YES\n";
    else cout << "Case #" << test_case << ": NO\n";
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