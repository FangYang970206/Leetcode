#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        cur1 = head
        res = cur2 = ListNode(0)
        length = 1
        while (cur1.next != None):
            length += 1
            cur1 = cur1.next
        for i in range(length - n):
            cur2.next = ListNode(0)
            cur2.next.val = head.val
            head = head.next
            cur2 = cur2.next
        cur2.next = head.next
        return res.next