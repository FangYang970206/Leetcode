class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        s1, s2, s3, s4 = -prices[0], -2**31 - 1, -2**31 - 1, -2**31 - 1
        for i in range(1, len(prices)):
            s1 = max(s1, -prices[i])
            s2 = max(s2, prices[i] + s1)
            s3 = max(s3, s2 - prices[i])
            s4 = max(s4, s3 + prices[i])
        return max(0, s4)