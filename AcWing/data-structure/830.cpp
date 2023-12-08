/* 
830. 单调栈
https://www.acwing.com/problem/content/832/
 */

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N], tt = -1;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (tt >= 0 && x <= stk[tt]) tt--;
        if (tt < 0) cout << -1 << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    return 0;
}