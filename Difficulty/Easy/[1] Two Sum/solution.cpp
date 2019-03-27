class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int index=0; index < nums.size(); index++){
            int res = target - nums[index];
            for(int i= index+1; i < nums.size(); i++)
            if(res==nums[i]){
                result.push_back(index);
                result.push_back(i);
                return result;
            }
            
        }
        
    }
};