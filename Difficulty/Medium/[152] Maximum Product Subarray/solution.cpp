/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int r = nums[0];
        int imax = r, imin = r;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(imax, imin);
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            r = max(r, imax);
        }
        return r;
    }
};
// @lc code=end

