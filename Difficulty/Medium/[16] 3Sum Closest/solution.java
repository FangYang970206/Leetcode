class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int res = 0, len = nums.length, distance = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < len - 2; i++) {
            int expect = target - nums[i];
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (Math.abs(sum - expect) < distance) {
                    distance = Math.abs(sum - expect);
                    res = sum + nums[i];
                }
                if (sum == expect) {
                    return target;
                } else if (sum > expect) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
}