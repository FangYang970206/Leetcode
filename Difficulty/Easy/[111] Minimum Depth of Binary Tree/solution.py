# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None: return 0
        L, R = minDepth(root.left), minDepth(root.right)
        return 1 + (min(L, R) if min(L, R) else max(L, R))