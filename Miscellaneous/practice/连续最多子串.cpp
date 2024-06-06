#include <iostream>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
using namespace std;

string res_substring;
int res_cnt;

void solve(string s) {
    vector<string> subs;    // 后缀数组（感觉没必要）
    int len = s.size();
    for (int i = 0; i < len; i++) {
        subs.push_back(s.substr(i));
    }

    int cnt = 1, max_cnt = 1;
    string max_substr;
    // 枚举子串 s[i, j)
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int l = j - i;
            string substr = subs[i].substr(0, l);
            cnt = 1;
            if (substr == subs[j].substr(0, l)) {
                cnt++;
                // 逻辑可简化合并
                for (int k = j + l; k < len; k += l) {
                    if (substr == subs[k].substr(0, l)) cnt++;
                    else break;
                }
                if (cnt > max_cnt) {
                    max_cnt = cnt;
                    max_substr = substr;
                }
            }
        }
    }
    res_cnt = max_cnt;
    res_substring = max_substr;
}

int main() {
    string str;
    cin >> str;
    solve(str);
    cout << res_substring << ' ' << res_cnt << '\n';
    return 0;
}
