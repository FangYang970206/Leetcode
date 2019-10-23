# 问题描述

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

```bash
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
```

# 方法

这题可以不断平分数组，通过递归来进行求解，对于排序的数组，二叉树的根节点在数组的中间，对于根节点的左孩子，它的位置在根节点数组的位置和开头位置中间，右孩子类似。依次类推便可求解。