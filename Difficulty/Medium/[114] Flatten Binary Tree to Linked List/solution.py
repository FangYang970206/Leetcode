# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        now = head
        while now:
            if now.left:
                pre = now.left
                while pre.right:
                    pre = pre.right
                pre.right = now.right
                now.right = now.left
                now.left = None
            now = now.right
                
            