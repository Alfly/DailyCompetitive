#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<int> x;
    while (n--) {
        int a; cin >> a;
        if (a == 1) continue;
        x.insert(a);
    }
    cout << x.size() << endl;

    return 0;
}