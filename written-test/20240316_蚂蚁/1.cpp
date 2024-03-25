#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;
// const int mod = 998244353;

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

// https://codefun2000.com/p/P1697