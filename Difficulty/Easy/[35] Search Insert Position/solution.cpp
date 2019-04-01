class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        size_t nums_len = nums.size();
        if (target > nums[nums_len - 1])
            return nums_len;
        size_t left = 0;
        size_t right = nums_len - 1;
        size_t temp = right / 2;
        while (temp != left){
            if (nums[temp] > target)
                right = temp;
            else if (nums[temp] == target)
                return temp;
            else
                left = temp;
            temp = (left + right) / 2;
        }
        if (target < nums[left])
            return left;
        else if (target > nums[right])
            return right + 1;
        else
            return right;
    }
};