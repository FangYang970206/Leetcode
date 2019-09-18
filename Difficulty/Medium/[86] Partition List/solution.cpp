/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        vector<int> less_set, greater_set;
        ListNode* tmp = head;
        while(tmp != nullptr) {
            if (tmp->val < x)
                less_set.push_back(tmp->val);
            else
                greater_set.push_back(tmp->val);
            tmp = tmp->next; 
        }
        tmp = head;
        for (auto i : less_set){
            tmp->val = i;
            tmp = tmp->next;
        }
        for (auto i : greater_set){
            tmp->val = i;
            tmp = tmp->next;
        }
        return head;
    }
};

