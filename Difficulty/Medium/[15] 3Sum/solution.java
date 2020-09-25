class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int j = i + 1, k = nums.length-1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum > target) {
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                } else if (sum < target) {
                    j++;
                    while(j < k && nums[j] == nums[j-1]) j++;
                } else {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(nums[i]);
                    tmp.add(nums[j]);
                    tmp.add(nums[k]);
                    res.add(tmp);
                    j++;k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return res;
    }
}