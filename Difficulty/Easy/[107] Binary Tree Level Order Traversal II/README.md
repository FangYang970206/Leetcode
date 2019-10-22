# 问题描述

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

```bash
    3
   / \
  9  20
    /  \
   15   7
```

返回其自底向上的层次遍历为：

```bash
[
  [15,7],
  [9,20],
  [3]
]
```

# 方法

我采用的是deque加queue做法，queue用于二叉树的BFS，deque用于存储vector数据，因为deque左边push可以达到O(1).时间是8ms。

在讨论中发现更好的做法, 通过求解最大深度，直接从逆向填vector：
```c++
int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
}
```