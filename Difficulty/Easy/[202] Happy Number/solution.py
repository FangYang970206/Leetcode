class Solution:
    def isHappy(self, n: int) -> bool:
        fast, slow, flag = n, n, True
        while flag or slow != fast:
            slow = self.squareSum(slow)
            fast = self.squareSum(fast)
            fast = self.squareSum(fast)
            flag = False
        return slow == 1

    def squareSum(self, n):
        res = 0
        while n:
            t = n % 10;
            res += t * t;
            n //= 10;
        return res;