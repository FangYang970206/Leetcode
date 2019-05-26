# 问题描述
给定一个只包含字符“(”和“)”的字符串，找到最长的有效(格式良好)括号子字符串的长度。
# 例子
```bash
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
```

# 方法

该题的solution中给出了四种方法，非常详细，下面只写了动态规划的方法：
```python
class Solution1:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        #dp的第i个元素代表的是以i为索引结束的最长有效子字符串的长度，所以只用判断当前的括号是否为右括号。
        dp = [0 for _ in range(len(s))]
        #循环有两种情况，第一种是当s[i-1]为左括号时，dp[i]加上前面的dp[i-2] + 2, 第二种是s[i-1]为右括号时，这时要判断s[i - dp[i-1] - 1]的位置是否为左括号，是的话，就刚好对称，加上dp[i-1]，另外还有加上dp[i - dp[i-1] - 2]的数量。
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = (dp[i-2] if i >= 2 else 0) + 2
                elif i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(':
                    dp[i] = dp[i-1] + 2 + (dp[i - dp[i-1] - 2] if i - dp[i-1] >=2 else 0)
        return max(dp)
```