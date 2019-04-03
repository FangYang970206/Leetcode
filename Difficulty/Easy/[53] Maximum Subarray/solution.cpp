#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        if (*it < 0)
            return *it;
        int maxsofar = 0;
        int maxendinghere = 0;
        for (auto &num: nums){
            maxendinghere = max(maxendinghere + num, 0);
            maxsofar = max(maxsofar, maxendinghere);
        }
        return maxsofar;
    }
};