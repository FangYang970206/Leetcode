/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int row_begin = 0, row_end = matrix.size();
        int col_begin = 0, col_end = matrix[0].size();
        while(row_begin < row_end && col_begin < col_end){
            for (int col = col_begin; col < col_end; col++)
                res.push_back(matrix[row_begin][col]);
            for (int row = row_begin + 1; row < row_end ; row++)
                res.push_back(matrix[row][col_end - 1]);
            if ((row_end - row_begin) > 1 && (col_end - col_begin) > 1){
                for (int col = col_end - 2; col >= col_begin; col--)
                    res.push_back(matrix[row_end - 1][col]);
                for (int row = row_end - 2; row > row_begin; row--)
                    res.push_back(matrix[row][col_begin]);
            }
            row_begin++, col_begin++, row_end--, col_end--; 
        }
        return res;
    }
};

