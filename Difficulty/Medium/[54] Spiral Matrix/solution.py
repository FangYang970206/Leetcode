class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        if not matrix:
            return res
        row_begin, row_end, col_begin, col_end = 0, len(matrix), 0, len(matrix[0])
        while row_begin < row_end and col_begin < col_end:
            for col in range(col_begin, col_end):
                res.append(matrix[row_begin][col])
            for row in range(row_begin + 1, row_end):
                res.append(matrix[row][col_end - 1])
            if row_end - row_begin > 1 and col_end - col_begin > 1:
                for col in range(col_end - 2, col_begin - 1, -1):
                    res.append(matrix[row_end - 1][col])
                for row in range(row_end - 2, row_begin, -1):
                    res.append(matrix[row][col_begin])
            row_begin += 1
            col_begin += 1
            row_end -= 1
            col_end -= 1
        return res