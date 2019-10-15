/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
#include <queue>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        if (root->left == nullptr || root->right == nullptr) return false;
        queue<TreeNode*> dl, dr;
        TreeNode *l, *r;
        dl.push(root->left);
        dr.push(root->right);
        while (!dl.empty() && !dr.empty()) {
            l = dl.front();
            r = dr.front();
            if (l->val != r->val)
                return false;
            if (l->left != nullptr && r->right != nullptr) {
                dl.push(l->left);
                dr.push(r->right);
            }else if (l->left == nullptr && r->right == nullptr) {}
            else return false;
            if (l->right != nullptr && r->left != nullptr) {
                dl.push(l->right);
                dr.push(r->left);
            }else if (l->right == nullptr && r->left == nullptr) {}
            else return false;
            dl.pop();
            dr.pop();
        }
        return true;
    }
};
// @lc code=end

