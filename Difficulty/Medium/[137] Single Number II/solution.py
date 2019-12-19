class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        x1, x2, mask = 0, 0, 0
        for num in nums:
            x2 ^= x1 & num
            x1 ^= num
            mask = ~(x1 & x2)
            x2 &= mask
            x1 &= mask
        return x1