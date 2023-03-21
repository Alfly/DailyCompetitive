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

class Solution {
public:
    unordered_map<string, vector<string>> g;
    vector<string> curr_path;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto edge: tickets) {
            if (g.find(edge[0]) == g.end()) {
                vector<string> v;
                g[edge[0]] = v;
            }
            g[edge[0]].push_back(edge[1]);
        }
        for (auto &t: g) {
            cout << t.first << " -> ";
            sort(t.second.rbegin(), t.second.rend());
            for (auto s: t.second) cout << s << ' ';
            cout << '\n';
        }
        string start = "JFK";
        Hierholzer(start);
        // for (int i = ans.size() - 1; i >= 0; i --) {
        //     cout << ans[i];
        //     if (i) cout << " ";
        // }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void Hierholzer(string start) {
        curr_path.push_back(start);
        while (curr_path.size() != 0) {
            string u = curr_path.back();
            if (g[u].size()) {
                string v = g[u].back();
                g[u].pop_back();
                curr_path.push_back(v);
            } else {
                curr_path.pop_back();
                ans.push_back(u);
            }
        }
    }
};
int main() {
    Solution solution;

    return 0;
}


