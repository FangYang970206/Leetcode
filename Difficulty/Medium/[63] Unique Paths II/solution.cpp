/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        vector<vector<size_t>> dp(m, vector<size_t>(n, 1));
        for (size_t m_i = 0; m_i < m; m_i++){
            for (size_t n_i = 0; n_i < n; n_i++){
                if (obstacleGrid[m_i][n_i] == 1)
                    dp[m_i][n_i] = 0;
                else if (m_i > 0 && n_i > 0)
                    dp[m_i][n_i] = dp[m_i - 1][n_i] + dp[m_i][n_i - 1];
                else if (m_i > 0)
                    dp[m_i][n_i] = dp[m_i - 1][n_i];
                else if (n_i > 0)
                    dp[m_i][n_i] = dp[m_i][n_i - 1];
            }
        }
        return dp[m-1][n-1];
    }
};