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
     * @param l long长整型 
     * @param r long长整型 
     * @return long长整型
     */

    using ll = long long;
    long long getNums(long long l, long long r) {
        ll ans = 0;
        // cout << getLen(1000);
        int n1 = getLen(l), n2 = getLen(r);
        if (n1 % 2 == 1) l = get10n(n1);
        if (n2 % 2 == 1) r = get10n(n2);
        printf("l: %lld, r: %lld\n", l, r);

        return ans;
    }
    int getLen(ll n) {
        int c = 0;
        while (n) {
            n /= 10;
            c++;
        }
        return c;
    }
    ll get10n(int x) {
        ll t = 1;
        for (int i = 0; i < x; i++) {
            t *= 10;
        }
        return t;
    }
};