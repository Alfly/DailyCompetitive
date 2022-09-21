#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int solve(int n, vector<int>& a) {
        sort(a.begin(), a.end());
        int left = a[0], right = a[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (left < right) {
                ans = max(ans, a[i] - left);
                left = a[i];
            } else {
                ans = max(ans, a[i] - right);
                right = a[i];
            }
        }
        return ans;
    }
};

int main() {  
    Solution solution;
    vector<int> x = {2, 1, 1, 3, 2};
    cout << solution.solve(5, x) << "\n";
    vector<int> y = {30, 10, 20};
    cout << solution.solve(3, y) << "\n";
    return 0;
}