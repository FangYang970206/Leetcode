/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> elem;
        combine_helper(n, k, 1, elem, res);
        return res;
    }

    void combine_helper(int n , int k, int begin, vector<int>& elem, vector<vector<int>>& res){
        if (elem.size() == k){
            res.push_back(elem);
            return;
        }
        for (int i = begin; i <= n; ++i){               
            elem.push_back(i);
            if (elem[0] > n - k + 1) break;
            combine_helper(n, k, i+1, elem, res);
            elem.pop_back();
        }
    }
};

