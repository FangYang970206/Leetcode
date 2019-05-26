#
# @lc app=leetcode id=32 lang=python3
#
# [32] Longest Valid Parentheses
#

#动态规划
class Solution1:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        dp = [0 for _ in range(len(s))]
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = (dp[i-2] if i >= 2 else 0) + 2
                elif i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(':
                    dp[i] = dp[i-1] + 2 + (dp[i - dp[i-1] - 2] if i - dp[i-1] >=2 else 0)
        return max(dp)

