class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        permutation(res, 0, size - 1, nums);
        return res;
    }
    
    void permutation(vector<vector<int>>& res, int begin, int len, vector<int>& nums){
        if (begin == len){
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> record;
        for (int i = begin; i <= len; ++i){
            if (record.find(nums[i]) != record.end())
                continue;
            record.insert(nums[i]);
            swap(nums[begin], nums[i]);
            permutation(res, begin + 1, len, nums);
            swap(nums[begin], nums[i]);
        }
    }
};