/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        if (newInterval.empty()) return intervals;
        vector<int> insert_interval;
        for (auto& interval : intervals){
            if (insert_interval.size() == 0){
                if (interval[1] < newInterval[0])
                    res.push_back(interval);
                else{
                    if (interval[0] > newInterval[0]){
                        if (newInterval[1] > interval[1])
                            insert_interval.push_back(newInterval[0]);
                        else if (newInterval[1] < interval[0]){
                            insert_interval = {newInterval[0], newInterval[1]};
                            res.push_back(insert_interval);
                            res.push_back(interval);
                        }else{
                            insert_interval = {newInterval[0], interval[1]};
                            res.push_back(insert_interval);
                        }
                    }
                    else{
                        insert_interval.push_back(interval[0]);
                        if (newInterval[1] < interval[1]){
                            insert_interval.push_back(interval[1]);
                            res.push_back(insert_interval);
                        }
                    } 
                }
            }
            else if (insert_interval.size() == 1){
                    if (interval[0] > newInterval[1]){
                        insert_interval.push_back(newInterval[1]);
                        res.push_back(insert_interval);
                        res.push_back(interval);
                    }
                    else {
                        if (interval[0] <= newInterval[1] && interval[1] > newInterval[1]){
                            insert_interval.push_back(interval[1]);
                            res.push_back(insert_interval);
                        }
                    }
            }else
                res.push_back(interval);
        }
        if (insert_interval.size() == 0){
            res.push_back(newInterval);
        }
        if (insert_interval.size() == 1){
            insert_interval.push_back(newInterval[1]);
            res.push_back(insert_interval);
        }
        return res;
    }
};

