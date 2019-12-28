/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 3) return *min_element(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) return nums[left];
        if (nums[right] < nums[right - 1]) return nums[right];
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return 0;
    }
};
// @lc code=end

