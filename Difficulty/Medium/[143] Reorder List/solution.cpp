/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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

#include <vector>

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> vec;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *move = slow->next;
        while (move){
            vec.push_back(move);
            move = move->next;
        }
        slow->next = nullptr;
        cout << vec.size() << endl;
        ListNode* prev = head;
        while (!vec.empty()) {
            ListNode* tmp = prev->next;
            ListNode* node_move = vec.back();
            vec.pop_back();
            prev->next = node_move;
            node_move->next = tmp;
            prev = tmp;
        }
    }
};
// @lc code=end

