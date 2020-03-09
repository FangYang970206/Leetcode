/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int length = n - m, i = 0;
        while (length) {
            n &= ~(1U << i);
            length >>= 1;
            i++;
        }
        return m & n;
    }
};
// @lc code=end

