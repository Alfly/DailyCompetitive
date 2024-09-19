#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6+10;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    int del = 0;
    int l = 0, r = l + m - 1;
    while (r < n) {
        if (a[r] - a[l] <= k) {
            del++;
        }
        l++, r++;
    }
    cout << n - del << endl;
    return 0;
}