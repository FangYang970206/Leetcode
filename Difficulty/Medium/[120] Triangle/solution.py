class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle: return 0
        height = len(triangle)
        for i in range(1, height):
            for j in range(0, i+1):
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j == i:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1])
        return min(triangle[height-1])