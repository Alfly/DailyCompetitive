#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
using namespace std;

using PII = pair<int, int>;
struct Fragment {
    unordered_set<int> att_vert;            // attachment_vertex
    vector<int> F;                          // filed index list
    unordered_map<int, unordered_set<int>> graph;
};

const int N = 110;
int n, m;
vector<int> g[N], h[N];     // H: G's subgraph;
bool st[N];
vector<int> cycle_path;     // algo starts from a cycle
vector<list<int>> field;     // filed boundary nodes
vector<Fragment> fras;


inline void quick_read() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void show_cycle_path() {
    cout << "\ncycle path: ";
    for (int x: cycle_path) cout << x << " ";
}

// void show_field_boundary() {
//     cout << "\nfield count: " << field.size();
//     int field_idx = 0;
//     for (auto it = field.begin(); it != field.end(); it++) {
//         cout << "\nfield " << field_idx << " vertex count: " << (*it).size() - 1 << " | boundary: ";
//         for (auto x: (*it)) cout << x << ' ';
//         field_idx++;
//     }
//     cout << '\n';
// }

void show_field_boundary() {
    cout << "\nfield count: " << field.size();
    for (int i = 0; i < field.size(); i++) {
        cout << "\nfield " << i << " vertex count: " << field[i].size() - 1 << " | boundary: ";
        for (auto x: field[i]) cout << x << ' ';
    }
    cout << '\n';
}

void show_fragments() {
    cout << "\nfragment count: " << fras.size();
    for (int i = 0; i < fras.size(); i++) {
        cout << "\n[fragment " << i << "] atta vertex count: " << fras[i].att_vert.size() << " | atta vertex: ";
        for (auto x: fras[i].att_vert) cout << x << ' ';
        cout << "\nfiled index list: ";
        for (auto x: fras[i].F) cout << x << ' '; 
        cout << "\nfragment graph:";
        for (const auto &[u, vs]: fras[i].graph) {
            cout << '\n' << u << ": ";
            for (int v: vs) cout << v << ' ';
        }
    }
    cout << "\n";
}

void show_subgraph() {
    cout << "\nsubgraph H:\n";
    for (int u = 1; u <= n; u++) {
        for (int v: h[u]) {
            if (u >= v) continue;
            cout << u << ' ' << v << '\n';
        }
    }
}

// find a cycle path
bool find_cycle(int u, int p) {
    cout << "\np: " << p << " u: " << u;
    if (st[u]) {
        cycle_path.push_back(u);
        return true;
    }
    st[u] = true;
    cycle_path.push_back(u);
    for (int v: g[u]) {
        if (v != p && find_cycle(v, u)) {
            return true;
        }
    }
    cycle_path.pop_back();
    return false;
}

// build subgraph H from cycle and add field boundary
void build_H() {
    int end_node = cycle_path.back();
    assert(count(cycle_path.begin(), cycle_path.end(), end_node) == 2);
    int start_index = -1;
    for (int i = 0; i < cycle_path.size(); i++) {
        if (cycle_path[i] == end_node) {
            start_index = i;
            break;
        }
    }
    // build graph & embed
    list<int> boundary{end_node};
    for (int i = start_index; i + 1 < cycle_path.size(); i++) {
        int u = cycle_path[i], v = cycle_path[i + 1];
        h[u].push_back(v); h[v].push_back(u);
        boundary.push_back(v);
    }
    field.push_back(boundary);  // inside
    field.push_back(boundary);  // outside
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (g[i].size() != h[i].size()) return true;
    }
    return false;
}

// dfs to get connected component
void get_component(int u, unordered_set<int>& vs) {
    st[u] = true;
    vs.insert(u);
    for (int v: g[u]) {
        if (st[v]) continue;
        get_component(v, vs);
    }
}

vector<unordered_set<int> > get_component_fragment_verts() {
    vector<unordered_set<int> > verts;
    memset(st, false, sizeof st);
    for (int u = 1; u <= n; u++) {
        if (!h[u].empty()) st[u] = true;
    }
    for (int u = 1; u <= n; u++) {
        if (st[u]) continue;
        // cout << "\nstart find component at: " << u;
        unordered_set<int> vs;
        get_component(u, vs);
        verts.emplace_back(vs);
    }
    return verts;
}

void get_fragments() {
    // connected component
    vector<unordered_set<int> > verts = get_component_fragment_verts();
    // case 1: edge with two verts all in H
    for (int u = 1; u <= n; u++) {
        for (int v: g[u]) {
            if (u >= v) continue;
            if (!h[u].empty() && !h[v].empty() && !count(h[u].begin(), h[u].end(), v)) {
                Fragment fra;
                fra.att_vert = {u, v};
                fra.graph[u].insert(v); fra.graph[v].insert(u);
                fras.push_back(fra);
            }
        }
    }
    // case 2: connected component and edge with one vert in H
    for (auto vs: verts) {
        cout << "\nconnected component vertex: ";
        for (auto u: vs) cout << u << ' ';
        Fragment fra;
        for (auto u: vs) {
            for (int v: g[u]) {
                if (!h[v].empty()) fra.att_vert.insert(v);
                fra.graph[u].insert(v); fra.graph[v].insert(u);
            }
        }
        fras.push_back(fra);
    }
}

