/*
20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
1.	左括号必须用相同类型的右括号闭合。
2.	左括号必须以正确的顺序闭合。
3.	每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    string s = "()[]{}}}}}";

    unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    stack<char> sk;
    bool res = true;

    // 通过 s.size() 快速判断是否有效

    for (char c: s) {
        if (mp.count(c)) {
            sk.push(c);
        } else if (!sk.empty() && mp[sk.top()] == c) {
            sk.pop();
        } else {
            res = false;
            break;
        }
    }
    res &= sk.empty();

    if (res) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}