#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (25.15%)
# Total Accepted:    618.4K
# Total Submissions: 2.5M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [âˆ’231,Â  231Â âˆ’ 1]. For the purpose of
# this problem, assume that your function returns 0 when the reversed integer
# overflows.
# 
#
class Solution1:
    def reverse(self, x: int) -> int:
        if x==0:
            return 0

        max = 2**31
        if x > max-1 or x < -max:
            return 0

        a = 0
        if x < 0:
            x = -x
            flag_neg = True
        else:
            flag_neg = False
        
        while(x != 0):
            a = a*10 + x%10
            x //= 10
        
        if a < max-1 and a > -max:
            return a if not flag_neg else -a
        else:
            return 0

class Solution2:
    def reverse(self, x: int) -> int:
        if x==0:
            return 0

        max = 2**31
        if x > max-1 or x < -max:
            return 0

        a = 0
        if x < 0:
            x = -x
            flag_neg = '-'
        else:
            flag_neg = ''
        
        a = int(flag_neg + str(x)[::-1])
        
        if a < max-1 and a > -max:
            return a
        else:
            return 0