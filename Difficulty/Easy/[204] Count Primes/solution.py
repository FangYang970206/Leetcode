class Solution:
    def countPrimes(self, n: int) -> int:
        isPrim, count = [1] * n, 0
        for i in range(2, n):
            if isPrim[i]:
                for j in range(i*i, n, i):
                    isPrim[j] = 0
        for j in range(2, n):
            if isPrim[j]:
                count += 1
        return count