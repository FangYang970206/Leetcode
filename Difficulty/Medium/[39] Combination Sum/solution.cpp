/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        searchtree(res, candidates, target, combination, 0);
        return res;
    }
    
    void searchtree(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& combination, int start){
        if (!target){
            res.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size() && target >= candidates[i]; ++i){
            combination.push_back(candidates[i]);
            searchtree(res, candidates, target - candidates[i], combination, i);
            combination.pop_back();
        }
    }
};