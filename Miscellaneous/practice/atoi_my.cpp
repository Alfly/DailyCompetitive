#include <iostream>
using namespace std;

vector<string> test_case = {"123", "-123", "-0", "0",
                            "-00123", "00123",
                            "1111111111111", "-1111111111111",
                            "  -10", "  10", " ", "",
                            "abc", "abc-1", "  -100abc-1", "100 100",
                            };

// string 2 int [-2^31, 2^31-1] [-2147483648, 2147483647]
int myAtoi(const char* str) {
    if (str == nullptr) return 0;

    int res = 0, sign = 1, i = 0;

    // 忽略字符串开头空格
    while (str[i] == ' ') i++;

    // 整数符号判断
    if (str[i] == '-' || str[i] == '+') {
        sign = str[i++] == '-' ? -1 : 1;
    }

    // 没有有效转化数字
    if (!(str[i] >= '0' && str[i] <= '9')) {
        throw std::invalid_argument("no conversion");
        // return 0;
    }

    // 计算数字
    for (; str[i]; i++) {
        // 非数字字符直接终止
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return res * sign;
        }
        // 处理溢出
        if (res > INT_MAX / 10 || (res == INT_MAX/10 && str[i] > '7')) {
            throw std::out_of_range("out of range");
            // return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + str[i] - '0';
    }
    return res * sign;
}

int main() {
    for (string s: test_case) {
        cout << "string2int(\"" + s + "\"): ";
        try {
            cout << myAtoi(s.c_str());
        } catch (const std::invalid_argument& e) {
            cout << "[Invalid argument exception]: " << e.what();
        } catch (const std::out_of_range& e) {
            cout << "[Out of range exception]: " << e.what();
        }
        cout << endl;
    }
    return 0;
}