#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1;
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        if len(nums) == 2:
            if nums[0] != target:
                return 1 if nums[1] == target else -1
            if nums[1] != target:
                return 0 if nums[0] == target else -1
        l, m, r = 0, 0, len(nums) - 1
        if nums[r] < nums[l]:
            while l < r:
                m = (l + r) // 2
                if nums[m] == target:
                    return m
                if m == 0:
                    if nums[0] < nums[1]:
                        m = 1
                        break
                    else:
                        break
                else:
                    if nums[m] > nums[m - 1] and nums[m] > nums[m + 1]:
                        break
                    elif nums[m] > nums[len(nums) - 1]:
                        l = m + 1
                    else:
                        r = m - 1
            m = l if l == r else m
            if target > nums[0]:
                return self.binary_search(nums[:m+1], target)
            elif target < nums[0]:
                ind = self.binary_search(nums[m+1:], target)
                return -1 if ind == -1 else m + 1 + ind
            else:
                return 0
            return -1
        else:
            return self.binary_search(nums, target)

    def binary_search(self, nums: List[int], target: int) -> int:
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] == target:
                return l
            if nums[r] == target:
                return r
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            elif nums[m] == target:
                return m
            else:
                r = m - 1
        return -1

