/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um1, um2;
        for (int i = 0; i < s.size(); i++) {
            if (um1.find(t[i]) != um1.end()) {
                if (s[i] != um1[t[i]])
                    return false;
            }else
                um1[t[i]] = s[i];
            if (um2.find(s[i]) != um2.end()) {
                if (t[i] != um2[s[i]])
                    return false;
            }else
                um2[s[i]] = t[i];
        }
        return true;
    }
};
// @lc code=end

