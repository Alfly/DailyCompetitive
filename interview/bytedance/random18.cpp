#include <cstdlib>
#include <iostream>
#include <random>
#include <cmath>
#include <unordered_map>
using namespace std;

// f3 -> [1, 3]
// _ _ _

int f3() {
    int x = (rand() % 3) + 1;
    return x;
}

int f18() {
    while (1) {
        // int x = (f3() - 1) * 3 * 3 + (f3() - 1) * 3 + (f3() - 1) + 1;   // [1-27]
        int x = (f3() - 1) * 3 * 3 + (f3() - 1) * 3 + (f3() - 1);   // [0-26]

        // cout << x << endl;

        if (x < 18) {   // [0, 17]
            return x + 1;
        }
        // [18-16]
    }
}

int main() {
    // for (int i = 0; i < 50; i++) {
    //     cout << f18() << endl;
    // }

    int avg_cnt = 100000;
    int total_test_count = 18*avg_cnt;
    unordered_map<int, int> freq;
    for (int i = 0; i < total_test_count; i++) {
        int rand_res = f18();        
        freq[rand_res]++;
    }
    for (auto kv: freq) {
        int k = kv.first, v = kv.second;
        // cout << k << ' ' << v << endl;
    }
    bool res = true;
    for (auto kv: freq) {
        int k = kv.first, v = kv.second;
        if (k < 1 || k > 18) res = false;
        if (abs(v - avg_cnt) > avg_cnt / 100) res = false;
    }
    cout << res << endl;

    return 0;
}