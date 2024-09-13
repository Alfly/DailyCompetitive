#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> nums(n + 1);
        vector<int> up(n + 1);
        vector<int> down(n + 1);
        for (int i = 0; i < n; i++) {
            int op, x;
            cin >> op >> x;
            nums[x] = op;
            if (op == 1) down[x] = 1;
            else if (op == -1) up[x] = 1;
        }
        //presum
        for (int i = 1; i <= n - 1; i++) {
            down[i + 1] += down[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            up[i] += up[i + 1];
        }
        bool res = true;
        for (int i = 1; i <= n; i++) {
            if (nums[i] == 1) {
                if (up[i] == 0) {
                    res = false;
                    break;
                }
            } else if (nums[i] == -1) {
                if (down[i] == 0) {
                    res = false;
                    break;
                }
            }
        }
        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}