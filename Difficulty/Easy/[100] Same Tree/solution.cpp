/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
#include <queue>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp, qq;
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        qp.push(p);
        qq.push(q);
        while(!qp.empty() && !qq.empty()) {
            p = qp.front();
            q = qq.front();
            if (p->val != q->val)
                return false;

            if (p->left != nullptr && q->left != nullptr){
                qp.push(p->left);
                qq.push(q->left);
            }else if (p->left == nullptr && q->left == nullptr){}
            else return false;

            if (p->right != nullptr && q->right != nullptr){
                qp.push(p->right);
                qq.push(q->right);
            }else if (p->right == nullptr && q->right == nullptr){}
            else return false;
            
            qp.pop();
            qq.pop();
        }
        return true;
    }
};
// @lc code=end

