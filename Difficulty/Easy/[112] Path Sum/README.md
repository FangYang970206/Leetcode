# 问题描述

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

```bash
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
```

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

# 方法

有多种方法，这里介绍两种，一种是基于递归求解的，将问题分为左右孩子的子问题，求根节点的sum相当于求左右子节点的sum减去根节点的val。第二种方法是基于DFS，记录每个节点的sum，当某个节点等于要求的和时，返回True。