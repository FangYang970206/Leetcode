class Solution:
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        if len(s) == 1:
            return 1 if s[0] != '0' else 0
        dp = [0] * len(s)
        if s[0] == '0':
            return 0
        if ord(s[0]) - ord('2') > 0 and s[1] == '0':
            return 0
        dp[0] = 1
        if (s[0] == '1' and s[1] != '0'):
            dp[1] = 2
        elif s[0] == '2' and ord(s[1]) - ord('0') > 0 and ord(s[1]) - ord('0') <= 6:
            dp[1] = 2
        else:
            dp[1] = 1
        for i in range(2, len(s)):
            if ord(s[i - 1]) - ord('0') > 0 and ord(s[i - 1]) - ord('0') <= 2:
                if s[i - 1] == '1' and s[i] != '0':
                    dp[i] = dp[i - 1] + dp[i - 2]
                elif s[i - 1] == '2' and s[i] != '0' and ord(s[i]) - ord('0') <= 6:
                    dp[i] = dp[i - 1] + dp[i - 2]
                elif s[i] == '0':
                    dp[i] = dp[i - 2]
                else:
                    dp[i] = dp[i - 1]
            elif s[i] != '0':
                dp[i] = dp[i - 1]
            else:
                return 0
        return dp[len(s) - 1]