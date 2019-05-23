class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int nums_size = nums.size();
        if (nums_size < 4) return res;
        sort(nums.begin(), nums.end());
        int hi = nums[nums_size - 1];
        map<int, int> num2id;
        int mapId = 0;
        for (auto& num : nums) {
            num2id[num] = mapId;
            mapId += 1;
        }
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        for (int i = 0; i < nums_size - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            a = nums[i];
            if (a * 4 > target) return res;
            if (a + 3 * hi < target) continue;
            for (int j = i + 1; j < nums_size - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                b = nums[j];
                if (a + b * 3 > target) break;
                if (a + b + 2 * hi < target) continue;
                for (int k = j + 1; k < nums_size - 1; k++){
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    c = nums[k];
                    if (a + b + c*2 > target) break;
                    if (a + b + c + hi < target) continue;
                    d = target - a - b - c;
                    auto search = num2id.find(d);
                    if (search != num2id.end()){
                        e = search->second;
                        if (e <= k) break;
                        else{
                            vector<int> temp{a, b, c, d};
                            res.push_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};