/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<string> seen;
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != '0') {
                    if (seen.find(to_string(i) + '_' + to_string(j)) == seen.end()) {
                        dfs(grid, seen, i, j);
                        res++;
                    }
                }   
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, unordered_set<string>& seen, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if (grid[x][y] != '0') {
            string cord = to_string(x) + '_' + to_string(y);
            if (seen.find(cord) == seen.end()) {
                seen.insert(cord);
                dfs(grid, seen, x + 1, y);
                dfs(grid, seen, x - 1, y);
                dfs(grid, seen, x, y + 1);
                dfs(grid, seen, x, y - 1);
            }
        }
    }
};
// @lc code=end

