class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        length, i = n - m, 0
        while length:
            n &= ~(1 << i)
            i += 1
            length >>= 1
        return m & n