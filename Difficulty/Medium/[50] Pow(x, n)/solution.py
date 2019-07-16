class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        AbsN = abs(n)
        while AbsN > 0:
            if AbsN & 1:
                res *= x
            AbsN >>= 1
            x *= x
        return res if n > 0 else 1 / res