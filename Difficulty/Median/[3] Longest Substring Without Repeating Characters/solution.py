#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (27.97%)
# Total Accepted:    866.4K
# Total Submissions: 3.1M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# 
# Example 1:
# 
# 
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# 
# 
# 
# Example 2:
# 
# 
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# 
# 
# 
# Example 3:
# 
# 
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
# â             Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
# 
# 
# 
# 
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        longest_sub_str = ''
        for i, elem in enumerate(s):
            longest_sub_str += elem
            if len(longest_sub_str) > 1:
                if elem in longest_sub_str[:-1]:
                    if max_length < len(longest_sub_str) - 1:
                        max_length = len(longest_sub_str) - 1
                    same_char_index = longest_sub_str[:-1].find(longest_sub_str[-1])
                    longest_sub_str = longest_sub_str[same_char_index+1:]
        if len(longest_sub_str) > max_length:
            return len(longest_sub_str)
        else:
            return max_length
        

