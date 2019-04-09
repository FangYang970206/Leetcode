#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (30.63%)
# Total Accepted:    821K
# Total Submissions: 2.7M
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# Example:
# 
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
# 
# 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = l3 = ListNode(0)
        carry_flag = 0
        while( l1 and l2 ):
            l3.next = ListNode(0)
            l3 = l3.next
            temp = l1.val + l2.val + carry_flag
            if temp < 10:
                l3.val = temp
                carry_flag = 0
            else:
                l3.val = temp - 10
                carry_flag = 1
            l1 = l1.next
            l2 = l2.next
        if l1:
            l3.next = l1
            carry_flag, l3 = self.control_carry(carry_flag, l3)
        if l2:
            l3.next = l2
            carry_flag, l3 = self.control_carry(carry_flag, l3)
        if not l1 and not l2:
            if carry_flag == 1:
                l3.next = ListNode(1)
        if carry_flag == 1:
            l3.next = ListNode(1)
        return head.next

    def control_carry(self, carry_flag, l3):
        while(carry_flag):
            if l3.next:
                l3 = l3.next
            else:
                break
            temp1 = l3.val + carry_flag
            if temp1 < 10:
                l3.val = temp1
                carry_flag = 0
            else:
                l3.val = temp1 - 10
                carry_flag = 1
        return carry_flag, l3