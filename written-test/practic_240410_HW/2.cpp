#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 910;
int a[N][N];
int p[N], cnt[N];
int n;

int Find(int x) {
    if (p[x] != x) {
        p[x] = Find(p[x]);
    }
    return p[x];
}

void Union(int x, int y, int w) {
    int a = Find(x), b = Find(y);
    if (a != b) {
        p[a] = b;
        cnt[b] += cnt[a] + w;
    } else {
        cnt[b] += w;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i] = i;
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0) {
                Union(i, j, a[i][j]);
            }
        }
    }


    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            // cout << i << endl;
            res.push_back(cnt[i]);
        }
    }
    sort(res.rbegin(), res.rend());

    for (int x: res) cout << x << ' ';

    return 0;
}