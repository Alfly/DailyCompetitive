#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> st;

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        char color;
        cin >> u >> v >> color;
        if (color == 'W') {
            st.insert(u);
            st.insert(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!st.count(i)) ans++;
    }   
    cout << ans;
    return 0;
}