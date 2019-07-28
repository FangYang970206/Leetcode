class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = [n * [0] for _ in range(m)]
        for m_i in range(m):
            for n_i in range(n):
                if m_i > 0 and n_i > 0:
                    if dp[m_i][n_i - 1] > dp[m_i - 1][n_i]:
                        dp[m_i][n_i] = grid[m_i][n_i] + dp[m_i - 1][n_i]
                    else:
                        dp[m_i][n_i] = grid[m_i][n_i] + dp[m_i][n_i - 1]
                elif m_i > 0:
                    dp[m_i][n_i] = grid[m_i][n_i] + dp[m_i - 1][n_i]
                elif n_i > 0:
                    dp[m_i][n_i] = dp[m_i][n_i - 1] + grid[m_i][n_i]
                else:
                    dp[m_i][n_i] = grid[m_i][n_i]
        return dp[m-1][n-1]