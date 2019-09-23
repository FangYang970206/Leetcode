/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <stack>

using namespace std;

// 递归方案
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalHelper(res, root);
        return res;
    }

    void inorderTraversalHelper(vector<int>& res, TreeNode* p) {
        if (p != nullptr) {
            inorderTraversalHelper(res, p->left);
            res.push_back(p->val);
            inorderTraversalHelper(res, p->right);
        }
    }    
};

//迭代方案
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur_node = root;
        while(cur_node != nullptr || !s.empty()){
            while (cur_node != nullptr) {
                s.push(cur_node);
                cur_node = cur_node->left;
            }
            cur_node = s.top();
            res.push_back(cur_node->val);
            cur_node = cur_node->right;
            s.pop();
        }
        return res;
    }
};

//莫里斯遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur != nullptr){
            if (cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right != nullptr)
                    pre = pre->right;
                pre->right = cur;
                TreeNode* tmp = cur;
                cur = cur->left;
                tmp->left = nullptr;
            }
        }
        return res;
    }
};