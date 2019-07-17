class Solution:
    def solveNQueens(self, n: int):
        if n < 1:
            return [[]]
        res, row, positions, cur = [], 0, [], [n * ['.'] for _ in range(n)]
        self.Nqueens(res, cur, row, n, positions)
        return res
    
    def Nqueens(self, res, cur, row, n, positions):
        if cur[n - 1] != n * ['.']:
            list_to_str = []
            for l in cur:
                list_to_str.append(''.join(l))
            res.append(list_to_str)
            return
        for col in range(n):
            posId = 0
            for pos in positions:
                if abs(pos[0] - row) == abs(pos[1] - col) or pos[1] == col:
                    break
                posId += 1
            if posId == len(positions):
                positions.append([row, col])
                cur[row][col] = 'Q'
                self.Nqueens(res, cur, row + 1, n, positions)
                cur[row][col] = '.'
                positions.pop()