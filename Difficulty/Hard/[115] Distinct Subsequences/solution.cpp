/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        if (!s_len || !t_len || s_len < t_len) return 0;
        if (s_len == t_len) return s == t;
        vector<vector<long>> dp(t_len+1, vector<long>(s_len+1));
        for (int i = 0; i < t_len; i++) {
            for (int j = 0; j < s_len; j++) {
                if (i <= j){
                    if (t[i] == s[j]) {
                        if (i == 0)
                            dp[i+1][j+1] = dp[i+1][j] + 1;
                        else
                            dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
                    }else{
                        dp[i+1][j+1] = dp[i+1][j];
                    }
                }
            }
        }
        return dp[t_len][s_len];
    }
};
// @lc code=end

