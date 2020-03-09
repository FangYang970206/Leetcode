class Solution:
    def reverseBits(self, n: int) -> int:
        left, right = 0x80000000, 0x00000001
        while left > right:
            left_bit = n & left
            right_bit = n & right
            if left_bit == 0:
                n &= ~right
            else:
                n |= right
            if right_bit == 0:
                n &= ~left
            else:
                n |= left
            left >>= 1
            right <<= 1
        return n