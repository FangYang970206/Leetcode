class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board or len(board) == 0:
            return
        self.solve(board)
        
    def solve(self, board):
        """
        rtype: boolean
        """
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if board[i][j] == '.':
                    for c in "123456789":
                        if self.isValid(board, i, j, c):
                            board[i][j] = c
                            # If it's the solution return true
                            if self.solve(board): 
                                return True
                            # Otherwise go back
                            else:
                                board[i][j] = '.'
                    return False
        return True
        
    def isValid(self, board, x, y, c):
        for i in xrange(9):
            if board[i][y] == c: 
                return False
        for j in xrange(9):
            if board[x][j] == c:
                return False
        for i in xrange(3):
            for j in xrange(3):
                if board[(x/3)*3 + i][(y/3)*3 + j] == c:
                    return False
                    
        return True

# python3 version is same as python2 , but it does not work, the reason i do not know 
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return None
        solve(board)
    
        def solve(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for c in '123456789':
                            if isValid(board, i, j, c):
                                board[i][j] = c
                                if solve(board):
                                    return True
                                else:
                                    board[i][j] = '.'
                        return False
            return True
    
        def isValid(board, row, col, s):
            for i in range(9):
                if board[row][i] != '.' and board[row][i] == s:
                    return False
                if board[i][col] != '.' and board[i][col] == s:
                    return False
                if board[3 * row // 3 + i // 3][3 * col // 3 + i % 3] != '.' \
                   and board[3 * row // 3 + i // 3][3 * col // 3 + i % 3] != s:
                    return False
            return True
