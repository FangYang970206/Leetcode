class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if k <= 0 or not prices: return 0
        if k >= len(prices) // 2:
            return self.greedy(prices)
        dp = [[0] * 2 for _ in range(k+1)]
        for i in range(1, k+1):
            dp[i][0] = 0
            dp[i][1] = -prices[0]
        for i in range(1, len(prices)):
            for j in range(1, k+1):
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i])
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i])
        return dp[k][0]
            
    def greedy(self, prices):
        res = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                res += prices[i] - prices[i - 1]
        return res