#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

const int N = 410;
int a[N];
int n, k;

struct Node {
    int l, r;
    int val;
    Node(int _l, int _r, int _val) {
        l = _l;
        r = _r;
        val = _val;
    }
};

// struct greaterCmp {
//     bool operator() (const Node& a, const Node& b) const {
//         return a.val > b.val;
//     }
// };

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // priority_queue<Node, vector<Node>, greaterCmp> q;
    list<Node> q;

    for (int i = 0; i < n; i++) {
        int j = i + 1, t = a[i], s = a[i];
        while (j < n && (t ^ a[j]) == (s + a[j])) {
            t ^= a[j];
            s += a[j];
            j++;
        }
        // printf("%d %d\n", i, j);
        q.emplace_back(Node(i, j, t));
        i = j - 1;
    }

    // while (q.size() > k) {
        
    // }
    // cout << q.size();
    
    if (k == 2) {
        int l = 0, ans = 0;
        for (int r = 0; r < n - 1; r++) {
            int leftval = 0, rightval = 0;
            for (int i = 0; i <= r; i++) leftval ^= a[i];
            for (int i = r + 1; i < n; i++) rightval ^= a[i];
            ans = max(ans, leftval + rightval);
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        for (auto &node: q) {
            ans += node.val;
        }
        cout << ans << endl;
    }
    
    return 0;
}

/* 11.54% */