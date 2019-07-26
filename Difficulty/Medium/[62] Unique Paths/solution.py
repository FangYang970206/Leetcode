class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [n * [1] for _ in range(m)]
        for m_i in range(1, m):
            for n_i in range(1, n):
                dp[m_i][n_i] = dp[m_i - 1][n_i] + dp[m_i][n_i - 1]
        return dp[m - 1][n - 1]