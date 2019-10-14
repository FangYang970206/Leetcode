# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        s, node1, node2, pre = [], None, None, None
        while root != None or s:
            while root != None:
                s.append(root)
                root = root.left
            root = s.pop()
            if pre != None and pre.val > root.val:
                if node1 == None:
                    node1 = pre
                    node2 = root
                else:
                    node2 = root
            pre = root
            root = root.right
        if node1 is None and node2 is None:
            node1.val, node2.val = node2.val, node1.val