#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        res = ListNode(0)
        res.next = head
        nex = ListNode(0)
        pre = cur = res
        num = 0
        while(cur):
            cur = cur.next
            num += 1
        while(num > k):
            cur = pre.next
            nex = cur.next
            for _ in range(1, k):
                cur.next = nex.next
                nex.next = pre.next
                pre.next = nex
                nex = cur.next
            pre = cur
            num -= k
        return res.next