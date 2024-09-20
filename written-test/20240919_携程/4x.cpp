#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_dist = max(max_dist, abs(a[i] - p));
    }
    for (int i = 0; i < k; i++) cin >> b[i];
    cout << max_dist << endl;
    return 0;
}
// pass 75%