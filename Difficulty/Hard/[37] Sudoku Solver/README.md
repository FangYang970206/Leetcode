# 问题描述
编写一个程序，通过填充空单元格来解决数独难题。

数独解决方案必须满足以下所有规则:
- 每个数字1-9必须在每一行中精确地出现一次。
- 每个数字1-9必须在每一列中精确地出现一次。
- 每个数字1-9必须在网格的9个3x3子框中精确地出现一次。

空单元格由字符'.'表示。



# 例子

![img](assets/250px-Sudoku-by-L2G-20050714.svg.png)

结果：

![img](assets/250px-Sudoku-by-L2G-20050714_solution.svg.png)

- 给定的板只包含数字1-9和字符'.'。
- 你可以假设给定的数独游戏将有一个唯一的解。
- 给定的板大小总是9x9。

# 方法

该题的solution中参考自https://leetcode.com/problems/sudoku-solver/discuss/15752/Straight-Forward-Java-Solution-Using-Backtracking , 非常直接的方法，遍历每一个'.'，有9种可能性，选择其中一种可能性，如果满足上述要求，递归调用下一个'.', 当不满足要求时，进行回溯，寻找其他的可能性。

当然，这种方法有冗余，每一行，每一列，每一个3x3的cell已存在其他的数字，所以对于这些数字，应该不用进行考虑，可以参照https://leetcode.com/problems/sudoku-solver/discuss/15892/A-simple-DFS-solution 中票数最高的评论，使用了三个字典保存已经出现的值，这样更加高效，用一定的内存换取更快的时间。
```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                if (board[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for (int i = 0; i < 9; ++i){
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
```