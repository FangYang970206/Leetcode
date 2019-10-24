/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int>> res;
//         vector<int> tmp;
//         stack<pair<TreeNode*, int>> s;
//         s.push({root, root->val});
//         while (!s.empty()) {
//             root = s.top().first;
//             int sum_node = s.top().second;
//             tmp.push_back(root->val);
//             s.pop();
//             if (!root->left && !root->right) {
//                 if (sum_node == sum)
//                     res.push_back(tmp);
//                 tmp.pop_back();
//                 continue;
//             }
//             if (root->left)
//                 pathSum(root->left, sum-sum_node);
//             if (root->right)
//                 pathSum(root->right, sum-sum_node);
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        pathSumHelper(root, sum, res, tmp);
        return res;
    }

    void pathSumHelper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& tmp) {
        if (root == nullptr) return;
        tmp.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            res.push_back(tmp);
        pathSumHelper(root->left, sum-root->val, res, tmp);
        pathSumHelper(root->right, sum-root->val, res, tmp);
        tmp.pop_back();
    }
};
// @lc code=end

