#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    vector<int> num(10);
    for (char c: s) {
        c = c < 'a' ? c - 'A' + 'a' : c;
        cnt[c - 'a']++;
    }
    // for (int x: cnt) cout << x << ' ';
    //two
    if (cnt['w' - 'a']) {
        int n = cnt['w' - 'a'];
        cnt['t' - 'a'] -= n;
        cnt['w' - 'a'] -= n;
        cnt['o' - 'a'] -= n;
        num[2] += n;
    }
    //six
    if (cnt['x' - 'a']) {
        int n = cnt['x' - 'a'];
        cnt['s' - 'a'] -= n;
        cnt['i' - 'a'] -= n;
        cnt['x' - 'a'] -= n;
        num[6] += n;
    }
    //eight
    if (cnt['g' - 'a']) {
        int n = cnt['g' - 'a'];
        cnt['e' - 'a'] -= n;
        cnt['i' - 'a'] -= n;
        cnt['g' - 'a'] -= n;
        cnt['h' - 'a'] -= n;
        cnt['t' - 'a'] -= n;
        num[8] += n;
    }
    //seven
    if (cnt['s' - 'a']) {
        int n = cnt['s' - 'a'];
        cnt['s' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        cnt['v' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        cnt['n' - 'a'] -= n;
        num[7] += n;
    }
    //five
    if (cnt['v' - 'a']) {
        int n = cnt['v' - 'a'];
        cnt['f' - 'a'] -= n;
        cnt['i' - 'a'] -= n;
        cnt['v' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        num[5] += n;
    }
    //nine
    if (cnt['i' - 'a']) {
        int n = cnt['i' - 'a'];
        cnt['n' - 'a'] -= n;
        cnt['i' - 'a'] -= n;
        cnt['n' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        num[9] += n;
    }
    //three
    if (cnt['t' - 'a']) {
        int n = cnt['t' - 'a'];
        cnt['t' - 'a'] -= n;
        cnt['h' - 'a'] -= n;
        cnt['r' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        num[3] += n;
    }
    //four
    if (cnt['f' - 'a']) {
        int n = cnt['f' - 'a'];
        cnt['f' - 'a'] -= n;
        cnt['o' - 'a'] -= n;
        cnt['u' - 'a'] -= n;
        cnt['r' - 'a'] -= n;
        num[4] += n;
    }
    //zero
    if (cnt['z' - 'a']) {
        int n = cnt['z' - 'a'];
        cnt['z' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        cnt['r' - 'a'] -= n;
        cnt['o' - 'a'] -= n;
        num[0] += n;
    }
    //one
    if (cnt['o' - 'a']) {
        int n = cnt['o' - 'a'];
        cnt['o' - 'a'] -= n;
        cnt['n' - 'a'] -= n;
        cnt['e' - 'a'] -= n;
        num[1] += n;
    }
    // for (int x: num) cout << x << ' ';
    for (int i = 0; i < 10; i++) {
        while (num[i]--) cout << i;
    }
    return 0;
}