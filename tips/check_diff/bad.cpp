#include <iostream>
#include <random>
using std::cin;
using std::cout;
using std::endl;

int main() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);

    int a, b;
    cin >> a >> b;

    int roll = dist(rd);
    if (roll < 10) {
        // Wrong Answer
        cout << a + b + 1 << endl;
    } else if (roll < 20) {
        // Timeout
        while (1);
    } else {
        // ok
        cout << a + b << endl;
    }
    return 0;
}