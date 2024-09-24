// 数学题 给长度为n的数组ai，判断是否可以构建另一个长度为n的数组 bi，使得对任意 ai，都存在 ai = bj - bk，1<=j,k<=n
/**
 * 判断an的子序列和 有重复值就可以了
 * 
 * 把bn的第一个值定死为0 x+y+z=a+b => 0 x x+y x+y+z[a+b] a
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

using ll = long long;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        unordered_set<int> st;
        //子序列和
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) sum += a[j];
            }
            if (st.count(sum)) {
                flag = true;
                break;
            }
            st.insert(sum);
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}