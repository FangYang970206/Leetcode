/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s <= 0 || nums.empty()) return 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        int length = nums.size();
        int minLen = INT_MAX;
        while (right < length) {
            sum += nums[right];
            right++;
            while (sum >= s) {
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
// @lc code=end

