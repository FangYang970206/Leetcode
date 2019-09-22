#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        m, n, pre, count = min(m, n), max(m, n), [], 1
        new_head = ListNode(0)
        new_head.next = head
        while head is not None:
            if count >= m and count < (n + m + 1) // 2:
                pre.append(head)
            if count > (m + n) // 2 and count <= n:
                head.val, pre[n - count].val = pre[n - count].val, head.val
            count += 1
            head = head.next
        return new_head.next
        
        

