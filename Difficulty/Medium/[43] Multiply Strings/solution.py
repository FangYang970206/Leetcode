class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        res = [0] * (len(num1) + len(num2)) 
        for i in range(len(num1)-1, -1, -1):
            carry = 0
            for j in range(len(num2)-1, -1, -1):
                mu = res[i + j + 1] + (ord(num1[i]) - 48) * (ord(num2[j]) - 48) + carry
                res[i + j + 1] = mu % 10
                carry = mu // 10
            res[i] += carry
        res = "".join(map(str, res)).lstrip('0')
        return res if res else '0'