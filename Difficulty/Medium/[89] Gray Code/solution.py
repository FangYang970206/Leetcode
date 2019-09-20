class Solution:
    def grayCode(self, n: int) -> List[int]:
        num = 1 << n
        res = [0] * num
        for i in range(1, num):
            if i & 1:
                res[i] = res[i - 1] ^ 1 if res[i - 1] & 1 else res[i - 1] | 1
            else:
                j = self.getPosition(i)
                res[i] = res[i - 1] ^ (1 << (j - 1)) if res[i - 1] & (1 << (j - 1)) else res[i - 1] | (1 << (j - 1))
        return res
    
    def getPosition(self, n):
        i = 2
        while not (n >> 1) & 1:
            n >>= 1 
            i += 1
        return i