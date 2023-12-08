/* 
154. 滑动窗口
https://www.acwing.com/problem/content/156/
 */

#include <iostream>
#include <deque>
using namespace std;

const int N = 1e6+10;
int a[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // MIN
    deque<int> deq;   // 双向队列存下标
    for (int i = 0; i < n; i++) {
        // 判断队头是否滑出窗口
        if (!deq.empty() && i - k + 1 > deq.front()) deq.pop_front();
        
        while(!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
        
        deq.push_back(i);
        
        if (i >= k - 1) cout << a[deq.front()] << ' ';
    }
    cout << '\n';
    
    // MAX
    deq.clear();
    for (int i = 0; i < n; i++) {
        if (!deq.empty() && i - k + 1 > deq.front()) deq.pop_front();
        
        while(!deq.empty() && a[deq.back()] <= a[i]) deq.pop_back();
        
        deq.push_back(i);
        
        if (i >= k - 1) cout << a[deq.front()] << ' ';
    }
    
    return 0;   
}

/* 数组模拟双向队列

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int n, k;
int a[N], q[N]; // q 队列记录下标

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++ i) scanf("%d", &a[i]);
    
    // MIN
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ ){
        // 判断队头是否滑出窗口
        if(hh <= tt && i - k  + 1 > q[hh]) 
            ++ hh;
        // 只要队列里有元素，且尾元素比待处理值大，即尾元素已经不可能成为最小值，出队
        // 直到尾元素小于待处理值，满足"单调"。
        while(hh <= tt && a[q[tt]] >= a[i])
            -- tt;
        q[++ tt] = i;
        if(i >= k - 1) 
            printf("%d ", a[q[hh]]);
    }
    printf("\n");
    
    // MAX
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ ){
        // 判断队头是否滑出窗口
        if(hh <= tt && i - k  + 1 > q[hh]) 
            ++ hh;
        while(hh <= tt && a[q[tt]] <= a[i])
            -- tt;
        q[++ tt] = i;
        if(i >= k - 1) 
            printf("%d ", a[q[hh]]);
    }
    
    return 0;
}
 */