/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half_len = nums.size() / 2;
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
            if (map[num] > half_len)
                return num;
        }
        return 0;
    }
};
// @lc code=end

