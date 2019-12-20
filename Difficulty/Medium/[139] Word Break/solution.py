class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        d, size = dict(), len(s)
        dp, positions = [0] * (size + 1), []
        for word in wordDict:
            d[word] = True
        for i in range(size + 1):
            if d.get(s[:i], False):
                positions.append(i)
                dp[i] = True
            else:
                for p in positions:
                    if d.get(s[p:i], False):
                        positions.append(i)
                        dp[i] = True
                        break
        return dp[size]