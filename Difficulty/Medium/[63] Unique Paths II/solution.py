class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [n * [1] for _ in range(m)]
        for m_i in range(0, m):
            for n_i in range(0, n):
                if obstacleGrid[m_i][n_i] == 1:
                    dp[m_i][n_i] = 0
                elif m_i > 0 and n_i > 0:
                    dp[m_i][n_i] = dp[m_i - 1][n_i] + dp[m_i][n_i - 1]
                elif m_i > 0:
                    dp[m_i][n_i] = dp[m_i - 1][n_i]
                elif n_i > 0:
                    dp[m_i][n_i] = dp[m_i][n_i - 1]
        return dp[m - 1][n - 1]