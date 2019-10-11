/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!root) {
            if (root->val == INT_MIN) {
                if (root->left != nullptr)
                    return false;
                else
                    root = root->right;
            }else if (root->val == INT_MAX) {
                if (root->right !=nullptr)
                    return false;
                else
                    root = root->left;
            }   
        }
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTHelper(TreeNode* n, long lower_bound, long upper_bound) {
        if (n == nullptr)
            return true;
        bool isValidLeft = false;
        bool isValidRight = false;
        if (n->val >= upper_bound || n->val <= lower_bound)
            return false;
        isValidLeft = isValidBSTHelper(n->left, lower_bound, n->val);
        isValidRight = isValidBSTHelper(n->right, n->val, upper_bound);
        return isValidLeft && isValidRight;
    }
};

