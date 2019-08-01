class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a_size, b_size = len(a), len(b)
        loop_i = min(a_size, b_size)
        carry, res = False, ''
        for i in range(1, loop_i+1):
            sum_temp = int(a[a_size - i]) + int(b[b_size - i]) + carry
            if sum_temp < 2:
                carry = False
                res = str(sum_temp) + res
            else:
                carry = True
                res = str(sum_temp - 2) + res
        other = abs(a_size - b_size)
        if carry:
            if a_size > b_size:
                res, carry = self.other_add(res, a, other, carry)
            else:
                res, carry = self.other_add(res, b, other, carry)
        else:
            if a_size > b_size:
                res = a[:other] + res
            else:
                res = b[:other] + res
        if carry:
            res = '1' + res
        return res

    def other_add(self, res, s, other, carry):
        for j in range(1, other+1):
            sum_temp = int(s[other - j]) + carry
            if sum_temp < 2:
                res = str(sum_temp) + res
                carry = False
            else:
                res = '0' + res
                carry = True
        return res, carry