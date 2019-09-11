/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] == nums[left] && nums[mid] == nums[right])
                {left++; right--;}
            else if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }else{
                if(nums[right] >= target && target > nums[mid]) left = mid + 1;
                else right = mid - 1; 
            }
        }
        return false;
    }
};

