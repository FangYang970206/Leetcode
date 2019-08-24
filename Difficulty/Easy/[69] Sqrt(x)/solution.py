# 二分法
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        mid, left, right = x // 2, 0, x
        while left < right:
            if mid > x // mid:
                right = mid
            elif mid < x // mid:
                left = mid
            else:
                return mid
            mid = (left + right) // 2
            if mid == left:
                return mid

# 牛顿法
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        r = x
        while r > x // r:
            r = (r + x//r) // 2
        return r