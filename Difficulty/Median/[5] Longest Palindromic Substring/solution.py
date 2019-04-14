#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (26.65%)
# Total Accepted:    520.5K
# Total Submissions: 1.9M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
# 
# Example 1:
# 
# 
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: "cbbd"
# Output: "bb"
# 
# 
#
class Solution1:
    def longestPalindrome(self, s: str) -> str:
        longestPStr = ''
        for i in range(len(s), 0, -1):
            for j in range(len(s) - 1):
                if s[j:i] == s[::-1]:
                    if len(s[j:i]) > len(longestPStr):
                        longestPStr = s[j:i]
                if len(longestPStr) > i:
                    return longestPStr
        return longestPStr
                    
        
                


