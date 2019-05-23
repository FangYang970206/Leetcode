class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int l = 0, r = 0, sum = 0;
        for (int i = 0; i < nums.size() - 2; ++i){
            l = i + 1;
            r = nums.size() - 1;
            while (l < r){
                sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return sum;
                if (abs(res - target) > abs(sum - target))
                    res = sum;
                if (sum > target)
                    r -= 1;
                else if (sum < target)
                    l += 1;
            }
        }
        return res;
    }
};