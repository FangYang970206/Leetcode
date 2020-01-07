class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        row, col = len(dungeon), len(dungeon[0])
        dp = [[2**31 - 1] * (col + 1) for _ in range((row + 1))]
        dp[row - 1][col] = 1
        for i in range(row - 1, -1, -1):
            for j in range(col - 1, -1, -1):
                val = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
                dp[i][j] = max(val, 1)
        return dp[0][0]

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        row, col = len(dungeon), len(dungeon[0])
        dp = [2**31 - 1] * (col + 1)
        dp[col-1] = 1
        for i in range(row - 1, -1, -1):
            for j in range(col - 1, -1, -1):
                dp[j] = max(min(dp[j], dp[j+1]) - dungeon[i][j], 1)
        return dp[0]

    