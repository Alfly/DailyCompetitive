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
    int cntOfSwap(TreeNode* root) {
        vector<int> path;
        dfs(root, path);

        for (int x: path) cout << x << " ";
        cout << endl;

        int n = path.size(), ans = 0;
        vector<int> s = path;
        sort(s.begin(), s.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != path[i] && path[i] == s[mp[path[i]]] && s[i] == path[mp[path[i]]]) {
                swap(path[i], path[mp[path[i]]]);
                ans++;
            }
        }

        cout <<ans;
        for (int x: path) cout << x << ' ';
        cout << endl;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (path[i] != s[i]) {
                flag = true;
                ans++;
            } 
        }
        if (flag) return ans - 1;
        else return ans;
    }
    void dfs(TreeNode* root, vector<int>& path) {
        if (root == nullptr) return;
        path.push_back(root->val);
        dfs(root->left, path);
        dfs(root->right, path);
    }
};