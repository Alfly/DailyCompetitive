
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
int p[N], cnt[N];

int Find(int x) {
    if (p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

int cal(int type, int val) {
    if (type == 0) return 5 * val;
    else return 2 * val;
}

int main()
{
    int m, n;
    cin >> m >> n;
    
    for (int i = 0; i < N; i++) {
        p[i] = i;
        cnt[i] = 0;
    }
    
    unordered_map<string, int> node;
    map<PII, int> edges;
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        
        if (!node.count(a)) node[a] = idx++;
        if (b != "*" && !node.count(b)) node[b] = idx++;
        
        if (b == "*") {            
            edges[{node[a], -1}] += cal(c, d);
        } else {
            edges[{node[a], node[b]}] += cal(c, d);
        }
    }
    
    for (auto &[k, v]: edges) {
        int a = k.first, b = k.second;
        if (b == -1) {
            int x = Find(a);
            cnt[x] += v;
        } else {
            int x = Find(a), y = Find(b);
            p[x] = y;
            cnt[y] += v;   
        }
    }
    
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        // printf("%d, p: %d, cnt: %d\n", i, p[i], cnt[i]);
        if (p[i] == i) {
            if (cnt[i] > m) ans++;
        }
    }
    cout << ans;
    return 0;
}

/* 通过 95% */