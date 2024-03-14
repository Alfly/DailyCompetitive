#include <iostream>
#include <queue>
// #include<cstring>
using namespace std;

struct Node {
    int val;
    int x;
    // bool operator < (const Node &w) const {
    //     return val > w.val;
    // }
};

struct greaterCmp {
    bool operator() (const Node& a, const Node& b) const {
        return a.val > b.val;
    }
};

int main() {
    priority_queue<Node, vector<Node>, greaterCmp> heap;

    heap.push({1, 2});
    heap.push({2, 2});
    heap.push({3, 2});
    heap.push({4, 2});

    auto [val, x] = heap.top(); heap.pop();

    cout << val;

    return 0;
}