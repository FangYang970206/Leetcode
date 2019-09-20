/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; ++i)
                nums1[i] = nums2[i];
            return;
        }
        if (nums2[0] > nums1[m-1]){
            for (int i = 0; i < n; ++i)
                nums1[m+i] = nums2[i];
        }
        if (nums2[n-1] < nums1[0]){
            for (int i = m - 1; i >= 0; --i)
                nums1[n + i] = nums1[i];
            for (int i = 0; i < n; ++i)
                nums1[i] = nums2[i];
            return;
        }
        int s1_i = m - 1, s2_i = n - 1, i = 1;
        while(s1_i >= 0 && s2_i >= 0){
            if (nums1[s1_i] > nums2[s2_i]){
                nums1[m + n - i] = nums1[s1_i];
                s1_i--;
            }else{
                nums1[m + n - i] = nums2[s2_i];
                s2_i--;
            }
            i++;
        }
        if (s1_i < 0){
            for (int j = 0; j <= s2_i; j++)
                nums1[j] = nums2[j];
        }
    }
};

