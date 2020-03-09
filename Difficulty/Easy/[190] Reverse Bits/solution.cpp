/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t left = 0x80000000, right = 0x00000001, value_left, value_right;
        while (left > right) {
            value_left = n & left;
            value_right = n & right;
            if (value_left == 0)
                n = n & (~right);
            else
                n = n | right;
            if (value_right == 0)
                n = n & (~left);
            else
                n = n | left;
            right <<= 1;
            left >>= 1;
        }
        return n;
    }
};
// @lc code=end

