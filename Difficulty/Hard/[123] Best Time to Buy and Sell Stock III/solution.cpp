/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start

//version1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int K = 2;
        vector<vector<int>> dp(prices.size(), vector<int>(K + 1, 0));
        for (int k = 1; k <= K; ++k) {
            for (int i = 1; i < prices.size(); ++i) {
                int min_val = INT_MAX;
                for (int buy = 0; buy <= i; ++buy) {
                    min_val = min(prices[buy] - dp[buy][k-1], min_val);
                }
                dp[i][k] = max(dp[i-1][k], prices[i] - min_val);
            }
        }
        return dp[prices.size()-1][K];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int K = 2;
        vector<vector<int>> dp(prices.size(), vector<int>(K + 1, 0));
        for (int k = 1; k <= K; ++k) {
            int min_val = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                min_val = min(prices[i] - dp[i][k-1], min_val);
                dp[i][k] = max(dp[i-1][k], prices[i] - min_val);
            }
        }
        return dp[prices.size()-1][K];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int K = 2;
        vector<vector<int>> dp(prices.size(), vector<int>(K + 1, 0));
        vector<int> min_vals(K + 1, prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= K; ++k) {
                min_vals[k] = min(prices[i] - dp[i][k-1], min_vals[k]);
                dp[i][k] = max(dp[i-1][k], prices[i] - min_vals[k]);
            }
        }
        return dp[prices.size()-1][K];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int K = 2;
        vector<int> dp(K + 1, 0);
        vector<int> min_vals(K + 1, prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= K; ++k) {
                min_vals[k] = min(prices[i] - dp[k-1], min_vals[k]);
                dp[k] = max(dp[k], prices[i] - min_vals[k]);
            }
        }
        return dp[K];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int dp1 = 0;
        int dp2 = 0;
        int min1 = prices[0];
        int min2 = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min1 = min(prices[i] - 0, min1);
            dp1 = max(dp1, prices[i] - min1);

            min2 = min(prices[i] - dp1, min2);
            dp2 = max(dp2, prices[i] - min2);
        }
        return dp2;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }
        return max(s4, 0);
    }
};
// @lc code=end

