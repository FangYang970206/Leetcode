/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur1 = head;
        ListNode* cur2 = new ListNode(0);
        ListNode* res = cur2;
        int length = 1;
        while (cur1->next != NULL){
            length += 1;
            cur1 = cur1->next;
        }
        for (int i = 0; i < length - n; i++){
            cur2->next = new ListNode(0);
            cur2->next->val = head->val;
            head = head->next;
            cur2 = cur2->next;
        }
        cur2->next = head->next;
        return res->next;
    }
};

// ref https://leetcode.com/problems/remove-nth-node-from-end-of-list/solution/
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for (int i = 1; i <= n + 1; i++){
            first = first->next;
        }
        while (first != NULL){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};