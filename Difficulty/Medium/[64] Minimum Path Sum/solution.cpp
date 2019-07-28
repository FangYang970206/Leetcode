/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for (int m_i = 0; m_i < m; m_i++){
            for (int n_i = 0; n_i < n; n_i++){
                if (m_i > 0 && n_i > 0){
                    if (dp[m_i][n_i - 1] > dp[m_i - i][n_i])
                        dp[m_i][n_i] = grid[m_i][n_i] + dp[m_i - 1][n_i];
                    else
                        dp[m_i][n_i] = grid[m_i][n_i] + dp[m_i][n_i - 1];
                }else if (m_i > 0)
                    dp[m_i][n_i] = dp[m_i - 1][n_i] + grid[m_i][n_i];
                else if (n_i > 0)
                    dp[m_i][n_i] = dp[m_i][n_i - 1] + grid[m_i][n_i];
                else
                    dp[m_i][n_i] = grid[m_i][n_i];
            }
        }
        return dp[m-1][n-1];
    }
};

