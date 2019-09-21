class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res, tmp = [], []
        nums.sort()
        self.subsetsWithDup(res, nums, tmp, 0)
        return res
    
    def subsetsWithDupHelper(self, res, nums, tmp, begin):
        res.append(tmp[:])
        for i in range(begin, len(nums)):
            if i == begin or nums[i] != nums[i - 1]:
                tmp.append(nums[i])
                self.subsetsWithDupHelper(res, nums, tmp, i+1)
                tmp.pop()
        