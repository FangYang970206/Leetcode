/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        deque<vector<int>> d;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int size = q.size();
            while (size--) {
                tmp.push_back(q.front()->val);
                TreeNode* ptr = q.front();
                if (ptr->left != nullptr)
                    q.push(ptr->left);
                if (ptr->right != nullptr)
                    q.push(ptr->right);
                q.pop();
            }
            d.push_front(tmp);
        }
        return vector<vector<int>>(d.begin(), d.end());
    }
};
// @lc code=end

