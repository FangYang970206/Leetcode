#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        _dict = dict()
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    b = '(' + board[i][j] + ')'
                    if _dict.get(str(i) + b, 0) or \
                       _dict.get(b + str(j), 0) or \
                       _dict.get(str(i // 3) + b + str(j // 3), 0):
                        return False
                    else:
                        _dict[str(i) + b] = 1
                        _dict[b + str(j)] = 1
                        _dict[str(i // 3) + b + str(j // 3)] = 1
        return True
        

