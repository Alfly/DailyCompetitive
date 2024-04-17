
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 10010;
int delay[N][N];
int remain[N];
int faultnode, cap;

int dist[N];
bool st[N];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> delay[i][j];        
        }
    }
    for (int i = 0; i < n; i++) cin >> remain[i];
    cin >> faultnode >> cap;
    
    
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    dist[faultnode] = 0;
    for (int i = 0; i < n; i++) {
        // find min
        int t = -1;
        for (int j = 0; j < n; j++) {
            if (st[j]) continue;
            if (t == -1 || dist[j] < dist[t]) t = j;
        }
        st[t] = true;
        // printf("t: %d\n", t);
        
        for (int j = 0; j < n; j++) {
            if (delay[t][j] == -1) continue;
            if (dist[j] > dist[t] + delay[t][j]) {
                dist[j] = min(dist[j], dist[t] + delay[t][j]);
            }
        }
    }
    dist[faultnode] = 0x3f3f3f3f;
    
    
    vector<PII> a;
    for (int i = 0; i < n; i++) {
        //cout << dist[i] << " ";
        a.push_back({dist[i], i});
    }
    //cout << '\n';
    
    sort(a.begin(), a.end());
    //for (int i = 0; i < n; i++) {
    //    printf("dist: %d, idx: %d\n", a[i].first, a[i].second);
    //}
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i].first == 0x3f3f3f3f) continue;
        int idx = a[i].second;
        ans.push_back(idx);
        cap -= remain[idx];
        if (cap <= 0) break;
    }
    
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    
    return 0;
}
