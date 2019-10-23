# 问题描述

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

```bash
    3
   / \
  9  20
    /  \
   15   7
```

返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]
```bash
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

返回false。

# 方法

有两种方法：自底向上和自顶向下。https://leetcode.com/articles/balanced-binary-tree/ 有很好的动画示意图以及很好的解释。

我的方法是自顶向下，通过判断每个节点的左右孩子的深度来判断是否平衡，从顶往下。
这样做的复杂度是O(nlogn), 更好的做法是自底向上。

自底向上是检查子树是否平衡。如果是，则使用它们的高度来确定当前子树是否平衡，并计算当前子树的高度。而自顶向下是通过额外的递归函数（有logn的复杂度）来求取高度，从而判断是否平衡。

自底向上：
```python
class Solution:
    # Return whether or not the tree at root is balanced while also returning
    # the tree's height
    def isBalancedHelper(self, root: TreeNode) -> (bool, int):
        # An empty tree is balanced and has height -1
        if not root:
            return True, -1
        
        # Check subtrees to see if they are balanced. 
        leftIsBalanced, leftHeight = self.isBalancedHelper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced, rightHeight = self.isBalancedHelper(root.right)
        if not rightIsBalanced:
            return False, 0
        
        # If the subtrees are balanced, check if the current tree is balanced
        # using their height
        return (abs(leftHeight - rightHeight) < 2), 1 + max(leftHeight, rightHeight)
        
    def isBalanced(self, root: TreeNode) -> bool:
        return self.isBalancedHelper(root)[0]
```