#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#
# https://leetcode.com/problems/search-insert-position/description/
#
# algorithms
# Easy (40.47%)
# Total Accepted:    376.9K
# Total Submissions: 928.6K
# Testcase Example:  '[1,3,5,6]\n5'
#
# Given a sorted array and a target value, return the index if the target is
# found. If not, return the index where it would be if it were inserted in
# order.
# 
# You may assume no duplicates in the array.
# 
# Example 1:
# 
# 
# Input: [1,3,5,6], 5
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: [1,3,5,6], 2
# Output: 1
# 
# 
# Example 3:
# 
# 
# Input: [1,3,5,6], 7
# Output: 4
# 
# 
# Example 4:
# 
# 
# Input: [1,3,5,6], 0
# Output: 0
# 
# 
#
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target <= nums[0]:
            return 0
        nums_len = len(nums)
        if target > nums[nums_len - 1]:
            return nums_len
        left = 0
        right = nums_len - 1
        temp = right // 2
        while temp != left:
            if nums[temp] > target:
                right = temp
            elif nums[temp] == target:
                return temp
            else:
                left = temp
            temp = (left + right) // 2
        if target < nums[left]:
            return left
        elif target > nums[right]:
            return right + 1
        else:
            return right