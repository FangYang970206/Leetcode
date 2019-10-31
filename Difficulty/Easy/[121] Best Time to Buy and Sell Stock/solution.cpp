/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int maxProfit = 0, min_val = prices[0];
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] < min_val) {
                min_val = prices[i];
            }else{
                maxProfit = max(maxProfit, prices[i] -  min_val);
            }
        }
        return maxProfit;
    }
};
// @lc code=end

