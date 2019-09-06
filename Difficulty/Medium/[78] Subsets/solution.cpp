/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(vector<int>{});
        for (int i = 0; i < nums.size(); ++i)
            subsets_helper(res, tmp, nums, 0, i+1);
        return res;
    }

    void subsets_helper(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int begin, int num){
        if (tmp.size() == num){
            res.push_back(tmp);
            return;
        }
        for (int i = begin; i < nums.size(); ++i){
            tmp.push_back(nums[i]);
            subsets_helper(res, tmp, nums, i+1, num);
            tmp.pop_back();
        }
    }
};

