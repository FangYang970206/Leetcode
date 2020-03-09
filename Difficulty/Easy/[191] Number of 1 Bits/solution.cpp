/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while(n) {
            if (n & 1 != 0)
                num++;
            n >>= 1;
        }
        return num;
    }
};
// @lc code=end

