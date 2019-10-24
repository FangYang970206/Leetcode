/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         stack<pair<TreeNode*,int>> s;
//         while (root != nullptr || !s.empty()) {
//             while (root != nullptr) {
//                 if (s.empty())
//                     s.push({root, sum-root->val});
//                 else{
//                     TreeNode* node = s.top();
//                     s.push({root, node->val - root->val});
//                 }
//                 if (s.top().second == 0 && s.top().first->left == nullptr && s.top().first->right == nullptr)
//                     return true;
//                 root = root->left;
//             }
//             root = s.top();
//             root = root->right;
//             s.pop();
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && root->val == sum) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while (!s.empty()) {
            int sum_node = s.top().second;
            root = s.top().first;
            s.pop();
            if (sum_node == sum && !root->left && !root->right)
                return true;
            if (root->left)
                s.push({root->left, sum_node + root->left->val});
            if (root->right)
                s.push({root->right, sum_node + root->right->val});
        }
        return false;
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while (!s.empty()) {
            int sum_node = s.top().second;
            root = s.top().first;
            s.pop();
            if (sum_node == sum && !root->left && !root->right)
                return true;
            if (root->left)
                s.push({root->left, sum_node + root->left->val});
            if (root->right)
                s.push({root->right, sum_node + root->right->val});
        }
        return false;
    }
};
// @lc code=end

