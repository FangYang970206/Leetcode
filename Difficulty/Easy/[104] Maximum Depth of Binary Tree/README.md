# 问题描述

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]

```bash
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度3。

# 方法

这里的方法有挺多种，最简洁的是递归：
```c++
return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
```
题目给出的函数的功能就是求出树的最大深度，那么可以等效为求左子树和右子树的最大深度加1.

另外，还可以通过DFS以及BFS进行求解，BFS简单，直接通过队列即可.不过DFS就需要记录深度了，笔者试过只用一个值记录当前深度，不可行，看答案要么是通过队列，要么就是通过pair。

DFS:
```c++
//maximum depth of a binary tree, non-recursive version, using Stack
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        int maxDepth = 0;
        stack<pair<TreeNode *, int>> S;
        S.push({root, 1});
        while (!S.empty()) {
            TreeNode *p = S.top().first;
            int curDepth = S.top().second;
            S.pop();
            maxDepth = max(curDepth, maxDepth);
            if (p->right != NULL) {
                S.push({p->right, curDepth + 1});
            }
            if (p->left != NULL) {
                S.push({p->left, curDepth + 1});
            }
        }
        return maxDepth;
    }
};
```

BFS:
```c++
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 1});
        int maxDepth = 0;
        while (!Q.empty()) {
            TreeNode * p = Q.front().first;
            int curDepth = Q.front().second;
            Q.pop();
            maxDepth = max(curDepth, maxDepth);
            if (p->left != NULL) {
                Q.push({p->left, curDepth + 1});
            }
            if (p->right != NULL) {
                Q.push({p->right, curDepth + 1});
            }
        }
        return maxDepth;
    }
};
```