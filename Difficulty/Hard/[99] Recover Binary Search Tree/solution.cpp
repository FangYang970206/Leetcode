/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
#include <stack>

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node1 = nullptr, *node2 = nullptr, *pre = nullptr;
        while (root != nullptr || !s.empty()) {
            while(root != nullptr){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (pre != nullptr && pre->val > root->val) {
                if (node1 == nullptr)
                    {node1 = pre; node2 = root;}
                else{
                     node2 = root; 
                     swap(node1->val, node2->val);
                     return;
                }
            }
            pre = root;
            root = root->right;
        }
        if (node1 != nullptr && node2 != nullptr)
            swap(node1->val, node2->val);
    }
};
// @lc code=end

