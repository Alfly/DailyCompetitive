#include <iostream>
#include <vector>
using namespace std;

void show(vector<int>& a, int n, int pos, int nextpos) {
    for (int i = pos; i < n; i++) cout << a[i] << ' ';
    for (int i = 0; i < pos; i++) cout << a[i] << ' ';
    cout << "(" << a[nextpos] << ")";
    cout << endl;
}

// 数组模拟过程
void Josephus_array(int n, int m) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    int pos = 0, nextpos = 0;
    while (n > 0) {
        nextpos = (pos + m - 1) % n;
        show(a, n, pos, nextpos);
        pos = nextpos;
        for (int i = pos; i + 1 < n; i++) {
            a[i] = a[i + 1]; 
        }
        n--;
    }
}

// 链表模拟过程
void Josephus_list(int n, int m) {

}

// 递推求得最后一个在座的成员位置 f(n) = (f(n-1) + m - 1) % n
void Josephus_finalpos(int n, int m) {
    int pos = 0; // 最后存活的位置 0
    // 进行 n - 1 轮
    for (int t = 2; t <= n; t++) {
        cout << pos << endl;
        pos = (pos + m) % t;
    }
    cout << pos << endl;
}

void Josephus_finalpos2(int n, int m) {
    int pos = 0; // 最后存活的位置 0
    // 进行 n - 1 轮
    for (int t = 2; t <= n; t++) {
        cout << pos << endl;
        if (pos + m < t) {
            int delta = (t - pos) / m;
            delta = min(delta, n - t);
            t += delta;
            pos += delta * m;
        }
        pos = (pos + m) % t;
    }
    cout << pos << endl;
}

int main() {
    // int N = 39, M = 3;
    int N = 11, M = 3;

    Josephus_array(N, M);
    cout << "------" << endl;
    Josephus_finalpos(N, M);
    cout << "------" << endl;
    Josephus_finalpos2(N, M);

    return 0;
}

/* 
https://zhuanlan.zhihu.com/p/35487124
https://blog.csdn.net/u011500062/article/details/72855826
 */