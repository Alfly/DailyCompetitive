#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void run_cases(int test_case) {
    int N;
    string C;
    cin >> N >> C;
    unordered_set<string> leaves;
    queue<string> q;
    q.push("");
    bool finish = false;
    while (!q.empty() && !finish) {
        string cur = q.front(); q.pop();
        leaves.erase(cur);
        for (string s: {cur + '-', cur + '.'}) {
            q.push(s);
            // 判断不与 C 有共同前缀
            if (s.find(C) == 0 || C.find(s) == 0) continue;
            leaves.insert(s);
            if (leaves.size() == N - 1) {
                finish = true;
                break;
            }
        }
    }
    
    cout << "Case #" << test_case << ": " << '\n';
    for (auto s: leaves) cout << s << '\n';
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