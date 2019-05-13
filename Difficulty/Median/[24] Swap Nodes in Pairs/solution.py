#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return None
        if not head.next:
            return head
        res = cur = ListNode(0)
        while head and head.next:
            cur.next = head.next
            head.next = head.next.next
            cur.next.next = head
            head = head.next
            cur = cur.next.next
        return res.next