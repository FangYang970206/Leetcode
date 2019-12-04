/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q_tree;
        queue<int> q_val;
        int sum = 0;
        q_tree.push(root);
        q_val.push(root->val);
        while (!q_tree.empty()) {
            int size = q_tree.size();
            while(size--) {
                TreeNode * cur = q_tree.front(); q_tree.pop();
                int cur_val = q_val.front(); q_val.pop();
                if (cur->left != nullptr) {
                    q_tree.push(cur->left);
                    q_val.push(cur->left->val + cur_val * 10);
                }
                if (cur->right != nullptr) {
                    q_tree.push(cur->right);
                    q_val.push(cur->right->val + cur_val * 10);
                }
                if (cur->left == nullptr && cur->right == nullptr)
                    sum += cur_val;
            }
        }
        return sum;
    }
};
// @lc code=end

