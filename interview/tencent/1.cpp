/* 
只含 0 1 的字符串， 0 和 1 相邻则消去这个两个字符，问最后剩余多少字符
 */

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int one = 0, zero = 0;
    for (char c: s) {
        if (c == '0') zero++;
        else one++;
    }

    int ans = one >= zero ? one - zero : zero - one;
    cout << ans << endl;

    return 0;
}