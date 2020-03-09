class Solution:
    def hammingWeight(self, n: int) -> int:
        num = 0
        while n:
            num += n & 1;
            n >>= 1
        return num