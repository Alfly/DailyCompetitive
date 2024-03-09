#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node* mergetwo(Node *l1, Node *l2) {
    Node *h = new Node(), *p = h;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return h->next;
}

Node* mergeKList1(vector<Node*>& lists) {
    Node *ans = nullptr;
    for (int i = 0; i < lists.size(); i++) {
        ans = mergetwo(ans, lists[i]);
    }
    return ans;
}

Node* binaryMerge(vector<Node*>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    Node *t1 = binaryMerge(lists, l, mid);
    Node *t2 = binaryMerge(lists, mid + 1, r);
    return mergetwo(t1, t2);
}

Node* mergeKList2(vector<Node*>& lists) {
    int n = lists.size();
    return binaryMerge(lists, 0, n - 1);
}

struct greaterCmp {
    bool operator() (const Node* a, const Node* b) const {
        return a->val > b->val;
    }
};

Node* mergeKList3(vector<Node*>& lists) {
    int n = lists.size();
    priority_queue<Node*, vector<Node*>, greaterCmp> q;
    for (Node* h: lists) {
        q.push(h);
    }
    Node *head = new Node(), *cur = head;
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        cur->next = t;
        if (t->next) q.push(t->next);
        cur = cur->next;
    }
    return head->next;
}

int main() {
    int k, n, x; 
    cin >> k;
    vector<Node*> lists;
    for (int i = 0; i < k; i++) {
        cin >> n;
        Node* h = new Node(), *p = h;
        while (n--) {
            cin >> x;
            p->next = new Node(x);
            p = p->next;
        }
        lists.push_back(h->next);
    }

    // Node *res = mergeKList1(lists);
    // Node *res = mergeKList2(lists);
    Node *res = mergeKList3(lists);

    // ouput
    Node *p = res;
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }

    return 0;
}

/*
[[1,4,5],[1,3,4],[2,6]]
3
3 1 4 5
3 1 3 4
2 2 6
*/