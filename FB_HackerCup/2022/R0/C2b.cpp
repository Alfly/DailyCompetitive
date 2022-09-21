#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <unordered_set>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int BITS = 8;
void run_cases(int test_case) {
    int N;
    string C;
    cin >> N >> C;
    vector<string> ans;
    for (int i = 0; i < (1 << 8) && ans.size() < N - 1; i ++) {
        string s = bitset<BITS>(i).to_string('.', '-');
        if (C.find(s) != 0 && s.find(C) != 0) {
            ans.push_back(s);
        }
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