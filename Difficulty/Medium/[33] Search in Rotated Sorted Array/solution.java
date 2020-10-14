class Solution {
    public int search(int[] nums, int target) {
        int beg = 0, end = nums.length - 1, mid = 0;
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[beg]) {
                if (target >= nums[beg] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (target <= nums[end] && target > nums[mid]) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return - 1;
    }
}