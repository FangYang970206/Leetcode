#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums or target < nums[0] or target > nums[-1]:
            return [-1, -1]
        li, hi = 0, len(nums) - 1
        while li < hi:
            mid = (li + hi) // 2
            if nums[mid] == target:
                break
            elif nums[mid] > target:
                hi = mid - 1
            else:
                li = mid + 1
        if li == hi:
            return [-1, -1] if nums[li] != target else [li, li]
        else:
            li, hi = mid, mid
            while True:
                if li == 0:
                    break
                if nums[li - 1] == nums[mid]:
                    li -= 1
                else:
                    break
            while True:
                if hi == len(nums) - 1:
                    break
                if nums[hi + 1] == nums[mid]:
                    hi += 1
                else:
                    break
            return [li, hi]