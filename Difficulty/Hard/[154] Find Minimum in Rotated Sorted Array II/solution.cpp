class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int result = INT_MAX;
        while (left < right) {
            if (nums[left] < nums[right])
                return min(min(result, nums[left]), nums[0]);
            else if (nums[left] == nums[right]) {
                left++;
                right--;
            }else {
                int mid = (left + right) / 2;
                if (nums[mid] < nums[left])
                    right = mid;
                else
                    left = mid + 1;
            }
        }
        return min(min(result, nums[left]), nums[0]);
    }
};