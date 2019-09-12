/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode* pre = new ListNode(0);
		ListNode* move_ptr = head;
		pre->next = head;
		ListNode* new_head = pre;
		int num = 0;
		while (move_ptr->next != nullptr) {
			if (move_ptr->val == move_ptr->next->val) {
				num++;
				move_ptr = move_ptr->next;
				if (move_ptr->next == nullptr)
					pre->next = move_ptr;
			}
			else {
				if (num > 0) {
					pre->next = move_ptr;
                    pre = pre->next;
					move_ptr = move_ptr->next;
					num = 0;
				}
				else {
					pre = move_ptr;
					move_ptr = move_ptr->next;
				}
			}
		}
		return new_head->next;
	}
};

