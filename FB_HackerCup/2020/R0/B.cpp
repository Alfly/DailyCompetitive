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
    string s;
    cin >> N >> s;
    int a = 0, b = 0;
    for (auto c: s) {
        if (c == 'A') a ++;
        else b ++;
    }
    char ans = (abs(a - b) == 1 ? 'Y' : 'N');
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