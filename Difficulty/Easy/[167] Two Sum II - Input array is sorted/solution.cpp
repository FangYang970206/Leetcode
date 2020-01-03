/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int sum = numbers[left] + numbers[right];
        while (sum != target) {
            if (sum > target)
                right--;
            else
                left++;
            sum = numbers[left] + numbers[right];
        }
        return vector<int>{left + 1, right + 1};
    }
};


// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        if (numbers[right] + numbers[left] > target) {
            while (left < right) {
                int mid = (left + right) / 2;
                if (numbers[mid] + numbers[0] > target)
                    right = mid - 1;
                else if (numbers[mid] + numbers[0] < target)
                    left = mid + 1;
                else
                    return vector<int>{1, mid + 1};
            }
        } 
        while (numbers[right] == target)
            right--;
        left = 0;
        int sum = numbers[left] + numbers[right];
        while (sum != target) {
            if (sum > target)
                right--;
            else
                left++;
            sum = numbers[left] + numbers[right];
        }
        return vector<int>{left + 1, right + 1};
    }
};
// @lc code=end

