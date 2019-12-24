/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
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
    ListNode* sortList(ListNode* head) {
        if (! head || ! head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        slow = sortList(slow);
        head = sortList(head);
        return merge(slow, head);
    }

    ListNode* merge(ListNode* h1, ListNode* h2) {
        // ListNode* new_head = new ListNode(0);
        // ListNode* node = new_head;
        //没有动态分配，速度提升了12ms, 内存减少一倍。
        ListNode new_head = ListNode(0); 
        ListNode* node = &new_head;
        while (h1 && h2) {
            if (h1->val > h2->val) {
                node->next = h2;
                h2 = h2->next;
            }else{
                node->next = h1;
                h1 = h1->next;
            }
            node = node->next;
        }
        if (h1) node->next = h1;
        if (h2) node->next = h2;
        return new_head->next;
    }
};
// @lc code=end

