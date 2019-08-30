/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;

        for(int j = 0; j < matrix[0].size(); ++j)
                row = matrix[0][j] == 0 ? true : row;

        for(int i = 0; i < matrix.size(); ++i)
                col = matrix[i][0] == 0 ? true : col;

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if(!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
            }
        }

        if(row){
            for(int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        }
        
        if(col){
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }
    }
};

