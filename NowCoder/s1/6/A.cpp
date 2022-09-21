#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
    long long rotateRight(string str, int k) { 
        long long ans = 0;
        int n = str.size();
        for (int i = n - k; i < n; i ++) {
            ans = ans * 2 + (str[i] - '0');
        }
        for (int i = 0; i < n - k; i ++) {
            ans = ans * 2 + (str[i] - '0');
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {  
    Solution solution;
    cout << solution.rotateRight("10110", 2);
    return 0;
}