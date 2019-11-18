/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        set<int> nums_set(nums.begin(), nums.end());
        int prev = *nums_set.begin(), res = 1, num = 1;
        for (auto it = ++nums_set.begin(); it != nums_set.end(); it++) {
            if (*it - prev == 1){
                num++;
                if (num > res)
                    res = num;
            }else
                num = 1;
            prev = *it;
        }
        return res;
    }
};
// @lc code=end

