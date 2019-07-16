/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> records;
        vector<vector<string>> res;
        for (auto& s : strs){
            auto t = s;
            sort(t.begin(), t.end());
            records[t].emplace_back(move(s));
        }
        for (auto& r : records){
            res.emplace_back(move(r.second));
        }
        return res;
    }
};

