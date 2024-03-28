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
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @return int整型
     */
    using ll = long long;
    int ans = 0;
    unordered_map<ll, bool> primes;
    int getMethods(vector<int>& a) {
        vector<bool> st(a.size(), false);
        sort(a.begin(), a.end());

        vector<ll> path;
        dfs(-1, a, st, 0, path);
        return ans;
    }
    void dfs(int pre, vector<int>& a, vector<bool>& st, int cnt, vector<ll>& path) {
        int n = a.size();
        // for (int x: path) cout << x << " ";
        // cout << endl;
        if (cnt == n) {
            // 最后判断会超时
            // for (int i = 1; i < n; i++) {
            //     if (!isPrime(path[i - 1] + path[i])) return;
            // }
            ans++;
            for (int x: path) cout << x << " ";
            cout << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st[i]) continue;
            if (pre != -1 && !isPrime(a[pre] + a[i])) {
                continue;   // 剪枝
            }
            st[i] = true;
            path.push_back(a[i]);
            dfs(i, a, st, cnt + 1, path);
            st[i] = false;
            path.pop_back();

            while (i + 1 < n && a[i + 1] == a[i]) i++;
        }
    }

    bool isPrime(ll n) {
        if (primes.count(n)) return primes[n];
        for (ll i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                primes[n] = false;
                return false;
            }
        }
        primes[n] = true;
        return true;
    }
};

int main() {
    Solution solution;
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    solution.getMethods(a);

    return 0;
}