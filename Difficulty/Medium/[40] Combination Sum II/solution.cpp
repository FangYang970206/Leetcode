/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        bfs(res, candidates, target, combination, 0);
        return res;
    }
    
    void bfs(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& combination, int start){
        if (target < 0)
            return;
        if (target == 0){
            res.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            if (i != start && candidates[i] == candidates[i-1]){
                continue;
            }
            combination.push_back(candidates[i]);
            bfs(res, candidates, target - candidates[i], combination, i+1);
            combination.pop_back();
        }
    }
};