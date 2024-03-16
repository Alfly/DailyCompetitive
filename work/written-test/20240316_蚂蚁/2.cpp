#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 200000+5;
int a[N], b[N];
string tag = "aeiou";

int main() {
    string str;
    cin >> str;
    int n = str.size(), res = 0;

    int yuanSum = 0, otherSum = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (char c: tag) {
            if (str[i] == c) {
                flag = true;
                yuanSum++;
                break;
            }
        }
        a[i + 1] = a[i] + (flag == true); 
        b[i + 1] = b[i] + (flag == false); 
    }
    otherSum = n - yuanSum;

    for (int i = 0; i < n - 1; i++) {
        int leftLen = i + 1;
        // string left = str.substr(0, leftLen);
        // string right = str.substr(leftLen);
        // cout << left << ' ' << right << endl;
        // [0, i] [i + 1, n - 1]
        int left = abs(a[i + 1] - b[i + 1]);
        int right = abs((yuanSum - a[i + 1]) - (otherSum - b[i + 1]));
        if (left == right) res++;
    }
    cout << res;

    return 0;
}