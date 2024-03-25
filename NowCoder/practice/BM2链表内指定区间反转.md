## [BM2 链表内指定区间反转](https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=295&tqId=654&ru=/exam/company&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Fcompany)

```cpp
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p0 = dummy;
        // p0 为 p 前一个节点
        for (int i = 0; i < m - 1; i++) p0 = p0->next;
        
        ListNode* pre = nullptr, * cur = p0->next;
        // 需要翻转 n - m + 1 次
        for (int i = 0; i <= n - m; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p0->next->next = cur;
        p0->next = pre;

        return dummy->next;
    }
};
```