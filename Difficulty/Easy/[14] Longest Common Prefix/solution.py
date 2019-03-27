#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (33.03%)
# Total Accepted:    427.1K
# Total Submissions: 1.3M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        list_len = len(strs)
        str_min_len = len(strs[0])
        for i in range(1, list_len):
            if len(strs[i]) < str_min_len:
                str_min_len = len(strs[i])
        for i in range(str_min_len):
            for j in range(list_len - 1):
                if strs[j][i] == strs[j+1][i]:
                    if j == list_len - 2 and i+1 == str_min_len:
                        return strs[j][:(i+1)]
                else:
                    if not strs[j][:i]:
                        return ""
                    else:
                        return strs[j][:i]
        return ""