/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = nullptr;
        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root -> left;
            } else {
                TreeNode* node = todo.top();
                if (node -> right && node -> right != last) {
                    root = node -> right;
                } else {
                    nodes.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }
};
// @lc code=end

