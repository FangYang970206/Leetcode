# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        
        def maxPathSumHelper(root):
            nonlocal val
            if root is None: return 0
            left = maxPathSumHelper(root.left)
            right = maxPathSumHelper(root.right)
            lmr = root.val + left + right
            ret = root.val + max(0, max(right, left))
            val = max(val, max(ret, lmr))
            return ret
        val = -2 ** 31 - 1
        maxPathSumHelper(root)
        return val
        