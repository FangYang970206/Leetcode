# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if root is None: return 0
        q_tree, q_val, res = deque(), deque(), 0
        q_tree.append(root)
        q_val.append(root.val)
        while q_tree:
            size = len(q_tree)
            for _ in range(size):
                cur, cur_val = q_tree.popleft(), q_val.popleft()
                if cur.left:
                    q_tree.append(cur.left)
                    q_val.append(cur.left.val + cur_val * 10)
                if cur.right:
                    q_tree.append(cur.right)
                    q_val.append(cur.right.val + cur_val * 10)
                if not cur.left and not cur.right:
                    res += cur_val
        return res
                
