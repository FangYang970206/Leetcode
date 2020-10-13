class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1) return nums.length;
        int i = 1, j = 1, len = nums.length;
        while (j < len) {
            while (j < len && nums[j] == nums[j-1]) {
                j++;
            }
            if (j < len) {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
}