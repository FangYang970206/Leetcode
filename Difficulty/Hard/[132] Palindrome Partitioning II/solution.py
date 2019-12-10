class Solution:
    def minCut(self, s: str) -> int:
        if len(s) < 2: return 0
        n = len(s)
        pal = [[0] * n for _ in range(n)]
        d = [0] * n
        for i in range(n-1, -1, -1):
            d[i] = n - i - 1
            for j in range(i, n):
                if s[i] == s[j] and (j - i < 2 or pal[i+1][j-1]):
                    pal[i][j] = 1
                    if j == n-1:
                        d[i] = 0
                    else:
                        if d[j + 1] + 1 < d[i]:
                            d[i] = d[j + 1] + 1
        return d[0]