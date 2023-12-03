/* 
827. 双链表
https://www.acwing.com/problem/content/description/829/
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int e[N], l[N], r[N], idx;

void init() {
    // 两个特殊节点 0: head  1: tail
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// add(k, x)    在第 k 个插入的数 右侧 插入一个数 x
// add(l[k], x) 在第 k 个插入的数 左侧 插入一个数 x
void add(int k, int x) {
    e[idx] = x, l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// 删除第 k 个插入的数
void removeK(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    init();
    int n;
    cin >> n;
    string op;
    int x, k;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "L") {
            cin >> x;
            add(0, x);
        } else if (op == "R") {
            cin >> x;
            add(l[1], x);
        } else if (op == "IR") {
            cin >> k >> x;
            add(k + 1, x);      // 1 -> idx=2
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        } else if (op == "D") {
            cin >> k;
            removeK(k + 1);
        }
    }
    // 遍历输出
    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }
    return 0;
}