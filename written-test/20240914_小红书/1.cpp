#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    unordered_map<int, long long> cnt;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        if (cnt[x] == 1) a.push_back(x);
    }
    long long ans = 0;
    for (int x: a) {
        // x^y = k => y = k^x
        long long y = k ^ x;
        if (cnt.count(y)) {
            ans += (long long) cnt[x] * cnt[y];
        }
    }
    cout << ans / 2 << endl;

    return 0;
}