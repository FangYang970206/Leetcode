class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ""
        while n:
            r = n % 26
            if r == 0:
                res += 'Z'
                n -= 26
            else:
                res += chr(ord('A') + r - 1)
                n -= r
            n //= 26
        return res[::-1]