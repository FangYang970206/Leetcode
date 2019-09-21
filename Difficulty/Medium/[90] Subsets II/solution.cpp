/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(res, nums, tmp, 0);
        return res;
    }

    void subsetsWithDupHelper(vector<vector<int>>& res, const vector<int>& nums, vector<int>& tmp, int begin) {
        res.push_back(tmp);
        for (int i = begin; i < nums.size(); ++i) {
            if ( i == begin || nums[i] != nums[i-1] ){
                tmp.push_back(nums[i]);
                subsetsWithDupHelper(res, nums, tmp, i + 1);
                tmp.pop_back();
            }
        }
    }
};

