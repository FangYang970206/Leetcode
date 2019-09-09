/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() <= 2) return nums.size();
        int count = 1, dup_ind = 0, size = nums.size();
        bool flag = false;
        for (int move_ind = 0; move_ind < size - 1; ++move_ind)
        {
            if (nums[move_ind] == nums[move_ind+1]){
                count++;
                if (flag && count <= 3 && move_ind > dup_ind)
                    nums[dup_ind++] = nums[move_ind];
            }
            else{
                if (count > 2){
                    if (!flag) {
                        dup_ind = move_ind - count + 3;
                        flag = true;
                    }
                }else{
                    if (flag && move_ind > dup_ind)
                        nums[dup_ind++] = nums[move_ind];
                }
                count = 1;
            }
        }
        if (count == nums.size())
            dup_ind = 2;
        else if (count > 2)
            dup_ind = flag ? dup_ind : size - count + 2;
        else{
            if (flag)
                nums[dup_ind++] = nums[size - 1];
            else
                dup_ind = size;
        }
        for (int i = 0; i < size - dup_ind; i++)
            nums.pop_back();
        return dup_ind;
    }
};

