/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int left_value = (mid - 1) >= 0 ? nums[mid - 1]: INT_MIN;
            int right_value = (mid + 1) < nums.size() ? nums[mid + 1]: INT_MIN;
            if (nums[mid] > left_value && nums[mid] > right_value)
                return mid;
            if (nums[mid] > left_value)
                left = mid + 1;
            else
                right = mid - 1;            
        }
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        return (left + right) / 2;
    }
};
// @lc code=end

