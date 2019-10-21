/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < inorder.size(); ++i)
            hash_map[inorder[i]] = i;
        return buildTreeHelper(0, 0, inorder.size() - 1, preorder, inorder, hash_map);
    }

    TreeNode* buildTreeHelper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& hash_map) {
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = hash_map[root->val];
        root->left = buildTreeHelper(preStart + 1, inStart, index - 1, preorder, inorder, hash_map);
        root->right = buildTreeHelper(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder, hash_map);
        return root;
    }
};
// @lc code=end

