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
     * 根据价格列表和当前点券数，计算出能买到的最多英雄
     * @param costs int整型 vector 英雄点券价格列表
     * @param coins int整型  拥有的点券
     * @return int整型vector
     */
    vector<int> cal(vector<int>& costs, int coins) {
        vector<int> tmp = costs;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (coins >= tmp[i]) {
                coins -= tmp[i];
                mp[tmp[i]]++;
                cnt++;
            }
            else break;
        }
        vector<int> ans(cnt);
        int i = 0;
        for (int x: costs) {
            if (mp[x] > 0) {
                mp[x]--;
                ans[i++] = x;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int coins; cin >> coins;

    vector<int> ans = solution.cal(a, coins);
    for (int x: ans) cout << x << " ";

    return 0;
}

/*

贪心 通过率为66%

不是输出任意满足要求的列表，而是选择那个每个元素尽量靠前的

costs=[10 8 6]，coins=18，贪心 [8 6] 答案 [10 8]
costs=[5 4 3 2]，coins=12，贪心 [4 3 2] 答案 [5 4 3]

*/