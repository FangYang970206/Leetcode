class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        if len(nums) < 2: return nums[0]
        r1, r2, tmp = nums[0], max(nums[0], nums[1]), 0
        for i in range(2, len(nums)):
            tmp = max(r2, r1 + nums[i])
            r1 = r2
            r2 = tmp
        return r2