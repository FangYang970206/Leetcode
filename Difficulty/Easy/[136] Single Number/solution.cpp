/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto i : nums)
            m[i]++;
        for (auto p : m) {
            if (p.second == 1) {
                res = p.first;
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i : nums)
            res ^= i;
        return res;
    }
};
// @lc code=end

