#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

int n, m, q;
unordered_map<int, int> p;
map<pair<int, int>, int> mp;

struct Operator {
    int op, u, v;
};

int Find(int x){
    if (p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

void Union(int a,int b){
    p[Find(a)] = Find(b);
}

int main() {
    int a, b;
    cin >> n >> m >> q;

    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        // 初始化
        p[u] = u; p[v] = v;
        // 记录边数
        mp[{u,v}]++;
        mp[{v,u}]++;
    }

    stack<Operator> ops;
    for(int i = 1, op, u, v; i <= q; ++i) {
        cin >> op >> u >> v;
        ops.push({op, u, v});
        if (op == 1) {
            mp[{u,v}]--;
            mp[{v,u}]--;
        }
    }

    for (auto& [edge, cnt] : mp) {
        if (cnt > 0) {
            Union(edge.first, edge.second);
        }
    }

    stack<string> ans;
    while (!ops.empty()) {
        auto t = ops.top(); ops.pop();
        int op = t.op, u = t.u, v = t.v;
        if (op == 1) {
            mp[{u, v}]++;
            mp[{v, u}]++;
            if (mp[{u, v}] > 0) Union(u, v);
        }
        else{
            if(p[u] == 0 || p[v] == 0){
                ans.push("No");
                continue;
            }
            ans.push(Find(u) == Find(v) ? "Yes" : "No");
        }
    }

    while(!ans.empty()){
        cout << ans.top() << "\n";
        ans.pop();
    }

    return 0;
}