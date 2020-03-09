class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0;
        nr, nc, num = len(grid), len(grid[0]), 0
        for i in range(nr):
            for j in range(nc):
                if grid[i][j] != '0':
                    num += 1
                    self.dfs(grid, i, j)
        return num

    def dfs(self, grid, x, y):
        nr, nc = len(grid), len(grid[0])
        grid[x][y] = '0'
        if x - 1 >= 0 and grid[x-1][y] == '1':
            self.dfs(grid, x-1, y)
        if x + 1 < nr and grid[x+1][y] == '1':
            self.dfs(grid, x+1, y)
        if y - 1 >= 0 and grid[x][y-1] == '1':
            self.dfs(grid, x, y-1)
        if y + 1 < nc and grid[x][y+1] == '1':
            self.dfs(grid, x, y+1)