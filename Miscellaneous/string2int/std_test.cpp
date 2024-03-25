#include <iostream>
#include <iomanip> // 包含 setw
using namespace std;

vector<string> test_case = {"123", "-123", "-0", "0",
                            "-00123", "00123",
                            "1111111111111", "-1111111111111",
                            "  -10", "  10", " ", "",
                            "abc", "abc-1", "  -100abc-1", "100 100",
                            };

int main() {
    for (string s: test_case) {
        cout << "atoi(\"" + s + "\"): " << std::setw(30) << std::left << atoi(s.c_str()) << '\t';
        cout << "stoi(\"" + s + "\"): " ;
        try {
            cout << stoi(s);
        } catch (const std::invalid_argument& e) {
            cout << "[Invalid argument exception]: " << e.what();
        } catch (const std::out_of_range& e) {
            cout << "[Out of range exception]: " << e.what();
        }
        cout << endl;
    }
    return 0;
}