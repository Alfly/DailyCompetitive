#include<iostream>
using namespace std;

int main() {
    int T; cin >> T;
    int n, m;
    while (T--) {
        cin >> n >> m;
        long long sum = 0;
        if (n == 1) sum = 0;
        else if (n == 2) sum = m;
        else sum = m * 2;
        cout << sum << ' ';
    }
    return 0;
}