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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* l3 = head;
        bool carry_flag = 0;
        int temp = 0;
        while( l1 && l2){
            l3->next = new ListNode(0);
            l3 = l3->next;
            temp = l1->val + l2->val + carry_flag;
            if (temp < 10){
                l3->val = temp;
                carry_flag = 0;
            }
            else{
                l3->val = temp - 10;
                carry_flag = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1){
            l3->next = l1;
            carry_flag = control_carry(carry_flag, l3);
        }
        if (l2){
            l3->next = l2;
            carry_flag = control_carry(carry_flag, l3);
        }
        if (!l1 && !l2){
            if (carry_flag == 1)
                l3->next = new ListNode(1);
        }
        if (carry_flag == 1)
            l3->next = new ListNode(1);
        return head->next;
    }
    
    bool control_carry(bool carry_flag, ListNode*& l3){
        int temp1;
        while(carry_flag){
            if (l3->next)
                l3 = l3->next;
            else
                break;
            temp1 = l3->val + carry_flag;
            if (temp1 < 10){
                l3->val = temp1;
                carry_flag = 0;
            }
            else{
                l3->val = temp1 - 10;
                carry_flag = 1;
            }
        }
        return carry_flag;
    }
};