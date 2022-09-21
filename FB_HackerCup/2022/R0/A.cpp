#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    int N, K;
    cin >> N >> K; 
    vector<int> S(N);
    unordered_map<int, int> cnt;
    for (int i = 0; i < N; i ++) {
        cin >> S[i];
        cnt[S[i]] ++;
    }

    int n1 = 0, n2 = 0;
    bool flag = false;
    for (auto& mp: cnt) {
        if (mp.second > 2) {
            flag = true;
            break;
        } else if (mp.second == 2) {
            n2 ++;
        } else if (mp.second == 1){
            n1 ++;
        }
    }
    if (flag || (n2 + (n1+1)/2) > K) cout << "Case #" << test_case << ": NO" << '\n';
    else cout << "Case #" << test_case << ": YES" << '\n';
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