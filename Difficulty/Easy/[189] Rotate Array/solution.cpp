/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start

//TIME LIMITED ERROR
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            k = k % n;
        if (n < 2) return;
        for (int i = 0; i < k; i++) {
            int tmp = nums[n-1];
            for (int j = n - 2; j >= 0; j--){
                nums[j+1] = nums[j];
            }
            nums[0] = tmp;
        }
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            k = k % n;
        if (n < 2) return;
        vector<int> tmp(k, 0);
        for(int i = 0; i < k; i++)
            tmp[i] = nums[n - k + i];
        for(int i = n - k - 1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }
        for(int i = 0; i < k; i++){
            nums[i] = tmp[i];
        }
    }
};
// @lc code=end

