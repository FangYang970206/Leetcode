class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row, col = False, False
        for j in range(len(matrix[0])):
            row = True if matrix[0][j] == 0 else row
        for i in range(len(matrix)):
            col = True if matrix[i][0] == 0 else col
        for i in range(1, len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[0][j] = matrix[i][0] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
        if row:
            for j in range(len(matrix[0])):
                matrix[0][j] = 0
        if col:
            for i in range(len(matrix)):
                matrix[i][0] = 0