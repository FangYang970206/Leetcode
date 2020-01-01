/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = ceil(double(u - l) / (nums.size() - 1));
        vector<int> bucketsMIN(nums.size() - 1, INT_MAX);
        vector<int> bucketsMAX(nums.size() - 1, INT_MIN);
        for (auto n : nums) {
            if (n == l || n == u)
                continue;
            int idx = (n - l) / gap;
            bucketsMIN[idx] = min(n, bucketsMIN[idx]);
            bucketsMAX[idx] = max(n, bucketsMAX[idx]);
        }
        int maxGap = INT_MIN;
        int pre = l;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (bucketsMIN[i] == INT_MAX && bucketsMAX[i] == INT_MIN)
                continue;
            maxGap = max(maxGap, bucketsMIN[i] - pre);
            pre = bucketsMAX[i];
        }
        return max(maxGap, u - pre);
    }
};
// @lc code=end

