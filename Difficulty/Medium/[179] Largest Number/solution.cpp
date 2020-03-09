/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> nums_str;
        for (auto num : nums)
            nums_str.push_back(to_string(num));
        sort(nums_str.begin(), nums_str.end(), [](string& a, string& b){return a + b > b + a;});
        if (nums_str[0] == "0")
            return "0";
        for (auto s : nums_str) {
            res += s;
        }
        return res;
    }
};
// @lc code=end

