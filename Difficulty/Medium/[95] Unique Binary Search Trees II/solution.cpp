/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? generateTreesHelper(1, n) : vector<TreeNode*>();
    }

    vector<TreeNode*> generateTreesHelper(int from, int to) {
        if (from > to)
            return vector<TreeNode*>(1, nullptr);
        vector<TreeNode*> allTrees;
        for (int i = from; i < to + 1; i++) {
            vector<TreeNode*> leftTrees = generateTreesHelper(from, i - 1);
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, to);
            for (int j = 0; j < leftTrees.size(); j++) {
                for (int k = 0; k < rightTrees.size(); k++) {
                    TreeNode* curNode = new TreeNode(i);
                    curNode->left = leftTrees[j];
                    curNode->right = rightTrees[k];
                    allTrees.push_back(curNode);
                }
            }
        }
        return allTrees;
    }
};

