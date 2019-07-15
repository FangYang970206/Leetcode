class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        size = len(nums)
        self.permutation(res, 0, size, nums)
        return res
    
    def permutation(self, res, begin, size, nums):
        if begin == size - 1:
            res.append(nums[:])
            return
        record = set()
        for i in range(begin, size):
            if nums[i] in record:
                continue
            record.add(nums[i])
            nums[begin], nums[i] = nums[i], nums[begin]
            self.permutation(res, begin + 1, size, nums)
            nums[begin], nums[i] = nums[i], nums[begin]