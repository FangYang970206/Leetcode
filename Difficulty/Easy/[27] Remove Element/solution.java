class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) return 0;
        int i = 0, j = 0, len = nums.length;
        while (j < len) {
            if (nums[i] != val) {
                i++;j++;
            } else {
                break;
            }
        }
        while (++j < len) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
                nums[j] = val;
            }
        }
        return i;
    }
}