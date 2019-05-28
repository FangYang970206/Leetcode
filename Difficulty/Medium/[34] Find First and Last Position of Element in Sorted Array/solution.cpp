class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty() || target < *nums.begin() || target > *(--nums.end()))
            return res;
        int li = 0, mid = 0, hi = nums.size() - 1;
        while (li < hi){
            mid = (li + hi) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                li = mid + 1;
        }
        if (li == hi){
            if (nums[li] != target)
                return res;
            else{
                res[0] = li;
                res[1] = li;
                return res;
            }
        }else{
            li = mid;
            hi = mid;
            while (true){
                if (li == 0)
                    break;
                if (nums[li - 1] == nums[mid])
                    li -= 1;
                else
                    break;
            }
            while (true){
                if (hi == nums.size() - 1)
                    break;
                if (nums[hi + 1] == nums[mid])
                    hi += 1;
                else
                    break;
            }
            res[0] = li;
            res[1] = hi;
            return res;
        }
    }
};