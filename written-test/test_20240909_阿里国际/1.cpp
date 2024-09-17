// 题目 https://mp.weixin.qq.com/s/bsgkBoSYm0VuMGPe7yqeJw

#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            if (x == 1) cnt1++;
            else if (x == 2) cnt2++;
            else if (x == 3) cnt3++;
            else if (x == 4) cnt4++;
        }
        if (cnt1 >= 1 || cnt2 >= 2 || cnt3 == 3 || (cnt2 == 1 && cnt4 == 2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}