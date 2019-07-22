/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        for(int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= intervals[i-1][1]){
                if (intervals[i][1] > intervals[i - 1][1])
                    intervals[i] = {intervals[i-1][0], intervals[i][1]};
                else
                    intervals[i] = intervals[i-1];
            }
            else
                res.push_back(intervals[i-1]);                
        }
        res.push_back(intervals[intervals.size() - 1]);
        return res;
    }
};

