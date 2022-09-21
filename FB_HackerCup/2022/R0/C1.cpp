#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    int N;
    string C;
    cin >> N >> C;
    vector<string> ans;
    for (int i = 1; i < N; i ++) {
        char prefix = C[0] == '.' ? '-' : '.';
        ans.push_back(string(i, prefix) + C[0]);
    }
    cout << "Case #" << test_case << ": " << '\n';
    for (auto s: ans) cout << s << '\n';
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