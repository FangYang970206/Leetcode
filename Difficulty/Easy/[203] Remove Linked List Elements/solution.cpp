/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head; 
        ListNode *prev = new_head, *curr = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            }else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return new_head->next;
    }
};
// @lc code=end

