/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        int height = matrix.size(), width = matrix[0].size();
        if (height * width == 1) return target == matrix[0][0]; 
        int nums = height * width;
        int right = nums - 1, left = 0;
        if (target < matrix[0][0] || target > matrix[height - 1][width - 1])
            return false;
        while (left < right) {
            if (right - left == 1)
                break;
            int tmp = matrix[((right + left) >> 1) / width][((right + left) >> 1) % width];
            if (target > tmp)
                left = (right + left) >> 1;
            else if (target < tmp)
                right = (right + left) >> 1;
            else
                return true;
        }
        if (right - left == 1) {
            if (target == matrix[left / width][left % width] || target == matrix[right / width][right % width])
                return true;
            else
                return false;
        }
        return false;
    }
};

