/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSumHelper(root, val);
        return val;
    }

    int maxPathSumHelper(TreeNode* root, int& val){
        if (root == nullptr) return 0;
        int left = maxPathSumHelper(root->left, val);
        int right = maxPathSumHelper(root->right, val);
        int lmr = root->val + left + right;
        int ret = root->val + max(0, max(left, right));        
        val = max(val, max(ret, lmr));
        return ret;
    }
};
// @lc code=end

