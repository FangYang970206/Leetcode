class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums, res, cumulate, cumulateTemp, j = [], "", [], 1, 2
        for i in range(1, n+1):
            nums.append(str(i))
        for i in range(1, n):
            cumulateTemp *= i
            cumulate.append(cumulateTemp)
        k -= 1
        while len(res) != n - 1:
            q = k // cumulate[n - j]
            res += nums[q]
            del nums[q]
            k = k % cumulate[n - j]
            j += 1
        return res + nums[0]

        
