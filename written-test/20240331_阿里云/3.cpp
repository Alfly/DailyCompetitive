#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
char aeiou[5] = {'a' ,'e', 'i', 'o', 'u'};

int main() {
    int n; cin >> n;
    string str, color;
    cin >> str >> color;
    vector<int> w(n + 1, 0);
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int i = 0; i < 5; i++) {
            if (str[i] >= aeiou[i]) flag = true;
        }
        if (flag && color[i] == '1') {
            w[i + 1] = 1;
        }
    }

    int ans = 0;
    vector<ll> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (w[i] == 1) f[i] = (f[i] + f[j] + 1) % mod;
            else f[i] = (f[i] + f[j]) % mod;
        }
        ans = (ans + f[i]) % mod;
    }
    // cout << ans << endl;
    cout << f[n];

    return 0;
}
