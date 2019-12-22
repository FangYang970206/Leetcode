# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        res, s = [], []
        s.append(root)
        while s:
            visit = s.pop()
            res.append(visit.val)
            if visit.right:
                s.append(visit.right)
            if visit.left:
                s.append(visit.left)
        return res