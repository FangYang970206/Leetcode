class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n, begin, end = len(matrix) - 1, 0, len(matrix) - 1
        while begin < end:
            for i in range(begin, end):
                matrix[begin][i], matrix[i][n-begin] = matrix[i][n-begin], matrix[begin][i]
                matrix[begin][i], matrix[n-begin][n-i] = matrix[n-begin][n-i], matrix[begin][i]
                matrix[begin][i], matrix[n-i][begin] = matrix[n-i][begin], matrix[begin][i]
            begin += 1
            end -= 1
        