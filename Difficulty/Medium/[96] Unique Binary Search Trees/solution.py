class Solution:
    def numTrees(self, n: int) -> int:
        if n <= 0:
            return 0
        h_n = 1
        for i in range(1, n + 1):
            h_n = (4 * i - 2) * h_n // (i + 1)
        return h_n
            