/**
 * 面试官要求不用回溯 5555

2533 1 2 4 9
---
1999
2299
2499
29xx
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    vector<int> A = {1, 2, 4, 9};
    int n = 2499;

    sort(A.begin(), A.end());
    
    string ns = to_string(n);
    int len = ns.size();
    int ans = 0;
    
    int Alen = A.size();
    int top = A.back();
    int premax = 0;
    for (int i = 0; i < len; i++) {
        int t = ns[i] - '0';
        
        for (int j = 0; j < A.size(); j++) {
            if (A[j] >= t) break;
            // [0, j][...]
            int p = Alen - j - 1;

            int cur_max;
            if (A[j] < t) {
                cur_max = premax * 10 + A[j];
                while (p--) {
                    cur_max = cur_max * 10 + top;
                }
                premax = premax * 10 + A[j];
            } else {
                if (i == len - 1 || (ns[i + 1] - '0') >= A.front()) {
                    premax = premax * 10 + A[j];        
                }
            }

            cout << cur_max << endl;
            ans = max(ans, cur_max);
        }
    }

    // cout << ans << endl;

    return 0;
}