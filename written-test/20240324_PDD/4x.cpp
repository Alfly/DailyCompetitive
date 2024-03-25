#include <iostream>
using namespace std;

int expand(string str, int i, int j) {
    if (j >= str.size()) return 0;
    while (i >= 0 && j < str.size() && str[i] == str[j]) {
        i--;
        j++;
    }
    return j - i - 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int op_cnt = 0;
        while (str.size()) {
            op_cnt++;
            int n = str.size();
            int max_i = -1, max_len = 0;
            for (int i = 0; i < n; i++) {
                int len1 = expand(str, i, i);
                int len2 = expand(str, i, i + 1);
                // cout << len1 << ' ' << len2 << endl;
                int maxl = max(len1, len2);
                if (maxl > max_len) {
                    max_len = maxl;
                    max_i = i;
                }
            }
            // cout << max_i << ' ' << max_len << ' ' << max_i - (max_len-1)/2 << endl;
            if (max_len == 1) str = str.erase(max_i);
            else str = str.substr(0, max_i - (max_len-1)/2) + str.substr(max_i - (max_len-1)/2);
        }
        cout << op_cnt << endl;
    }
    return 0;
}