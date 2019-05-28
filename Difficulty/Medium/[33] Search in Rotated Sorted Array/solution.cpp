/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        if (nums.size() == 2) {
            if (nums[0] != target) return nums[1] == target ? 1 : -1;
            if (nums[1] != target) return nums[0] == target ? 0 : -1;
        }
        int l = 0, m = 0, r = nums.size() - 1;
        if (nums[r] < nums[l]){
            while (l < r){
                m = (l + r) / 2;
                if (nums[m] == target) return m;
                if (m == 0){
                    if (nums[0] < nums[1]){
                        m = 1;
                        break;
                    }else break;
                }else{
                    if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
                        break;
                    else if (nums[m] > nums[nums.size() - 1])
                        l = m+1;
                    else
                        r = m-1;
                }
            }
            m = (l == r ? l : m);
            // cout << m << endl;
            if (target > nums[0]){
                vector<int> v(nums.begin(), nums.begin()+m+1);
                return binary_search(v, target);
            }
            else if (target < nums[0]){
                vector<int> v(nums.begin()+m+1, nums.end());
                int id = binary_search(v, target);
                return id == -1 ? -1 : m + 1 + id;
            }else
                return 0;
            return -1;
        }else
            return binary_search(nums, target);
    }
    
    int binary_search(vector<int>& nums, int target){
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while (l < r){
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            int m = (l + r) / 2;
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] == target)
                return m;
            else
                r = m - 1;
        }
        return -1;
    }
};

