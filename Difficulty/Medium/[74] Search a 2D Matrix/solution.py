class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        if not matrix[0]:
            return False
        height, width = len(matrix), len(matrix[0])
        if height == 1 and width == 1:
            return target == matrix[0][0]
        nums = height * width
        right, left = nums - 1, 0
        if target < matrix[0][0] or target > matrix[height-1][width-1]:
            return False
        while left < right:
            if right - left == 1:
                break
            tmp = matrix[((right + left) >> 1) // width][((right + left) >> 1) % width]
            if target > tmp:
                left = (right + left) >> 1
            elif target < tmp:
                right = (right + left) >> 1
            else:
                return True
        if right - left == 1:
            if target == matrix[left // width][left % width] or target == matrix[right // width][right % width]:
                return True
            else:
                return False
        return False