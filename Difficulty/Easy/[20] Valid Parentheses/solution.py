#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (35.94%)
# Total Accepted:    541.1K
# Total Submissions: 1.5M
# Testcase Example:  '"()"'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# 
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# 
# 
# Note that an empty string isÂ also considered valid.
# 
# Example 1:
# 
# 
# Input: "()"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: "()[]{}"
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: "(]"
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: "([)]"
# Output: false
# 
# 
# Example 5:
# 
# 
# Input: "{[]}"
# Output: true
# 
# 
#
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        if len(s) % 2 != 0:
            return False
        parenthese = ['()', '{}', '[]']
        if len(s) == 2:
            return s in parenthese
        from collections import deque
        mis_parenthese = ['[)', '[}', '(]', '(}', '{]', '{)']
        deque1 = deque()
        deque2 = deque()
        for elem in s:
            deque1.append(elem)
        temp1 = deque1.pop()
        temp2 = deque1.pop()
        while(deque1):
            if (temp2+temp1) in parenthese:
                if deque2:
                    temp1 = deque2.pop()
                    temp2 = deque1.pop()
                else:
                    temp1 = deque1.pop()
                    temp2 = deque1.pop()
            elif (temp2+temp1) in mis_parenthese:
                return False
            else:
                deque2.append(temp1)
                temp1 = temp2
                temp2 = deque1.pop()
            
        if (not deque2) and (temp2+temp1) in parenthese:
            return True
        else:
            return False