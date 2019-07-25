/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

//  * Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        if (k == 0 || head->next == nullptr) return head;
        ListNode* pre = head, *lst = head, *Trv = head;
        int length = 1;
        while (Trv->next != nullptr){
            Trv = Trv->next;
            length++;
        }
        int rotate_len = k % length;
        if (rotate_len == 0) return head;
        int pre_i = 0, lst_i = 0;
        while(lst->next != nullptr){
            lst = lst->next;
            if (lst_i - pre_i == rotate_len){
                pre = pre->next;
                pre_i++;
            }
            lst_i++;
        }
        ListNode* new_head = pre->next;
        pre->next = nullptr;
        lst->next = head;
        return new_head;
    }
};

