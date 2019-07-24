class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n < 1:
            return []
        res = [n * [0] for _ in range(n)]
        row_begin, row_end, col_begin, col_end, i = 0, n, 0, n, 1
        while i <= n**2:
            for col in range(col_begin, col_end):
                res[row_begin][col] = i
                i += 1
            for row in range(row_begin + 1, row_end):
                res[row][col_end - 1] = i
                i += 1
            for col in range(col_end - 2, col_begin - 1, -1):
                res[row_end - 1][col] = i
                i += 1
            for row in range(row_end - 2, row_begin, -1):
                res[row][col_begin] = i
                i += 1
            row_begin += 1
            col_begin += 1
            row_end -= 1
            col_end -= 1
        return res