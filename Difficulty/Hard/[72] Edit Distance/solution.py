class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        #dp = [[0 for _ in range(len(word1))]]*len(word2)
        dp = [[0]*len(word1) for _ in range(len(word2))]
        equal_flag = False
        for j in range(len(word1)):
            if word2[0] == word1[j] and (not equal_flag):
                equal_flag = True
                dp[0][j] = dp[0][j - 1] if j > 0 else 0
            else:
                dp[0][j] = (dp[0][j - 1] + 1) if j > 0 else 1
        equal_flag = False
        for i in range(len(word2)):
            if word2[i] == word1[0] and (not equal_flag):
                equal_flag = True
                dp[i][0] = dp[i-1][0] if i > 0 else 0
            else:
                dp[i][0] = (dp[i-1][0] + 1) if i > 0 else 1
        for i in range(1, len(word2)):
            for j in range(1, len(word1)):
                if word2[i] == word1[j]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1
        return dp[len(word2) - 1][len(word1) - 1]