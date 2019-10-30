/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>();
        if (numRows == 1) return vector<vector<int>>(1, vector<int>(1, 1));
        if (numRows == 2) return vector<vector<int>>{{1}, {1, 1}};
        vector<vector<int>> res{{1}, {1, 1}};
        for (int i = 3; i <= numRows; ++i) {
            vector<int> tmp(i, 0);
            for (int j = 1; j <= i; ++j){
                if (j == 1 || j == i)
                    tmp[j-1] = 1;
                else
                    tmp[j-1] = res[i - 2][j - 1] + res[i - 2][j - 2];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

