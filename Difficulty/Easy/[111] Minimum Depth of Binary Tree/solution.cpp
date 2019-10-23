/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        int depth;
        q.push({root, 1});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            depth = q.front().second;
            if (!node->left && !node->right)
                return depth;
            if (node->left != nullptr)
                q.push({node->left, depth + 1});
            if (node->right != nullptr)
                q.push({node->right, depth + 1});     
            q.pop();
        }
        return depth;
    }
};
// @lc code=end

