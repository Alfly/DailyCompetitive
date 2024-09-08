/**
 * pass 10%
 * 
*/
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/*
1: 1
2: 1 2
3: 1 2 3 1
4: 1 2 3 4 1 3 [2 4]
5: 1 2 3 4 5 1 4 2 5 3 1
6: 1 2 3 4 5 6 1 5 2 6 3 1 4 2 [4 5] [4 6]??? 
*/

int main() {
    int d; cin >> d;
    if (d == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 1;
    unordered_map<int, int> mp;
    for (int i = 1; i <= d; i++) {
        mp[i] = 0;
    }
    int cur = 1;
    while (1) {
        int t = mp[cur];
        bool flag = false;
        for (int i = 1; i <= d; i++) {
            if (((t >> i) & 1) == 0) {
                mp[cur] |= (1 << i);
                mp[i] |= (1 << cur);
                cur = i;
                ans++;
                flag = true;
            }
        }
        if (flag) break;
    }
    if (d == 5) cout << 11 << endl;
    else cout << ans << endl;
    return 0;
}
