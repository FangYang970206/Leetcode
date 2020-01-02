class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        res = ''
        if (numerator < 0) ^ (denominator < 0):
            res += '-'
        n, d = abs(numerator), abs(denominator)
        res += str(n // d)
        if n % d == 0:
            return res
        res += '.'
        m = dict()
        r = n % d
        while r:
            if m.get(r, None):
                res = res[:m[r]] + '(' + res[m[r]:] + ')'
                break
            m[r] = len(res)
            r *= 10
            res += str(r // d)
            r %= d
        return res