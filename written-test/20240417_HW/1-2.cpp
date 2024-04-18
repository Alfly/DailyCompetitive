
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> strs;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        strs.push_back(t);
    }

    vector<string> stk;
    for (string s: strs) {
        stk.push_back(s);
        int l = stk.size();
        while (l >= 3 && stk[l - 1] == stk[l - 2] && stk[l - 2] == stk[l - 3]) {
            stk.pop_back();
            stk.pop_back();
            stk.pop_back();
            l -= 3;
        }
    }

    int l = stk.size();
    if (l == 0) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < l; i++) {
            cout << stk[i] << " \n"[i == l - 1];
        }
    }

    return 0;
}

/* 

https://mp.weixin.qq.com/s/i8CXFWWkAIlStggTVfEq1Q
https://mp.weixin.qq.com/s/eikGC_XdEh9HCBbaqaW5Iw

 */