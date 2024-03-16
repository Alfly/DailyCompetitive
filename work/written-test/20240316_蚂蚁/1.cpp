#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    double k;
    cin >> n >> k;
    vector<double> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') w[i] *= 0.95;
    }
    sort(w.begin(), w.end());
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (k < w[i]) break;
        k -= w[i];
        res++;
    }
    cout << res;
    return 0;
}