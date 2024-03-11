#include <iostream>
using namespace std;

// string 2 int [-2^31, 2^31-1] 2B
int string2int(string str) {
    int n = str.size();
    bool negative = str[0] == '-' ? true : false;
    long long res = 0;
    int start_idx = negative ? 1 : 0;
    // cout << negative << ' ' << start_idx << endl;

    if (n - negative > 10) {
        cout << "out of int range" << endl;
        return -1;
    }

    for (int i = start_idx; i < n; i++) {
        char c = str[i];
        // if () {
        //     ;
        // }
        int t = c - '0';
        res = res * 10 + t;
        if (res > INT32_MAX) {
            cout << "out of int range" << endl;
            return -1;
        }
    }

    if (negative) res *= -1;
    return res;
}

int main() {
    string str;
    while (cin >> str) {
        cout << string2int(str) << endl;
    }
    cout << string2int("    -1") << endl;
    return 0;
}