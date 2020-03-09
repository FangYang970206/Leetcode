/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return vector<string>();
        vector<string> res;
        unordered_map<string, int> um;
        for (int i = 0; i <= s.size() - 10; i++) {
            um[s.substr(i, 10)]++;
        }
        for(auto& p : um) {
            if (p.second > 1)
                res.push_back(p.first);
        }
        return res;
    }
};
// @lc code=end

