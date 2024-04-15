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
     * @param originStr string字符串  
     * @return string字符串
     */
    string ReverseString(string str) {
        vector<string> parts;
        string tmp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                parts.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += str[i];
        }
        parts.push_back(tmp);

        string ans = "";
        for (string part: parts) {
            // ans += rev2(part) + " ";
            reverse(part.begin(), part.end());
            ans += part + " ";
        }
        ans.pop_back();
        return ans;
    }
    string rev1(string str) {
        string ans = "";
        for (int i = str.size() - 1; i >= 0; i--) {
            ans += str[i];
        }
        return ans;
    }
    string rev2(string str) {
        int n = str.size();
        for (int i = 0; i < n / 2; i++) {
            swap(str[i], str[n - i - 1]);
        }
        return str;
    }
};

int main() {
    Solution solution;

    string s;
    getline(cin, s);
    cout << solution.ReverseString(s) << endl;

    return 0;
}