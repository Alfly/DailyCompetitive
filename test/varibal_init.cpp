#include <iostream>
using namespace std;

int global;

void get() {
    int x;
    cout << "global: " << global << endl;
    cout << "get() " << x << endl;
}

int main() {
    int x;
    int y = x;
    cout << "global: " << global << endl;
    cout << "main() " << x << endl;
    get();

    return 0;
}