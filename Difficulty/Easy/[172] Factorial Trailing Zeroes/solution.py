class Solution:
    def trailingZeroes(self, n: int) -> int:
        count, num, m = 0, 5, {5: 1}
        while num <= n:
            num *= 5
            m[num] = m[num // 5] * 5 + 1
        while n >= 5:
            num //= 5
            q = n // num
            if q != 0:
                n -= num * q
                count += m[num] * q
        return count