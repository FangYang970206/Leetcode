/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>{1};
        if (rowIndex == 1) return vector<int>{1, 1};
        if (rowIndex == 2) return vector<int>{1, 2, 1};
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        res[1] = 2;
        res[2] = 1;
        for (int i = 3; i <= rowIndex; i++){
            int prev = 1, tmp;
            for (int j = 1; j < i; j++){
                tmp = res[j] + prev;
                prev = res[j];
                res[j] = tmp;
            }
            res[i] = 1;
        }
        return res;
    }
};
// @lc code=end

