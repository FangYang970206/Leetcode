/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
        
        for (int i = begin; i <= len; ++i){
            swap(nums[begin], nums[i]);
            permutation(res, begin + 1, len, nums);
            swap(nums[begin], nums[i]);
        }
    }
};

