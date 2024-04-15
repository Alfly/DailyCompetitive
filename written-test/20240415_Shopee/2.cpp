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
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param nums int整型 vector 
     * @return string字符串
     */

    static bool greatCmp (string a, string b) {
        return a + b > b + a;
    }
    string LargestNum(vector<int>& nums) {
        vector<string> strs;
        for (int x: nums) {
            strs.push_back(to_string(x));
        }
        sort(strs.begin(), strs.end(), greatCmp);

        // sort(strs.begin(), strs.end(), [](string a, string b) {
        //     return a + b > b + a;
        // });

        string ans = "";
        for (string s: strs) {
            ans += s;
        }

        // 注意全 0 的情况
        if (ans[0] == '0') ans = "0";

        return ans;
    }
};

int main() {
    Solution solution;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solution.LargestNum(a) << endl;

    return 0;
}