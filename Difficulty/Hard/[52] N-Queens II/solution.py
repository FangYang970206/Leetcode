class Solution:
    def totalNQueens(self, n: int) -> int:
        if n < 1:
            return 0
        self.res = 0
        row, positions, cur = 0, [], [n * ['.'] for _ in range(n)]
        self.Nqueens(cur, row, n, positions)
        return self.res
    
    def Nqueens(self, cur, row, n, positions):
        if cur[n - 1] != n * ['.']:
            list_to_str = []
            for l in cur:
                list_to_str.append(''.join(l))
            self.res += 1
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
                self.Nqueens(cur, row + 1, n, positions)
                cur[row][col] = '.'
                positions.pop()