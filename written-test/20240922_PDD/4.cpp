// 第i时刻汉堡的价格为pi，所购买的汉堡价格可以对应转换为积分
// 若积分大于等于100，自动转换为一张汉堡券，时限为3天（若第1天获得汉堡券，可以在第2、3、4天使用）
// 求获得所有汉堡需要花费的最小金额

/**
 * dp[i][j][k]表示第i天后券为j剩余积分为k所需要花费的最小金额
 * 将券的状态记为j，其中j为历史三天是否获得优惠券（若j=6=0b110，表示i-1、i-2天获得了优惠券），剩余积分记为k
 * 对于每个dp[i-1][j][k]，判断是否有券可以在下一时刻使用（j!=0），并计算下一时刻是否使用券的情况下后续的状态，从而能够转移到dp[i][new j][new k]
 * O(800n)

具体而言：
    if (j & 1) dp[i][(j-1)>>1][k] = min(dp[i][(j-1)>>1][k], dp[i-1][j][k])
    else if (j & 2) dp[i][(j-2)>>1][k] = min(dp[i][(j-2)>>1][k], dp[i-1][j][k])
    else if (j & 4) dp[i][(j-4)>>1][k] = min(dp[i][(j-4)>>1][k], dp[i-1][j][k])
    
    dp[i][j>>1|(k+p[i])/100*4][(k+p[i])%100] = min(dp[i][j>>1|(k+p[i])/100*4][(k+p[i])%100], dp[i-1][j][k] + p[i])
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int ans;
int n;

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        //todo

        cout << ans << endl;
    }
    return 0;
}