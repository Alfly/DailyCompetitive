#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
    int solve(int n, vector<int>& a) {
        unordered_map<int, int> mp;
        for (int x: a) {
            int cnt = 0;
            while (x % 2 == 0) {
                ++ cnt;
                x /= 2;
            }
            mp[x] = cnt;
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans += it->second;
        }
        return ans;
    }
};

int main() {  
    Solution solution;
    vector<int> v = {2, 2, 3};
    cout << solution.solve(3, v) << endl;
    return 0;
}