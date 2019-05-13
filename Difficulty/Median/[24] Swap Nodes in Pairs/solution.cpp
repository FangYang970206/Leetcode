class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (! head) return nullptr;
        if (! head->next) return head;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (head and head->next){
            cur->next = head->next;
            head->next = head->next->next;
            cur->next->next = head;
            head = head->next;
            cur = cur->next->next;
        }
        return res->next;
    }
};