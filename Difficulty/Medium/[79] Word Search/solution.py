class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word, 0, len(board), len(board[0]), len(word)):
                    return True
        return False

    def dfs(self, board, row, col, word, start, M, N, slen):
        curC, res = '', False
        if board[row][col] != word[start]:
            return False
        if start == slen - 1:
            return True
        curC = board[row][col]
        board[row][col] = '*'
        if row > 0:
            res = self.dfs(board, row-1, col, word, start+1, M, N, slen)
        if not res and row < M - 1:
            res = self.dfs(board, row+1, col, word, start+1, M, N, slen)
        if not res and col > 0:
            res = self.dfs(board, row, col-1, word, start+1, M, N, slen)
        if not res and col < N - 1:
            res = self.dfs(board, row, col+1, word, start+1, M, N, slen)
        board[row][col] = curC
        return res