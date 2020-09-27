//取最小值和最大值过滤
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int len = nums.length;
        if (len < 4) return res;
        Arrays.sort(nums);
        for (int i = 0; i < len - 3; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int min1 = nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (min1 > target) break;
            int max1 = nums[i] + nums[len-1] + nums[len-2] + nums[len-3];
            if (max1 < target) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                int min2 = nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (min2 > target) break;
                int max2 = nums[i] + nums[j] + nums[len-1] + nums[len-2];
                if (max2 < target) continue;
                int sum = target - nums[i] - nums[j];
                int l = j + 1, r = len - 1;
                while (l < r) {
                    int val = nums[l] + nums[r];
                    if (val > sum) {
                        r--;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    } else if (val < sum) {
                        l++;
                        while(l < r && nums[l] == nums[l-1]) l++;
                    } else {
                        List<Integer> tmp = new ArrayList<>();
                        tmp.add(nums[i]);tmp.add(nums[j]);
                        tmp.add(nums[l]);tmp.add(nums[r]);
                        res.add(tmp);
                        r--; l++;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        return res;
    }
}