/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left {}, mid {}, right {nums.size() - 1};
        while (mid <= right) {
            if (nums[mid] == 0)
                swap(nums[mid++], nums[left++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[right--]);
        }
    }
};

