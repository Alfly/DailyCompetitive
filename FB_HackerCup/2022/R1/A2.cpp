#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAXN = 500005;
int A[MAXN], B[MAXN], C[MAXN*2];
int ne[MAXN*2];
void run_cases(int test_case) {
    int N, K;
    cin >> N >> K;
    A[0] = B[0] = C[0] = 0;
    for (int i = 1; i <= N; i ++) cin >> A[i];
    for (int i = 1; i <= N; i ++) cin >> B[i];
    for (int i = 1; i <= N * 2; i ++) {
        if (i <= N) C[i] = A[i];
        else C[i] = B[i - N];
    }
    for(int i = 2, j = 0; i <= N; i++){
        while(j && A[i] != A[j + 1]) j = ne[j];
        if(A[i] == A[j + 1]) ++ j;
        ne[i] = j;
    }
    // for(int i = 1; i <= n; i++) cout << ne[i] << " ";
    // cout << "\n";

    // kmp
    for(int i = 1, j = 0; i <= 2*N; i ++){
        while(j && C[i] != A[j + 1]) j = ne[j];
        if(C[i] == A[j + 1]) ++ j;                  // s[i] vs. p[j + 1] 
        if(j == N) {
            cout << i - N << " ";                     // 继续匹配下一个
        }
    }

    cout << "Case #" << test_case << ": ";
}

int main() {
    quick_read();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int tc = 1; tc <= tests; tc ++) {
        run_cases(tc);
        cout << flush;
    }
    return 0;
}