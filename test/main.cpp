#include <iostream>

using namespace std;

void op() {
    int x = 1024, i = 1;
    int a = x << i + 1;
    int b = (x << i) + 1;
    cout << a << ' '  << b << endl;
}

void strconvert() {
    // int -> string
    int intx = 123;
    string s = to_string(intx);
    cout << s << endl;

    // string -> int
    string strx = "456";
    int i = stoi(strx);
    cout << i << endl;
}

int main() {
    // op();
    strconvert();

    return 0;
}