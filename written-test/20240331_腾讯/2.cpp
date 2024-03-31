/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param lists ListNode类vector 
     * @return bool布尔型vector
     */
    vector<bool> canSorted(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<bool> ans;
        for (ListNode* head: lists) {
            ListNode *p = head;
            int dec = 0;
            int firstVal = p->val;
            while (p && p->next) {
                if (p->val > p->next->val) {
                    dec++;
                }
                p = p->next;
            }
            int lastVal = p->val;
            bool ok = (dec == 0) || (dec == 1 && firstVal > lastVal);
            ans.push_back(ok);
        }
        return ans;
    }
};