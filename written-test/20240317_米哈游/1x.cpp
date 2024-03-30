#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

// const int N = 1e5 + 10;
// int a[N];
// bool getR[N];
int T;

int main() {
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        vector<bool> getR(n, false);
        set<int> live;
        // memset(a, 0, sizeof a);
        // memset(getR, false, sizeof getR);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            live.insert(i);
        }
        int e, r; cin >> e >> r;
        int cntE = 0, cntR = 0;
        int cntLive = n, todoR = 0;
        while (cntLive > 0) {
            // for (int i = 0; i < n; i++) cout << a[i] << ' ';
            // cout << endl;
            if (todoR == 0) {
                cntE++;
                vector<int> dead;
                for (auto i: live) {
                    // if (a[i] <= 0) continue;
                    if (!getR[i] && e * 2 >= a[i]) {
                        getR[i] = true;
                        todoR++;
                    }
                    a[i] -= e;
                    if (a[i] <= 0) {
                        cntLive--;
                        dead.push_back(i);
                    }
                }
                for (int i: dead) live.erase(i);
            } else {
                cntR++;
                todoR--;
                int totalR = r;
                vector<int> dead;
                for (auto i: live) {
                    // if (a[i] <= 0) continue;
                    if (!getR[i] && totalR * 2 >= a[i]) {
                        getR[i] = true;
                        todoR++;
                    }
                    a[i] -= totalR;
                    if (a[i] <= 0) {
                        cntLive--;
                        dead.push_back(i);
                    }
                }
                for (int i: dead) live.erase(i);
            }
        }
        cout << cntE << ' ' << cntR << endl;
    }
    return 0;
}

// 通过 27% 超时