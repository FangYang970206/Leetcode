/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount){
            for (int i = 0; i < amount - interval; i += interval * 2)
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        if (amount > 0)
            return lists[0];
        else
            return nullptr;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (! l1) return l2;
        if (! l2) return l1;
        if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};