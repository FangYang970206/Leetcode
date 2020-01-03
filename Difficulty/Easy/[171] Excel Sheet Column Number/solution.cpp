/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size() - 1;
        double res = 0;
        for (int i = 0; i < s.size(); i++)
            res += ((s[i] - 'A') + 1) * pow(26, length - i);   
        return int(res);
    }
};
// @lc code=end

