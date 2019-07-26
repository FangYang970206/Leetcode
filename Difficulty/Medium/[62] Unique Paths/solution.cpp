/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 1));
        for (int m_i = 1; m_i < m; m_i++){
            for (int n_i = 1; n_i < n; n_i++)
                dp[m_i][n_i] = dp[m_i - 1][n_i] + dp[m_i][n_i - 1];
        }
        return dp[m-1][n-1];
    }
};

