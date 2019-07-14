class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, cur_index = 0;
        while(cur_index != nums.size() - 1){
            if (cur_index + nums[cur_index] >= nums.size() - 1)
                return step + 1;
            int max_shift = 0;
            int sub_optimal_index = 0;
            for (int i = 1; i <= nums[cur_index]; ++i){
                if ((i + nums[i + cur_index]) > max_shift){
                    max_shift = i + nums[i + cur_index];
                    sub_optimal_index = cur_index + i;
                }
            }
            cur_index = sub_optimal_index;
            step++;
        }
        return step;
    }
};