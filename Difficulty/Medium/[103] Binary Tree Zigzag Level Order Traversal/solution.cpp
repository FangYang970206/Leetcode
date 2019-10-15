/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<TreeNode*> q;
        bool flapper = false;
        int size = 0;
        q.push_back(root); 
        while (!q.empty()) {
            size = q.size();
            vector<int> tmp;
            if (flapper) {
                while (size--) {
                    root = q.back();
                    tmp.push_back(root->val);
                    if (root->right != nullptr)
                        q.push_front(root->right);
                    if (root->left != nullptr)
                        q.push_front(root->left);
                    q.pop_back();
                    if (size == 0)
                        res.emplace_back(tmp);
                }
            }else {
                while (size--) {
                    root = q.front();
                    tmp.push_back(root->val);
                    if (root->left != nullptr)
                        q.push_back(root->left);
                    if (root->right != nullptr)
                        q.push_back(root->right);
                    q.pop_front();
                    if (size == 0)
                        res.emplace_back(tmp);
                }
            }
            flapper = (flapper == false ? true : false);
        }
        return res;
    }
};
// @lc code=end

