/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
private:
    stack<TreeNode*> s;
private:
    void pushAll(TreeNode* node) {
        for (; node; s.push(node), node = node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur_node = s.top();
        s.pop();
        pushAll(cur_node->right);
        return cur_node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

