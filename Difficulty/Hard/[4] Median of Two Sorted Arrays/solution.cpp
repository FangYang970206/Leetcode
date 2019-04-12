class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())
            return getMiddleValue(nums2);
        if (nums2.empty())
            return getMiddleValue(nums1);
        int lens = nums1.size() + nums2.size();
        vector<int> res(lens);
        int num1 = nums1.back();
        nums1.pop_back();
        int num2 = nums2.back();
        nums2.pop_back();
        if (nums1.empty() && nums2.empty())
            return (num1 + num2)/2.0;
        while (!nums1.empty() && !nums2.empty()){
            if (num1 > num2){
                res[lens - 1] = num1;
                num1 = nums1.back();
                nums1.pop_back();
            }
            else{
                res[lens - 1] = num2;
                num2 = nums2.back();
                nums2.pop_back();
            }
            lens -= 1;
        }
        if (!nums1.empty())
            res = dealTheRest(res, nums1, num1, num2, lens);
        if (!nums2.empty())
            res = dealTheRest(res, nums2, num2, num1, lens);
        return getMiddleValue(res);
    }
    double getMiddleValue(vector<int>& nums){
        int nums_len = nums.size();
        if (nums_len % 2 == 0){
            int mid_idx = int(nums_len / 2);
            return (nums[mid_idx] + nums[mid_idx - 1])/2.0;   
        }
        else{
            return nums[(nums_len - 1) / 2]/1.0;
        }
    }
    vector<int> dealTheRest(vector<int>& res, vector<int>& nums, int& num1, int& num2, int& lens){
        while (num1 > num2 && !nums.empty()){
            res[lens - 1] = num1;
            num1 = nums.back();
            nums.pop_back();
            lens -= 1;
        }
        if (!nums.empty()){
            res[lens - 1] = num2;
            res[lens - 2] = num1;
            for (int i = 0; i < nums.size(); ++i)
                res[i] = nums[i];
        }
        else{
            if (num1 > num2){
                res[lens - 1] = num1;
                res[lens - 2] = num2;
            }
            else{
                res[lens - 1] = num2;
                res[lens - 2] = num1;
            }
        }
        return res;
    }
};