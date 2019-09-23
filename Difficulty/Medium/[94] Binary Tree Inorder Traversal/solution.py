# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res, s, cur = [], [], root
        while cur != None or s:
            while cur != None:
                s.append(cur)
                cur = cur.left
            cur = s.pop()
            res.append(cur.val)
            cur = cur.right
        return res
            