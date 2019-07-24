/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n < 1) return vector<vector<int>> ();
        vector<vector<int>> res {n, vector<int>(n, 0)};
        int row_begin = 0, row_end = n;
        int col_begin = 0, col_end = n;
        int begin = 1, end = n * n;
        while (begin <= end){
            for (int col = col_begin; col < col_end; col++)
                res[row_begin][col] = begin++;
            for (int row = row_begin + 1; row < row_end ; row++)
                res[row][col_end - 1] = begin++;
            for (int col = col_end - 2; col >= col_begin; col--)
                res[row_end - 1][col] = begin++;
            for (int row = row_end - 2; row > row_begin; row--)
                res[row][col_begin] = begin++;
            row_begin++, col_begin++, row_end--, col_end--; 
        }
        return res;
    }
};

