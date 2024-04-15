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
        // 选择更靠前的数，所以直接把 costs 逆置
        reverse(costs.begin(), costs.end());

        int n = costs.size();
        
        // f[i][j]: 只使用前i个物品，背包容量为j时的最大价值
        // path[i][j]: 只使用前i个物品，背包容量为j，达到最大价值时是否购买最后一个物品
        int f[coins + 1];
        int path[n + 1][coins + 1];
        memset(f, 0, sizeof f);
        memset(path, 0, sizeof path);

        for (int i = 1; i <= n; i++) {
            for (int j = coins; j >= costs[i - 1]; j--) {
                f[j] = f[j - costs[i - 1]] + 1;
                path[i][j] = 1;
            }
        }
        // cout << f[coins] << endl;
        
        vector<int> ans;
        int i = n, j = coins;
        while (i > 0 && j > 0) {
            if (path[i][j] == 1) {
                ans.push_back(costs[i - 1]);
                j -= costs[i - 1];
            }
            i--;
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

/* 01 背包 记录路径 */