bool get_path_dfs(int u, int p, int target, unordered_map<int, unordered_set<int>> graph, vector<int>& path) {
    // cout << "\np: " << p << " u: " << u;
    if (u == target) {
        // cout << "\n";
        // for (int x: path) cout << x << ' ';
        path.push_back(target);
        return true;
    }
    st[u] = true;
    path.push_back(u);
    for (int v: graph[u]) {
        if (v == p || st[v]) continue;
        if (get_path_dfs(v, u, target, graph, path)) {
            return true;
        }
    }
    path.pop_back();
    st[u] = false;
    return false;
}

void embed_plane(vector<int> P, int B, int f) {
    list<int> old = field[f];
    list<int> newa, newb;
    list<int>::iterator it1, it2;
    int cnt = 0;
    for (auto it = old.begin(); it != old.end() && cnt < 2; it++) {
        if (*it == P[0] || *it == P.back()) {
            if (cnt == 0) {
                it1 = it;
                cnt ++;
            } else {
                it2 = it;
                cnt ++;
            }
        }
    }
    // cout << '\n';
    // cout << *it1 << ' ' << *it2;
    int dir = 0;
    if (*it1 == P.back()) dir = 1;

    // newa
    for (auto it = old.begin(); it != it1; it++) {/*cout << *it << ' ';*/ newa.push_back(*it);}
    if (dir == 1) {
        for (auto it = P.rbegin(); it != P.rend(); ++it ) {/*cout << *it << ' ';*/ newa.push_back(*it);}
    } else {
        for (auto x: P) {/* cout << x << ' '; */ newa.push_back(x);}
    }
    for (auto it = next(it2, 1); it != old.end(); it++) {/*cout << *it << ' ';*/ newa.push_back(*it);}

    // newb
    for (auto it = it1; it != it2; it++) {/*cout << *it << ' ';*/ newb.push_back(*it);}
    if (dir == 1) {
        for (auto x: P) {/* cout << x << ' '; */ newb.push_back(x);}
    } else {
        for (auto it = P.rbegin(); it != P.rend(); ++it ) {/*cout << *it << ' ';*/ newb.push_back(*it);}
    }

    cout << "\nnewa: ";
    for (auto x: newa) cout << x <<  ' ';
    cout << "\nnewb: ";
    for (auto x: newb) cout << x <<  ' ';

    // update field
    field.erase(field.begin() + f);
    field.push_back(newa), field.push_back(newb);
    // updata subgraph H
    for (int i = 0; i + 1 < P.size(); i ++) {
        int u = P[i], v = P[i + 1];
        h[u].push_back(v);
        h[v].push_back(u);
    }
}

bool DMP() {
    // 1. find a cycle
    memset(st, false, sizeof st);
    int start = 1;
    // int start = 3;
    cout << "find cycle start from: " << start;
    find_cycle(start, 0);
    show_cycle_path();
    build_H();

    int iter_cnt = 0;
    while (check()) {
        cout << "\n------------------------------ iter_cnt " << iter_cnt << " -------------------------------------";
        // 2. get fragment
        fras.clear();
        get_fragments();

        show_field_boundary();
        show_subgraph();

        // 3. choose fragment
        int B = -1;  // chosen fragment index
        for (int i = 0; i < fras.size(); i++) {
            for (int j = 0; j < field.size(); j++) {
                unordered_map<int, bool> check_att;
                for (auto u: field[j]) check_att[u] = true;
                bool flag = true;
                for (auto u: fras[i].att_vert) {
                    if (!check_att[u]) {
                        flag = false;
                        continue;
                    }
                }
                if (flag) fras[i].F.push_back(j);
            }
            // return false when a fragment cant be planarized
            if (fras[i].F.empty()) {
                return false;
            } else if (fras[i].F.size() == 1) {
                B = i;
            }
        }
        if (B == -1) B = 0;
        show_fragments();

        // 4. choose path
        int cnt = 0, U, V;
        for (auto x: fras[B].att_vert) {
            // cout << x << ' ';
            if (cnt == 0) U = x;
            else if (cnt == 1) V = x;
            else break;
            cnt ++;
        }
        cout << "\nB: " << B << " U: " << U << " V: " << V;

        memset(st, false, sizeof st);
        vector<int> P;
        get_path_dfs(U, 0, V, fras[B].graph, P);
        cout << "\nfouned path: ";
        for (int x: P) cout << x << ' ';

        // 5. embed
        int f = fras[B].F[0];  // field index: filed[f]
        cout << "\nf: " << f;
        embed_plane(P, B, f);        

        iter_cnt++;
        // if (iter_cnt > 1) break;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (DMP()) cout << "\n\n" << 1 << endl;
    else cout << "\n\n" << 0 << endl;
    return 0;
}