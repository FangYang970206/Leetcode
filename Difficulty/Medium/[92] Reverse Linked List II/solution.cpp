/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        m = min(m, n);
        n = max(m, n);
        vector<ListNode*> pre((n - m + 1) / 2, nullptr);
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        int count = 1;
        while (head != NULL) {
            if (count >= m && count < (n + m + 1) / 2) {
                pre[count - m] = head;
            }
            if (count > (m + n) / 2 && count <= n){
                swapListNodeVal(pre[n - count], head);
            }
            count++;
            head = head->next;
        }
        return new_head->next;
    }

    void swapListNodeVal(ListNode *A, ListNode *B) {
        int tmp = A->val;
        A->val = B->val;
        B->val = tmp;
    }
};

