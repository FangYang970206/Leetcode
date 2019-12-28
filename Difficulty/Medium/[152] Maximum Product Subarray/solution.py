class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0
        r = nums[0]
        imax, imin = r, r
        for i in range(1, len(nums)):
            if nums[i] < 0:
                imax, imin = imin, imax
            imax = max(nums[i], imax * nums[i])
            imin = min(nums[i], imin * nums[i])
            r = max(r, imax)
        return r