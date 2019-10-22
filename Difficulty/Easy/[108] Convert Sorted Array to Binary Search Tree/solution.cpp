/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int begin, int end) {
        if (end - begin < 1)
            return nullptr;
        TreeNode* root = new TreeNode(nums[(end + begin) / 2]);
        root->left = sortedArrayToBSTHelper(nums, begin, (begin + end) / 2);
        root->right = sortedArrayToBSTHelper(nums, (begin + end) / 2 + 1, end);
        return root;
    }
};
// @lc code=end

