#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    double ans = .0;
    if (n == 2) {
        ans = 1.0;
    } else {
        ans = 2.0 / (n * (n - 1));
    }
    printf("%.10f", ans);
    return 0;
}