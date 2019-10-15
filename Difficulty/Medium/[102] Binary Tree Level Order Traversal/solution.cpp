/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int size;
        q.push(root);
        while (!q.empty()) {
            size = q.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* ptr = q.front();
                if (ptr->left != nullptr) q.push(ptr->left);
                if (ptr->right != nullptr) q.push(ptr->right);
                tmp.push_back(ptr->val);
                q.pop();
                if (size == 0)
                    res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end

