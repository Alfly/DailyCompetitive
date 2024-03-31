#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;
const int N = 1e5+10;
int p[N];
ll cnt[N];

int Find(int x) {
    if (p[x] != x) {
        p[x] = Find(p[x]);
    }
    return p[x];
}

void Union(int a, int b) {
    int x = Find(a), y = Find(b);
    if (x != y) {
        p[x] = y;
        cnt[y] += cnt[x];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int blockcnt = 0;
    unordered_set<int> root_st;
    for (int i = 1; i <= n; i++) {
        int root = Find(i);
        root_st.insert(root);
    }

    // cout << root_st.size();

    if (root_st.size() > 2) {
        cout << 0 << endl;
    } else {
        ll ans = 1;
        for (int root: root_st) {
            ans *= cnt[root];
        }
        cout << ans << endl;
    }


    return 0;
}