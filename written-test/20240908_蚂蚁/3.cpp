#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/*
1: 1
2: 1 2
3: 1 2 3 1
4: 1 2 3 4 1 3 [2 4]
5: 1 2 3 4 5 1 4 2 5 3 1
6: 1 2 3 4 5 6 1 5 2 6 3 1 4 2 [4 5] [4 6]

长度：1 2 4 8 11 18

转换为n个节点的全连通图，求欧拉回路：欧拉回路要求无向图的奇数度的点最多有2个(起点+终点)
- 如果是奇数节点，从哪个节点开始都可以形成欧拉回路，结果为 (n-1) * n / 2 + 1;
- 如果是偶数节点，构建 n/2 - 1 条虚拟边，可以形成欧拉回路，结果为 (n-1) * n / 2 + (n/2 - 1) + 1 = n * n / 2;
*/

int main() {
    int d; cin >> d;
    if (d & 1) cout << d * (d - 1) / 2 + 1 << endl;
    else cout << d * d / 2 << endl;
    return 0;
}
