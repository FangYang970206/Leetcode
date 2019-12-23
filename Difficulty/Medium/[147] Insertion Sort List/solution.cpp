/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (! head) return nullptr;
        ListNode* prev = head;
        ListNode* next = nullptr;
        ListNode* cur = head->next;
        ListNode* new_head = ListNode(0);
        new_head->next = head;
        while (cur) {
            if (cur->val >= prev->val){
                prev = cur;
                cur = cur->next;
            }else{
                next = cur->next;
                cur->next = nullptr;
                prev->next = next;
                ListNode* tmp_prev = new_head;
                ListNode* tmp = new_head->next;
                while (1) {
                    if (tmp->val > cur->val){
                        tmp_prev->next = cur;
                        cur->next = tmp;
                        break;
                    }else{
                        tmp_prev = tmp;
                        tmp = tmp->next;
                    }
                }
                cur = next;
            }
        }
        return new_head->next;
    }
};
// @lc code=end

