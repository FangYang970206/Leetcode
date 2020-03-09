/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        int r1 = nums[0], r2 = max(nums[0], nums[1]), tmp;
        for(int i = 2; i < nums.size(); i++){
            tmp = max(r1 + nums[i], r2);
            r1 = r2;
            r2 = tmp;
        }
        return r2;
    }
};
// @lc code=end

