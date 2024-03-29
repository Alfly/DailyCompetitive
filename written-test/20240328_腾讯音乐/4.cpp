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

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int cntOfSwap(vector<int>& path) {
        int n = path.size(), ans = 0;
        vector<int> s = path;
        sort(s.begin(), s.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            // if (s[i] != path[i]) {
            //     swap(path[i], path[mp[path[i]]]);
            //     ans++;
            // }
            while (s[i] != path[i]) {
                swap(path[i], path[mp[path[i]]]);
                ans++;
            }
        }
        cout << ans << endl;
        return ans;
    }
};

int main() {
    Solution solution;
    
    int T, n; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        solution.cntOfSwap(a);
    }

    return 0;
}