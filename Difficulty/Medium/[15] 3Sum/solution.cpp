// have bug, cause Running error, don't use it;
// have bug, cause Running error, don't use it;
// have bug, cause Running error, don't use it;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> nums_set;
        nums_set.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1])
                nums_set.push_back(nums[i]);
        }
        map<int, int> m;
        for (auto& num: nums_set)
            m[num] = 0;
        for (auto& num: nums)
            m[num] += 1;
        int short_len = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0){
                short_len = i;
                break;
            }
        }
        if (m.find(0) != m.end()){
            if (m[0] >= 3){
                vector<int> temp = {0, 0, 0};
                res.push_back(temp);
            }
        }
        int find_value = 0;
        for (int i = 0; i < short_len; i++){
            m[nums_set[i]] -= 1;
            for (int j = i; j < nums_set.size(); j++){
                m[nums_set[j]] -= 1;
                find_value = -nums_set[i] - nums_set[j];
                if (m.find(find_value) != m.end() && find_value > nums_set[i] && ((find_value > nums_set[j] && m[nums_set[j]] >= 0) || (find_value == nums_set[j] && m[nums_set[j]] > 0))){
                    vector<int> temp = {nums_set[i], nums_set[j], find_value};
                    res.push_back(temp);
                }
                m[nums_set[j]] += 1;
            }
        }
        return res;
    }
};