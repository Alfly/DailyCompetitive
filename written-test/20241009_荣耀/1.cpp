#include <bits/stdc++.h>
using namespace std;

bool check(string &s) {
    for (char c: s) {
        if (c >= '0' && c <= '9') continue;
        if (c >= 'a' && c <= 'z') continue;
        if (c >= 'A' && c <= 'Z') continue;
        return false;
    }
    return true;
}

int main() {
    string s;
    vector<string> good;
    unordered_set<string> good_set;
    vector<string> bad;
    while (cin >> s) {
        // cout << s << "|" << endl;
        if (check(s)) {
            if (!good_set.count(s)) {
                good.push_back(s);
                good_set.insert(s);
            }
        } else {
            bad.push_back(s);
        }
    }
    for (string x: good) {
        cout << x << " ";
    }
    cout << '\n';
    for (string x: bad) {
        cout << x << " ";
    }
    return 0;
}