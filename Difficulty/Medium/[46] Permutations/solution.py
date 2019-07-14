class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        size = len(nums)
        self.permutation(res, 0, size, nums)
        return res
    
    def permutation(self, res, begin, size, nums):
        if begin == size - 1:
            res.append(nums[:])
            return
        for i in range(begin, size):
            nums[begin], nums[i] = nums[i], nums[begin]
            self.permutation(res, begin + 1, size, nums)
            nums[begin], nums[i] = nums[i], nums[begin]