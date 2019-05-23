#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.reverse()
        if nums != sorted(nums):
            ind_pre, ind_exchange = len(nums), len(nums)
            for i, ele in enumerate(nums):
                targ = self.find_if(nums, i)
                if targ != len(nums):
                    if ind_exchange > targ:
                        ind_exchange = targ
                        ind_pre = i
                if i >= ind_exchange:
                    nums[ind_exchange], nums[ind_pre] = nums[ind_pre], nums[ind_exchange]
                    nums[:ind_exchange] = sorted(nums[:ind_exchange], reverse=True)
                    nums.reverse()
                    break

    def find_if(self, nums, begin_ind):
        for i, e in enumerate(nums[begin_ind:], start=begin_ind):
            if e < nums[begin_ind]:
                return i
        return len(nums)

