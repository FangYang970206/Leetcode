/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < inorder.size(); ++i)
            hash_map[inorder[i]] = i;
        return buildTreeHelper(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder, hash_map);
    }

    TreeNode* buildTreeHelper(int postStart, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& hash_map) {
        if (postStart < 0 || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postStart]);
        int index = hash_map[root->val];
        root->left = buildTreeHelper(postStart - (inEnd - index) - 1, inStart, index - 1, inorder, postorder, hash_map);
        root->right = buildTreeHelper(postStart - 1, index + 1, inEnd, inorder, postorder, hash_map);
        return root;
    }
};
// @lc code=end

