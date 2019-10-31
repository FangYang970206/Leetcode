class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2: return 0
        maxProfit, min_val = 0, prices[0]
        for i in range(1, len(prices)):
            if prices[i] < min_val:
                min_val = prices[i]
            else:
                maxProfit = max(maxProfit, prices[i] - min_val)
        return maxProfit