/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        int begin = 0;
        int end = n;
        while (begin < end){
            for (int i = begin; i < end; i++){
                swap(matrix[begin][i], matrix[i][n-begin]);
                swap(matrix[begin][i], matrix[n-begin][n-i]);
                swap(matrix[begin][i], matrix[n-i][begin]);
            }
            begin++;
            end--;
        }
    }
};

