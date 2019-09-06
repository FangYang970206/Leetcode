class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res, tmp, = [[]], []
        for i in range(len(nums)):
            self.subsets_helper(res, tmp, nums, 0, i+1)
        return res
    
    def subsets_helper(self, res, tmp, nums, begin, num):
        if len(tmp) == num:
            res.append(tmp[:])
            return
        for i in range(begin, len(nums)):
            tmp.append(nums[i])
            self.subsets_helper(res, tmp, nums, i+1, num)
            tmp.pop()