class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        s_len, t_len = len(s), len(t)
        dp = [[0] * (s_len + 1) for _ in range(t_len + 1)]
        if not s_len or not t_len or s_len < t_len: return 0
        if s_len == t_len: return int(s == t)
        for i in range(t_len):
            for j in range(s_len):
                if i <= j:
                    if t[i] == s[j]:
                        if i == 0:
                            dp[i+1][j+1] = dp[i+1][j] + 1
                        else:
                            dp[i+1][j+1] = dp[i+1][j] + dp[i][j]
                    else:
                        dp[i+1][j+1] = dp[i+1][j]
        print(dp)
        return dp[t_len][s_len]