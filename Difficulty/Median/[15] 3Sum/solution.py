#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        res = []
        nums = sorted(nums)
        nums_set = []
        nums_set.append(nums[0])
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums_set.append(nums[i])
        dict = {num: 0 for num in nums_set}
        for num in nums:
            dict[num] += 1
        short_len = 0
        for i, num in enumerate(nums_set):
            if num >= 0:
                short_len = i
                break
        for i, target in enumerate(nums_set[:short_len]):
            dict[target] -= 1
            for j in range(i, len(nums_set)):
                dict[nums_set[j]] -= 1
                find_value = -target - nums_set[j]
                if find_value < nums_set[j] or nums_set[j] > abs(target):
                    dict[nums_set[j]] += 1
                    break;
                if find_value in dict and find_value >= nums_set[j] and dict[nums_set[j]] >= 0 and dict[find_value] != 0:
                    res.append([target, nums_set[j], find_value])
                dict[nums_set[j]] += 1
        if dict.get(0, 0) >= 3:
            res.append([0, 0, 0])
        return res