
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<string>
using namespace std;

int check(string s) {
    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return i;
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        if (t == "10") t = "1";
        s += t;
    }
    
    while (s.size() > 0) {
        int idx = check(s);
        // cout << s << '|' << idx << endl;
        if (idx == -1) break;
        string l = s.substr(0, idx);
        string r = idx + 3 < s.size() ? s.substr(idx + 3) : "";
        s = l + r;
    }
    // cout << s << endl;
    if (s.size() > 0) {
        for (int i = 0; i < s.size(); i++) {
            if (i != 0) cout << ' ';
            if (s[i] == '1') cout << "10";
            else cout << s[i];
        }
    } else {
        cout << 0;
    }
    return 0;
}

/* 

可用栈实现 不用每次从头开始判断

 */