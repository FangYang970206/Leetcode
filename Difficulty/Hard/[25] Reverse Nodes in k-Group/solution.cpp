/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (! head || ! head->next) return head;
        int num = 0;
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode *pre = res, *cur = res, *nex;
        while(cur = cur->next) num += 1;
        while(num >= k){
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            num -= k;
        }
        return res->next;
    }
};