#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;

    set<int> red_lines({1, n});
    multiset<int> segments({n - 1});

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x; cin >> x;
            // 找到插入位置前后的红线
            auto it_right = red_lines.lower_bound(x);
            auto it_left = prev(it_right);
            // 删除旧段长
            int old_len = *it_right - *it_left;
            segments.erase(segments.find(old_len));
            // 更新段长
            int segment1 = x - *it_left;
            int segment2 = *it_right - x;
            segments.insert(segment1);
            segments.insert(segment2);
            // 添加红线
            red_lines.insert(x);
        } else {
            int k; cin >> k;
            // 获取当前段长的最大值
            int max_len = *segments.rbegin();
            if (max_len >= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
/*
8 7
2 7
1 4
2 4
2 5
1 6
2 3
2 4

YES
YES
NO
YES
NO
*/
