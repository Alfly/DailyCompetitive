#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1), st(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) st[i + 1] = s[i] == '1' ? true : false;

    // vector<vector<int>> f(n + 1, vector<int>(k));
    // vector<int> f(k);
    unordered_map<long long, int> f;
    for (int j = 0; j <= k; j++) f[j] = 0;
    for (int i = 1; i <= n; i++) {
        long long value = st[i] ? w[i] * 95 : w[i] * 100;
        // int value = w[i];
        for (int j = k * 100; j >= value; j--) {
            f[j] = max(f[j], f[j - value] + 1);
        }
    }
    cout << f[k * 100];

    return 0;
}

// k < 1e9 数据范围太大，内存溢出，不适合背包，直接贪心即可