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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param mystr string字符串 
     * @return string字符串
     */
    string change(string mystr) {
        for (int i = 0; i < mystr.size(); i++) {
            if (mystr[i] == 'r') mystr[i] = 'e';
            else if (mystr[i] == 'e') mystr[i] = 'd';
            else if (mystr[i] == 'd') mystr[i] = 'r';
        }
        return mystr;
    }
};