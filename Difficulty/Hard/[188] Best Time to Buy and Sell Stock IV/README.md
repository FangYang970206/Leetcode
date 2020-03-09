# 问题描述

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

```bash
输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```

示例 2:

```bash
输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

# 方法

这道题采用的方法是动态规划，特别推荐看这个[高赞题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/)，讲得很清楚。

下面是根据自己的理解写出来代码解析：

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.empty()) return 0;
        if (k >= prices.size() / 2)
            //此时退化成K为无穷的情况，跟第二个股票问题一样，使用贪婪算法。
            return greedy(prices);
        //dp表的含义是k次交易最大的利润，第二维分两种状态，一种是卖出股票，用0表示，另一种是买入股票，用1表示。
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        // 以第一天为base case，两种选择，买入或者卖出（无卖出状态，收入为0）
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }
        for(int i = 1; i < prices.size(); i++){
            for(int j = 1; j <= k; j++){
                // dp[j][0]有两种选择，要么跟之前状态一样，要么从dp[j][1]状态转移到此状态，此时加上卖出价格。
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                //  dp[j][1]有两种选择，要么跟之前状态一样，要么从dp[j-1][0]状态转移到此状态，此时减去买入价格，此时交易增加一次。
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }
private:
    int greedy(const vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }
};
```
